#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char	*buf;
	char	*end_of_line;
	char	*line = "";
	
	buf = malloc(BUFFER_SIZE * sizeof(char)); // buffer which will be read into
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);

	while ((end_of_line = ft_locatenewline(buf)) == 0)
	{
		// printf("end of line is \"%s\"\n\n", end_of_line); ///test
		line = ft_addstring(buf, line);
 		printf("We've hit end of buffer. the line so far is \"%s\"\n\n", line); // test
		read(fd, buf, BUFFER_SIZE);
	}
	if ((end_of_line = ft_locatenewline(buf))) // if we find \n in the buffer string
	{
		// printf("end of line is \"%s\"\n", end_of_line); //test
		line = ft_addstring(end_of_line, line); // add the buffer's contents to the "line" string
 		printf("We've hit end of line. the whole line is \"%s\"\n", line); // test
	}
	return (line);
}

int main(void)
{
	char path[] = "/Users/fallan/42/get_next_line/example.txt";
	int fd = open(path, O_RDONLY);
	printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	close(fd);
	return (0);
}