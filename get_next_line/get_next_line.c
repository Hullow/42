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
	
	printf("in the beginning of the function, next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
	printf("\nin the beginning of the function, temp at address %p is \"%s\"\n\n", temp, temp);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	
	if (ft_strlen(next_lines))
		temp = next_lines;
	else
		read(fd, (temp = buf), BUFFER_SIZE);
	printf("after our if-else, temp at address %p is \"%s\"\n\n", temp, temp);
	printf("before our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
	// if no '\n' in temp, adds all of temp to line, then reads more into temp
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp))
	{
		line = ft_add_string(temp, line); // adds our whole string temp to line
		printf("while loop: temp is \"%s\"\n and line is \"%s\"\n", temp, line);
		printf("while loop - temp address before ft_fill_zero: %p\n", temp);
		temp = ft_fill_zero(temp, ft_strlen(temp)); // sets our string temp to the address of buf filled with zeroes
		printf("while loop - temp address after ft_fill_zero: %p\n", temp);
		read(fd, (temp = buf), BUFFER_SIZE);
	}
	ft_fill_zero(end_of_line, ft_strlen(end_of_line));
	free(end_of_line);
	printf("after our while(), end_of_line at address %p is \"%s\"\n", end_of_line, end_of_line);
	printf("after our while(), temp at address %p is \"%s\"\n\n", temp, temp);
	printf("after our while(), next_lines at address %p is \"%s\"\n\n", next_lines, next_lines);
	// if we can locate a '\n' in temp
	if ((end_of_line = ft_end_of_line(temp)))
	{
		line = ft_add_string(end_of_line, line); // add end_of_line (defined from temp) to line
		printf("in the if, next_lines before redefinition at address %p is \"%s\"\n\n", next_lines, next_lines);
		next_lines = ft_next_lines(temp); // redefine next_lines to 
		printf("in the if, next_lines after redefinition at address %p is \"%s\"\n", next_lines, next_lines);
 		free(end_of_line);
	}
	free(buf);
	// if (end_reached == 1) printf("end_reached == %d\n", end_reached);// ft_fill_zero(next_lines, ft_strlen(next_lines));
	// printf("end_reached == %d\n", end_reached);
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

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	// ret_value = get_next_line(fd);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nnext line:\n*********************\"%s\"", ret_value);

	close(fd);
	return (0);
}