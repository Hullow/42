#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buf;
	char		*temp = NULL;
	char		*end_of_line = NULL;
	char		*line = "";
	static char	*next_lines = "";
	static int	trigger = 0;
	static int	read_ret = BUFFER_SIZE; // return value of read
																						 										 										 // // printf("in the beginning of the function, next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
																						 										 										 // // printf("\nin the beginning of the function, temp at address %p is \"%s\"\n\n", temp, temp);
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
	{
		read_ret = read(fd, (temp = buf), BUFFER_SIZE);
		// printf("first read: read_ret is %d\n", read_ret);
	}
	// when we've arrived at the end 
	else
		return(line);
																																										// // printf("after our if-else, temp at address %p is \"%s\"\n\n", temp, temp);
																																										// // printf("before our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
	// check if there is an '\n' in temp with ft_end_of_line and assign the return value to end_of_line (without this assignation, it seg faults)
	// do this while temp contains something (ft_strlen)
	// if no '\n' (== 0), enter the loop
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp)) // read_ret: if we've got no \n in temp, either buffer or next_lines, we can add to line
	{
		line = ft_add_string(temp, line); // add our whole string temp to line (because temp contains something but no '\n')
																																										// // printf("while loop: temp is \"%s\"\n and line is \"%s\"\n", temp, line);
																																										// // printf("while loop - temp address before ft_fill_zero: %p\n", temp);
		temp = ft_fill_zero(temp, ft_strlen(temp)); // fills temp (which points to buf or next_lines) with zeros => is this really needed ?
		buf = ft_fill_zero(buf, ft_strlen(buf));
																																										// // printf("while loop - temp address after ft_fill_zero: %p\n", temp);
		if (read_ret == BUFFER_SIZE) // same condition as above
			read_ret = read(fd, (temp = buf), BUFFER_SIZE); // sets temp to buf and reads more into buf/temp 
	}
																																										// // printf("after our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
																																										// // printf("after our while(), next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
																																										// // printf("after our while(), temp at address %p is \"%s\"\n\n", temp, temp);
	// if there is '\n' in temp (end_of_line) or if we've hit end of file and temp is non empty 
	if ((end_of_line = ft_end_of_line(temp)) || ((read_ret < BUFFER_SIZE) && (ft_strlen(temp))))
	{
		line = ft_add_string(end_of_line, line); // add the characters up to '\n' (== end_of_line string) to line
																																										// // printf("in the if, temp at address %p is \"%s\"\n\n", temp, temp);;
																																										// // printf("in the if, next_lines before redefinition at address %p is \"%s\"\n\n", next_lines, next_lines);
		next_lines = ft_next_lines(temp); // redefine next_lines to 
																																										// // printf("in the if, next_lines after redefinition at address %p is \"%s\"\n", next_lines, next_lines);
		free(end_of_line);
	}
	free(buf);
																			 										 										 // // printf("read_ret == %d\n", read_ret);
								 											 										 										 // // printf("\n*********next_lines:\"%s\"*********\n", next_lines);
	trigger++;
	return (line);
}

int main(void)
{
	char path[] = "/Users/fallan/42/get_next_line/example.txt";
	int fd = open(path, O_RDONLY);
	char *ret_value;

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("get_next_line returned NULL");
	else printf("\nnext line:\n*********************\"%s\"", ret_value);

	close(fd);
	return (0);
}