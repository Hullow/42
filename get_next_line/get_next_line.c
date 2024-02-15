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
	// printf("next_lines:\n\"%s\"\n\n", next_lines);

	// if there is something left in our variable "next_lines", set temp to next_lines
	if (ft_strlen(next_lines))
		temp = next_lines;
	else
		read(fd, (temp = buf), BUFFER_SIZE);
	// printf("temp is:\n\"%s\"\n\n", temp);
	// printf("buf is:\n\"%s\"\n\n", buf);
	// if ((end_of_line = ft_end_of_line(temp)) == 0) // test
		// printf("\"((end_of_line = ft_end_of_line(temp)) == 0)\" is true\n");
	// else
		// printf("\"((end_of_line = ft_end_of_line(temp)) == 0)\" is false\n");
	
	// this while() checks for '\n' using ft_end_of_line. If none, it adds temp's contents to our *line*, then reads
	// more into temp
	// if no '\n' in buf or next_lines, add contents to line and read further.
	// Problem: infinite loop. Why ? 
	// Take our example: 
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp)) // if no '\n' in buf or next_lines, add contents to line and read further
	{
		line = ft_add_string(temp, line);
		// printf("in the while loop, line is:\n\"%s\"\n\n", line);
		free(end_of_line);
 		// printf("We've hit end of buffer. the line so far is \"%s\"\n\n", line); // test
		// printf("   and temp is \"%s\"\n\n", temp);
		temp = ft_fill_zero(buf, BUFFER_SIZE); // implicit malloc, freed by free(buf) at the end of the function
		// printf("   and temp is \"%s\" at address %p\n\n", temp, temp);
		// printf("   and buf is \"%s\" at address %p\n\n", buf, buf);
		read(fd, (temp = buf), BUFFER_SIZE);
		// printf("   and temp is \"%s\" at address %p\n\n", temp, temp);
		// printf("   and buf is \"%s\" at address %p\n\n", buf, buf);
	}
	// printf("after our while(), buf is:\n\"%s\"\n\n", buf);
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
	// printf("\nafter our free(buf), buf is:\n\"%s\"\n", buf);
	return (line);
}

int main(void)
{
	char path[] = "/Users/fallan/42/get_next_line/example.txt";
	int fd = open(path, O_RDONLY);
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	printf("next line:%s\n", get_next_line(fd));
	close(fd);
	return (0);
}