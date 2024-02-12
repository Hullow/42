#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int					i;
	char				*buf;
	char				*end_of_line;
	static char			*line;
	
	buf = malloc(BUFFER_SIZE * sizeof(char)); // buffer which will be read into
	if (!buf)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);

	read(fd, buf, BUFFER_SIZE);
	i = 0;

	if ((end_of_line = ft_locatenewline(buf))) // if we find \n in the buffer string
	{
		printf("end of line is \"%s\"\n", end_of_line); //test
		line = ft_addstring(end_of_line, line); // add the buffer's contents from buf[0] to buf[i] to the "line" string
 		printf("We've hit end of line. the whole line is \"%s\"\n", line); // test
		return (line);
	}

	else // if we simply hit the end of the buffer, add its contents to the "line" string
	{
		printf("end of line is \"%s\"\n", end_of_line); ///test
		line = ft_addstring(buf, line);
 		printf("We've hit end of buffer. the line so far is \"%s\"\n", line); // test
		get_next_line(fd);
	}
	return (line);
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