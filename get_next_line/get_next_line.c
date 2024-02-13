#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buf;
	char		*end_of_line;
	char		*line = "";
	char		*temp;
	static char	*next_lines = "";
	
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	// printf("ft_strlen(next_lines) is %zu\n", ft_strlen(next_lines));
	if (ft_strlen(next_lines))
		temp = next_lines;
	else
		read(fd, (temp = buf), BUFFER_SIZE);
	// printf("buf is:\n\"%s\"\n\n", buf);
	// printf("temp is:\n\"%s\"\n\n", temp);
	while ((end_of_line = ft_end_of_line(temp)) == 0) // if no '\n' in buf or next_lines, add contents to line and read further
	{
		line = ft_add_string(temp, line);
		// printf("in the while loop, line is:\n\"%s\"\n\n", line);
		free(end_of_line);
 		// printf("We've hit end of buffer. the line so far is \"%s\"\n\n", line); // test
		read(fd, (temp = buf), BUFFER_SIZE);
	}
	// printf("after our first while, buf is:\n\"%s\"\n\n", buf);
	// printf("temp is:\n\"%s\"\n\n", temp);
	// if we find \n in buf or next_lines, add contents up to '\n' to line, and after '\n' to next_lines
	if ((end_of_line = ft_end_of_line(temp)))
	{
		line = ft_add_string(end_of_line, line); // add the buffer's contents to the "line" string;
		// printf("having added \"end of line\", line is:\n\"%s\"\n", line);
		next_lines = ft_next_lines(temp);
		// printf("We've hit end of line. the whole line is \"%s\"\n", line); // test
		// printf("\ntemp is:\n\"%s\"\n\n", temp);
		// printf("Remaining lines are: \"%s\"\n", next_lines); // test
 		free(end_of_line);
	}
	free(buf);
	return (line);
}

int main(void)
{
	char path[] = "/Users/fallan/42/get_next_line/example.txt";
	int fd = open(path, O_RDONLY);
	printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	// printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	// printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	// printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	// printf("\n\nget_next_line returns:\n**********************\n%s**********************\n", get_next_line(fd));
	close(fd);
	return (0);
}