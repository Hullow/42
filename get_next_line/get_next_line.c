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
	static int	read_ret = 1; // return value of read
																						 										 										 // printf("in the beginning of the function, next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
																						 										 										 // printf("\nin the beginning of the function, temp at address %p is \"%s\"\n\n", temp, temp);
	buf = malloc(BUFFER_SIZE * sizeof(char)); // allocate memory to store the contents of our buffer
	if (!buf)
		return (NULL);
	
	// check if there were lines previously read by the function but not returned. if yes, point our temp string to those lines
	if (ft_strlen(next_lines))
		temp = next_lines;

	// if no lines in memory, read BUFFER_SIZE bytes from the file descriptor, into our buffer buf, and set the temp string to buf
	else if (read_ret)
	{
		read_ret = read(fd, (temp = buf), BUFFER_SIZE);
		printf("first read: read_ret is %d\n", read_ret);
	}
																																										// printf("after our if-else, temp at address %p is \"%s\"\n\n", temp, temp);
																																										// printf("before our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
	// check if there is an '\n' in temp with ft_end_of_line and assign the return value to end_of_line (without this assignation, it seg faults)
	// do this while temp contains something (ft_strlen)
	// if no '\n' (== 0), enter the loop
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp)) // read_ret: if we've got no \n in temp, either buffer or next_lines, we can add to line
	{
		line = ft_add_string(temp, line); // add our whole string temp to line (because temp contains something but no '\n')
																																										// printf("while loop: temp is \"%s\"\n and line is \"%s\"\n", temp, line);
																																										// printf("while loop - temp address before ft_fill_zero: %p\n", temp);
		temp = ft_fill_zero(temp, ft_strlen(temp)); // fills temp (which points to buf or next_lines) with zeros => is this really needed ?
		buf = ft_fill_zero(buf, ft_strlen(buf));
		if (trigger > 5)
			printf("\n__________________________________________________________________________\n^^^^^^^^^^^^^^^^Trigger hit: We are close to the last line^^^^^^^^^^^^^^^^\n__________________________________________________________________________\n");

		printf("in the while before read(): read_ret is %d\n", read_ret);
																																										// printf("while loop - temp address after ft_fill_zero: %p\n", temp);
		if (read_ret < BUFFER_SIZE)
			read_ret = read(fd, (temp = buf), BUFFER_SIZE); // sets temp to buf and reads more into buf/temp 
		
		printf("in the while after read(): read_ret is %d\n", read_ret);
		if (!read_ret)
			printf("We've hit EOF and temp == buf is %s\n", temp);
	}
																																										// printf("after our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
																																										// printf("after our while(), next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
																																										// printf("after our while(), temp at address %p is \"%s\"\n\n", temp, temp);
	// if we locate a '\n' in temp or if temp is non empty and we've hit end of file
	if ((end_of_line = ft_end_of_line(temp)) || (ft_strlen(temp) && !read_ret)) 
	{
		line = ft_add_string(end_of_line, line); // add the characters up to '\n' (== end_of_line string) to line
																																										// printf("in the if, temp at address %p is \"%s\"\n\n", temp, temp);;
																																										// printf("in the if, next_lines before redefinition at address %p is \"%s\"\n\n", next_lines, next_lines);
		next_lines = ft_next_lines(temp); // redefine next_lines to 
																																										// printf("in the if, next_lines after redefinition at address %p is \"%s\"\n", next_lines, next_lines);
		free(end_of_line);
	}
	free(buf);
																			 										 										 // printf("read_ret == %d\n", read_ret);
								 											 										 										 // printf("\n*********next_lines:\"%s\"*********\n", next_lines);
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