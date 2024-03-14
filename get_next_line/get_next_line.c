/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/03/14 18:28:15 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char			*buf;
	char			*temp;
	static char		next_lines[BUFFER_SIZE];
	static int		read_ret = BUFFER_SIZE;
	struct Result	res;

	if (fd == -1)
		return (NULL);
	res.line = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (!ft_strlen(next_lines))
		read_ret = ft_read(fd, buf, read_ret);
	else
		ft_strlcpy(buf, next_lines, BUFFER_SIZE + 1);
	res = ft_fill_line(buf, res.line, read_ret, fd);
	read_ret = res.read_ret;
	temp = res.line;
	if (ft_end_of_line(res.buf))
	{
		temp = NULL;
		res.line = ft_add_string(res.buf, ft_end_of_line(res.buf), res.line);
	}
	ft_next_lines(next_lines, buf);
	// printf("get_next_line(int fd): res.line is {%s} at address {%p}\n", res.line, res.line);
	free(buf);
	if (temp)
		free(temp);
	if (read_ret == -1)
		return (NULL);
	return (res.line);
}

/* fills the line with characters from the buffer if the buffer 
doesn't contain a newline character then, reads again into the buffer
, and repeats the operations if no newline 
returns the line, buffer, and last read return value */
struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd)
{
	struct Result	res;

	if (read_ret > 0)
	{
		while (ft_end_of_line(buf) == 0 && ft_strlen(buf))
		{
			line = ft_add_string(buf, ft_strlen(buf), line);
			read_ret = ft_read(fd, buf, read_ret);
			if (read_ret == -1)
				break;
		}
	}
	res.read_ret = read_ret;
	res.line = line;
	res.buf = buf;
	return (res);
}

/* ft_strjoin adaptation 
* allocates enough space for our two strings and concatenates them in the new string
* free() is done either in our ft_fill_line while() loop, or in the main if this is 
* the last ft_add_string call by the get_next_line function
*
*/
char	*ft_add_string(char *addition, unsigned int addition_count, char *base)
{
	char			*output;
	char			*temp;
	unsigned int	i;
	unsigned int	base_length;

	temp = NULL;
	base_length = ft_strlen(base);
	if (base)
		temp = base;
	output = malloc((base_length + addition_count + 2) * sizeof(char));
	if (!output)
	{
		free(output);
		output = NULL;
		return (0);
	}
	else
	{
		i = 0;
		while (i++ < base_length)
			output[i - 1] = base[i - 1];
		i = 0;
		while (i++ < addition_count)
			output[base_length + i - 1] = addition[i - 1];
		output[base_length + i - 1] = '\0';
		// printf("\nft_add_string: output: {%s} && address: {%p}\n", output, output);
	}
	if (temp)
	{
		// printf("ft_add_string: temp is {%p} at address: {%p}\n", temp, temp);
		free(temp);
	}
	return (output);
}

/* Only reads if read_ret == BUFFER_SIZE, 
meaning we are not at the end of the fd */
// NEED: read() error handling
int	ft_read(int fd, char *buf, int read_ret)
{
	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret > -1)
		buf[read_ret] = '\0';
	if (read_ret == -1)
		ft_fill_char(buf, '\0');
	return (read_ret);
}

//strings to test:
// abcde.\n\0
// abcde.\n\n
// abcde.\n\0\n
// abcde.\n\0ab


// #include <fcntl.h>
// int main()
// {
// 	char *path_to_example_text;
// 	// path_to_example_text = "/Users/fallan/42/get_next_line/examples/example2.txt";
// 	path_to_example_text = "/Users/fallan/francinette/tests/get_next_line/fsoares/read_error.txt";

// 	int fd = open(path_to_example_text, O_RDONLY);
// 	fd = open(path_to_example_text, O_RDONLY);

// 	char	*ret_value;
// 	ret_value = NULL;

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	ret_value = get_next_line(fd);
// 	if (ret_value == NULL) printf("\nnext line: get_next_line returned NULL");
// 	else printf("\nnext line:\"%s\"", ret_value);

// 	if (ret_value)
// 	{
// 		free(ret_value);
// 		ret_value = NULL;
// 	}

// 	close(fd);
// 	return (0);
// }
