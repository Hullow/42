#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buf;
	char		*end_of_line;
	char		*line = "";
	char		*temp = NULL;
	static char	*next_lines = "";
	static int	test_line_check = 0;
	int			end_reached = 0;
	
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	// if there is something left in our variable "next_lines", set temp to next_lines
	if (ft_strlen(next_lines))
	{
		if (test_line_check > 3) printf("ft_strlen(next_lines) is %zu, next_lines is \"%s\" and temp is \"%s\"\n", ft_strlen(next_lines), next_lines, temp);
		temp = next_lines;
		if (test_line_check > 3) printf("temp is now assigned to next_lines, i.e. to \"%s\"\n", temp);
	}
	else
	{
		temp = ft_fill_zero(buf, BUFFER_SIZE);
		read(fd, (temp = buf), BUFFER_SIZE);
		// if (test_line_check > 5) printf("temp has been read into again, and is now: \"%s\"\n", temp);
	}
	// this while() checks for '\n' using in temp (i.e. buf or next_lines) using ft_end_of_line.
	// If none, it adds temp's contents to our *line*, then reads more into temp
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp))
	{
		line = ft_add_string(temp, line);
		if (test_line_check > 4) printf("in the while loop, line has now been assigned to:\n\"%s\"\n\n", line);
		free(end_of_line);
 		if (test_line_check > 4) printf("   and temp is \"%s\"\n\n", temp);
		temp = ft_fill_zero(buf, BUFFER_SIZE); // implicit malloc, freed by free(buf) at the end of the function
		if (read(fd, (temp = buf), BUFFER_SIZE) < BUFFER_SIZE) end_reached = 1; // if read returns less than BUFFER_SIZE characters, it means it has reached end of file
		if (test_line_check > 4) printf("After ft_fill_zero and reading again, temp is \"%s\" at address %p\n*********************************************************\n", temp, temp);
	}
	// if (test_line_check > 5) printf("after our while(), buf is:\n\"%s\" at address %p\n\n", buf, buf);
	// if (test_line_check > 5) printf("temp is:\n\"%s\" at address %p\n\n", temp, temp);

	// if we find \n in buf or next_lines, add contents up to '\n' to line, and after '\n' to next_lines
	if ((end_of_line = ft_end_of_line(temp)))
	{
		if (test_line_check > 4) printf("We've hit end of line. temp is \"%s\" and end_of_line has been assigned to \"%s\"\n", temp, end_of_line);
		line = ft_add_string(end_of_line, line); // add the buffer's contents to the "line" string;
		// if (test_line_check > 5) printf("having added \"end of line\", line is:\n\"%s\"\n", line);
		next_lines = ft_next_lines(temp);
		// if (test_line_check > 5) printf("We've hit end of line. the whole line is \"%s\"\n", line); // test
 		free(end_of_line);
	}
	// if (test_line_check > 5) printf("\ntemp is:\n\"%s\"\n\n", temp);
	// if (test_line_check > 5) printf("Remaining lines are:
	// \"%s\"\n*********************************************************\n", next_lines); // test
	free(buf);
	// // if (test_line_check > 5) printf("\nafter our free(buf), buf is:\n\"%s\"\n", buf);
	test_line_check++;
	if (end_reached == 1) ft_fill_zero(next_lines, ft_strlen(next_lines));
	return (line);
}

int main(void)
{
	char path[] = "/Users/fallan/42/get_next_line/example.txt";
	int fd = open(path, O_RDONLY);
	// printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	printf("*********************************************************\n*********************************************************\n");
	printf("next line:%s\n", get_next_line(fd));
	close(fd);
	return (0);
}