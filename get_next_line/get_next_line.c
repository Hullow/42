/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/03/01 17:30:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

// ft_fill_line: examines our buffer and adds its content to line
// takes as input the buffer, the line to modify, and the return value of read (read_ret)
// returns the read_ret value so that GNL can further evaluate if we've reached EOF of need to read() more
// the end_of_line string contains all of the buffer up to the first '\n', or nothing if no '\n' is found
int	ft_read(int fd, int read_ret, char *buf)
{
	if (read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
	}
	return (read_ret);
}

struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd)
{
	struct Result	result_struct;

	while (ft_locate_end_of_line(buf) == 0 && ft_strlen(buf))
	{
		line = ft_add_string(buf, ft_locate_end_of_line(buf), line);
		buf = ft_fill_char(buf, ft_strlen(buf), '\0'); // could cause issues if buf == next_lines ?
		read_ret = ft_read(fd, read_ret, buf);
	}
	result_struct.read_ret = read_ret;
	result_struct.line = line;
	result_struct.buf = buf;
	return (result_struct);
}

char    *get_next_line(int fd)
{
	char            *buf;
	char            *line;
	static char     *next_lines = "";
	static int      read_ret = BUFFER_SIZE;
	struct Result	result_struct;

	line = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (ft_strlen(next_lines))
		buf = next_lines;
	else if (read_ret == BUFFER_SIZE)
		read_ret = ft_read(fd, read_ret, buf); // make this into a function with read() error handling
	else
		return (line);
	result_struct = ft_fill_line(buf, line, read_ret, fd);
	line = result_struct.line;
	buf = result_struct.buf;
	read_ret = result_struct.read_ret;
	if (ft_locate_end_of_line(buf)) // necessary ?
		line = ft_add_string(buf, ft_locate_end_of_line(buf), line);
	next_lines = ft_next_lines(buf);
	// free(buf);
	return (line);
}

// adapted for str == NULL && non-null terminated strings (length < BUFFER_SIZE)
size_t	ft_strlen(char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	if (str)
	{
		while (str[length] != 0)
			length++;
	}
	return (length);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
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



int main()
{
	char	*ret_value;

	// ret_value = get_next_line(0);
	// if (ret_value == NULL) printf("get_next_line returned NULL");
	// else printf("\nline from stdin:\"%s\"\n\n", ret_value);

	// char *buf;
	// buf = malloc(10000 * sizeof(char)); // allocate memory for the buffer
	// if (!buf)
	// 	return (0);
	// sleep(5);

	char *path_to_example_text = "/Users/fallan/42/get_next_line/examples/example.txt";

	int fd = open(path_to_example_text, O_RDONLY);

	// read(fd, buf, 10000);
	// close(fd);
	// printf("Our example file is:\n\n");
	// ft_putstr_fd(buf, 1);
	// printf("**************************\n\nNow let's check out if our get_next_line works on it:\n***********************\n");

	// buf = malloc(BUFFER_SIZE * sizeof(char)); // allocate memory for the buffer
	// if (!buf)
	// 	return (0);

	fd = open(path_to_example_text, O_RDONLY);
	// printf("fd is %d\n", fd);
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
	// free(buf);
	return (0);
}

