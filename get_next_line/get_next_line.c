#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int					i;
	char				*buf;
	static t_list		*head; // it also works if it's not static
	
	buf = malloc(BUFFER_SIZE * sizeof(char));
	// char *ret = malloc((element_count * BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buf, BUFFER_SIZE);
	i = 0;
	while (buf[i] && buf[i] != 10) // check if there is a \n in the buffer
		i++;
	if (buf[i] == 10) // if yes, create a new string end_of_line, and add it to the linked list
	{
		printf("We've hit end of line. index of buffer is %d\n", i);
		char	*end_of_line = malloc((i+1) * sizeof(char));
		ft_strlcpy(end_of_line, buf, i+1);
		free (buf);
		end_of_line[i] = '\0';
		t_list	*new_element = ft_lstnew(end_of_line);
		free (end_of_line);
		ft_lstadd_back(&head, new_element);
		t_list	*last_element = ft_lstlast(head); //test
		char *ret = last_element->content; //test
 		printf("last_element->content is \"%s\"\n", ret); // test
		return (ret);
	}
	else // if no, create a new element in the linked list and add the buffer's contents to it 
	{
		printf("We've hit end of buffer. index of buffer is %d\n", i);
		t_list	*new_element = ft_lstnew(buf);
		ft_lstadd_back(&head, new_element);
		printf("new_element->content is \"%s\"\n\n", new_element->content); // test
		free (buf);
		get_next_line(fd);
	}
	return (ft_list_to_string(head));
}

int main(void)
{
	char path[] = "example.txt";
	int fd = open(path, O_RDONLY);
	char *line = get_next_line(fd);
	printf("\n\nget_next_line returns:\n**********************\n%s\n", line);
	close(fd);
	return (0);
}