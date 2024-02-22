#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buf;
	char		*temp = NULL;
	char		*end_of_line = NULL;
	char		*line = NULL;
	static char	*next_lines = "";
	static int	read_ret = BUFFER_SIZE;
	
	buf = malloc(BUFFER_SIZE * sizeof(char)); // allocate memory for the buffer
	if (!buf)
		return (NULL);
	// we want the function to first check if there were next lines to output
	// else, we want the function to read, unless the EOF was reached (read_ret < BUFFER_SIZE)

	// if there were lines previously read by the function but not returned, point the temp string to those lines
	if (ft_strlen(next_lines))
		temp = next_lines;

	// if no lines previously read to return, read BUFFER_SIZE bytes from the file descriptor, into the buffer buf, and set the temp string to buf
	else if (read_ret == BUFFER_SIZE) // if read_ret has not reached the end of file, i.e. previously read a full buffer (read_ret < BUFFER_SIZE) 
		read_ret = read(fd, (temp = buf), BUFFER_SIZE);
	// when we've arrived at the end 
	else
		return(line);
	// check if there is an '\n' in temp with ft_end_of_line and assign the return value to end_of_line (without this assignation, it seg faults)
	// do this while temp contains something (ft_strlen)
	// if no '\n' (== 0), enter the loop
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp)) // read_ret: if we've got no \n in temp, either buffer or next_lines, we can add to line
	{
		line = ft_add_string(temp, line); // add our whole string temp to line (because temp contains something but no '\n')
		temp = ft_fill_zero(temp, ft_strlen(temp)); // fills temp (which points to buf or next_lines) with zeros => is this really needed ?
		buf = ft_fill_zero(buf, ft_strlen(buf));
		if (read_ret == BUFFER_SIZE) // same condition as above
			read_ret = read(fd, (temp = buf), BUFFER_SIZE); // sets temp to buf and reads more into buf/temp 
	}
	// if there is '\n' in temp (end_of_line) or if we've hit end of file and temp is non empty 
	if ((end_of_line = ft_end_of_line(temp)) || ((read_ret < BUFFER_SIZE) && (ft_strlen(temp))))
	{
		line = ft_add_string(end_of_line, line); // add the characters up to '\n' (== end_of_line string) to line
		next_lines = ft_next_lines(temp); // redefine next_lines to
		free(end_of_line);
	}
	free(buf);
	return (line);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
}

int main() // int argc, char *argv[])
{
	char	*ret_value;

	// ret_value = get_next_line(0);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nline from stdin:\"%s\"\n\n", ret_value);

	char *buf;
	buf = malloc(BUFFER_SIZE * sizeof(char)); // allocate memory for the buffer
	if (!buf)
		return (0);

	char *path_to_example_text = "/Users/fallan/42/get_next_line/examples/example.txt";

	int fd = open(path_to_example_text, O_RDONLY);

	read(fd, buf, BUFFER_SIZE);
	close(fd);
	printf("Our example file is:\n\n");
	ft_putstr_fd(buf, 1);
	printf("\n\nNow let's check out if our get_next_line works on it:\n***********************\n");
	
	fd = open(path_to_example_text, O_RDONLY);
	printf("fd is %d\n", fd);
	ret_value = NULL;

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	close(fd);
	free(buf);
	return (0);
}

