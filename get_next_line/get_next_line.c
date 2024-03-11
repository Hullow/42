/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/03/11 17:38:35 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char    *get_next_line(int fd)
{
	char            *buf = NULL;
	char            *temp;
	char            *tempbuf;
	static char     next_lines[BUFFER_SIZE];
	static int      read_ret = BUFFER_SIZE - 1;
	struct Result	result_struct;

	result_struct.line = NULL;
	temp = NULL;
	buf = malloc((BUFFER_SIZE) * sizeof(char));
	if (!buf)
		return (NULL);
	tempbuf = buf;
	if (ft_strlen(next_lines))
		buf = next_lines;
	else if (read_ret == BUFFER_SIZE - 1)
		read_ret = ft_read(fd, buf, read_ret);
	else
		return (result_struct.line);
	result_struct = ft_fill_line(buf, result_struct.line, read_ret, fd);
	read_ret = result_struct.read_ret;
	if (ft_locate_end_of_line(result_struct.buf))
	{
		// if (result_struct.line)
		// 	temp = result_struct.line;
		result_struct.line = ft_add_string(result_struct.buf, ft_locate_end_of_line(result_struct.buf), result_struct.line);
	}
	if (temp)
		free(temp);
	// printf("before ft_next_lines: next_lines is {%s}\n", next_lines);
	ft_next_lines(next_lines, buf);
	// printf("after ft_next_lines: next_lines is {%s}\n", next_lines);
	if(tempbuf)
		free(tempbuf);
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
		// printf("\nft_fill_line:\n");
		if (line)
		{
			temp = line;
			// printf("\tbefore ft_add_string: line is {%s} at address {%p} -- temp is {%s} at address {%p}\n", line, line, temp, temp);
		}
		line = ft_add_string(buf, ft_strlen(buf), line);
		if (temp) // there isn't necessarily a malloc. e.g. 
		{
			// printf("\tafter ft_add_string: line is {%s} at address {%p} -- temp is {%s} at address {%p}\n", line, line, temp, temp);
			free(temp);
		}
		// printf("\tafter free:temp address {%p}, and line: {%s}\n", temp, line);
		temp = NULL;
		buf = ft_fill_char(buf, '\0');
		read_ret = ft_read(fd, buf, read_ret);
		// printf("buf is: {%s}\n", buf);
	}
	result_struct.read_ret = read_ret;
	result_struct.line = line;
	result_struct.buf = buf;
	// NEED: read() error handling: e.g. if (read_ret == -1)
	return (result_struct);
}

/* ft_strjoin adaptation */
char	*ft_add_string(char *addition, unsigned int addition_count, char *base)
{
	char			*output;
	unsigned int	i;
	unsigned int	base_length;

	base_length = ft_strlen(base);
	output = malloc((base_length + addition_count + 2) * sizeof(char));
	if (!output)
		return (NULL);
	else
	{
		i = 0;
		while (i++ < base_length)
			output[i - 1] = base[i - 1];
		i = 0;
		while (++i <= addition_count)
			output[base_length + i - 1] = addition[i - 1];
		output[base_length + i - 1] = '\0';
	}
	return (output);
}

/* Only reads if read_ret == BUFFER_SIZE - 1, meaning we are not at the end of the fd */
// NEED: read() error handling
int	ft_read(int fd, char *buf, int read_ret)
{
	if (read_ret == BUFFER_SIZE - 1)
	{
		read_ret = read(fd, buf, BUFFER_SIZE - 1);
		buf[read_ret] = '\0';
	}
	return (read_ret);
}

/* looks at #BUFFER_SIZE - 1 characters in a string: 
	- if those characters contain an '\n', 
	returns the index of '\n' + 1 (in case '\n' is at index 0)
	- otherwise, returns 0 */
unsigned int	ft_locate_end_of_line(char *buf)
{
	unsigned int	i;

	i = 0;
	while (i < (BUFFER_SIZE - 1) && buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	else
		return (0);
}


int main()
{
	char	*ret_value;

	char *path_to_example_text = "/Users/francis/42/get_next_line/examples/example.txt";

	int fd = open(path_to_example_text, O_RDONLY);

	fd = open(path_to_example_text, O_RDONLY);
	
	ret_value = NULL;

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	ret_value = get_next_line(fd);
	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
	else printf("\nnext line:\"%s\"", ret_value);

	if (ret_value)
	{
		free(ret_value);
		ret_value = NULL;
	}

	close(fd);
	return (0);
}
