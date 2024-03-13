/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/03/13 09:48:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char			*buf;
	static char		next_lines[BUFFER_SIZE];
	static int		read_ret = BUFFER_SIZE;
	struct Result	res;

	res.line = NULL;
	buf = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (ft_strlen(next_lines))
		ft_strlcpy(buf, next_lines, BUFFER_SIZE + 1);
	else if (read_ret == BUFFER_SIZE)
		read_ret = ft_read(fd, buf, read_ret);
	else
	{
		free(buf);
		return (res.line);
	}
	res = ft_fill_line(buf, res.line, read_ret, fd);
	read_ret = res.read_ret;
	if (ft_end_of_line(res.buf))
		res.line = ft_add_string(res.buf, ft_end_of_line(res.buf), res.line);
	ft_next_lines(next_lines, buf);
	free(buf);
	return (res.line);
}

/* fills the line with characters from the buffer if the buffer 
doesn't contain a newline character then, reads again into the buffer
, and repeats the operations if no newline 
returns the line, buffer, and last read return value */
struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd)
{
	struct Result	res;

	while (ft_end_of_line(buf) == 0 && ft_strlen(buf))
	{
		line = ft_add_string(buf, ft_strlen(buf), line);
		read_ret = ft_read(fd, buf, read_ret);
	}
	res.read_ret = read_ret;
	res.line = line;
	res.buf = buf;
	// NEED: read() error handling: e.g. if (read_ret == -1)
	return (res);
}

void	ft_free(char *target, char *temp, int free_now)
{
	printf("ft_free: target address is %p, temp address is %p\n", target, temp);
	if (free_now)
	{
		printf("free_now = %d\n", free_now);
		if (target)
		{
			printf(" \"if target:\": there is a target, it will be freed\n");
			free(target);
		}
		else
			printf(" \"if target:\": there is no target, it won't be freed\n");
	}
	else
	{
		printf("!free_now\n");
		if (target)
		{
			printf(" \"if target:\": there is a target, it will be freed\n");
			temp = target;
		}
		else
			printf(" \"if target:\": there is no target, it won't be freed\n");
	}
}

/* ft_strjoin adaptation */
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
	output = malloc((base_length + addition_count + 1) * sizeof(char));
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
	if (temp)
		free(temp);
	return (output);
}

/* Only reads if read_ret == BUFFER_SIZE, 
meaning we are not at the end of the fd */
// NEED: read() error handling
int	ft_read(int fd, char *buf, int read_ret)
{
	ft_fill_char(buf, '\0');
	if (read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
	}
	return (read_ret);
}

/* looks at #BUFFER_SIZE characters in a string: 
	- if those characters contain an '\n', 
	returns the index of '\n' + 1 (in case '\n' is at index 0)
	- otherwise, returns 0 */
unsigned int	ft_end_of_line(char *buf)
{
	unsigned int	i;

	i = 0;
	while (i < (BUFFER_SIZE) && buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	else
		return (0);
}

/*
//strings to test:
// abcde.\n\0
// abcde.\n\n
// abcde.\n\0\n
// abcde.\n\0ab
int main()
{
	char *path_to_example_text;
	path_to_example_text = "/Users/fallan/42/get_next_line/examples/example.txt";

	int fd = open(path_to_example_text, O_RDONLY);
	fd = open(path_to_example_text, O_RDONLY);

	char	*ret_value;
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

*/