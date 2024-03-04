/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/03/04 15:40:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd);
int				ft_read(int fd, char *buf, int read_ret);

char    *get_next_line(int fd)
{
	char            *buf;
	char            *temp;
	static char     *next_lines = NULL;
	static int      read_ret = BUFFER_SIZE;
	struct Result	result_struct;

	result_struct.line = NULL;
	temp = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (ft_strlen(next_lines))
		buf = next_lines;
	else if (read_ret == BUFFER_SIZE)
		read_ret = ft_read(fd, buf, read_ret);
	else
		return (result_struct.line);
	result_struct = ft_fill_line(buf, result_struct.line, read_ret, fd);
	read_ret = result_struct.read_ret;
	buf = result_struct.buf;
	if (ft_locate_end_of_line(buf))
	{
		if (result_struct.line)
			temp = result_struct.line;
		result_struct.line = ft_add_string(buf, ft_locate_end_of_line(buf), result_struct.line);
		if (temp)
			free(temp);
	}
	next_lines = ft_next_lines(result_struct.buf);
	return (result_struct.line);
}

// fills the line with characters from the buffer if the buffer doesn't contain a newline character
// then, reads again into the buffer, and repeats the operations if no newline
// returns the line, buffer, and last read return value
struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd)
{
	struct Result	result_struct;
	char			*temp;

	temp = NULL;
	while (ft_locate_end_of_line(buf) == 0 && ft_strlen(buf))
	{
		if (line) // if 
			temp = line;
		line = ft_add_string(buf, ft_strlen(buf), line);
		if (temp)
			free(temp);
		temp = NULL;
		buf = ft_fill_char(buf, ft_strlen(buf), '\0');
		read_ret = ft_read(fd, buf, read_ret);
	}
	result_struct.read_ret = read_ret;
	result_struct.line = line;
	result_struct.buf = buf;
	// NEED: read() error handling: e.g. if (read_ret == -1)
	return (result_struct);
}

// NEED: read() error handling
int	ft_read(int fd, char *buf, int read_ret)
{
	if (read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
	}
	return (read_ret);
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

/* 
int main()
{
	char	*ret_value;

	char *path_to_example_text = "/Users/fallan/42/get_next_line/examples/example.txt";

	int fd = open(path_to_example_text, O_RDONLY);

	fd = open(path_to_example_text, O_RDONLY);
	
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

	// if (ret_value)
	// {
	// 	free(ret_value);
	// 	ret_value = NULL;
	// }

	close(fd);
	// free(buf);
	return (0);
}

 */