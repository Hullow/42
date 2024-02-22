/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:08:39 by fallan            #+#    #+#             */
/*   Updated: 2024/02/22 17:12:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	// too many variable declarations in a function
	char		*buf;
	char		*temp = NULL;
	char		*end_of_line = NULL;
	char		*line = NULL;
	static char	*next_lines = "";
	static int	read_ret = BUFFER_SIZE;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (ft_strlen(next_lines))
		temp = next_lines;
	else if (read_ret == BUFFER_SIZE)
		read_ret = read(fd, (temp = buf), BUFFER_SIZE); // make this into a function with read() error handling
	else
		return (line);
	while (((end_of_line = ft_end_of_line(temp)) == 0) && ft_strlen(temp)) // no assignment in control structure
	{
		line = ft_add_string(temp, line);
		temp = ft_fill_zero(temp, ft_strlen(temp));
		buf = ft_fill_zero(buf, ft_strlen(buf));
		if (read_ret == BUFFER_SIZE)
			read_ret = read(fd, (temp = buf), BUFFER_SIZE);
	}
	if ((end_of_line = ft_end_of_line(temp)) || ((read_ret < BUFFER_SIZE) && (ft_strlen(temp))))
	{
		line = ft_add_string(end_of_line, line);
		next_lines = ft_next_lines(temp); // when to free ?
	}
	free(buf);
	free(end_of_line); // frees malloc from ft_end_of_line
	free(line); // free malloc from ft_add_string
	return (line);
}

// adapted for str == NULL
size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	if (str)
	{
		while (str[length] != 0)
			length++;
	}
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

/* void	ft_putstr_fd(char *s, int fd)
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
 */