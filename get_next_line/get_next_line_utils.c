/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/02/19 17:15:04 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// we need a function to locate the \n
// if it locates one, return a null-terminated string stopping at \n
// if not, return 0 => usable in an if condition

// ft_strjoin with a free for both input strings
char	*ft_add_string(char const *addition, char const *base)
{
	char			*output;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(addition);
	len2 = ft_strlen(base);
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (output)
	{
		i = 0;
		while (i < len2)
		{
			output[i] = base[i];
			i++;
		}
		i = 0;
		while (i < len1)
		{
			output[len2 + i] = addition[i];
			i++;
		}
		output[len2 + i + 1] = '\0';
	}
	// free((void *)addition); // is this really needed ? isn't it automatically freed when we call read(fd, buf, BUFFER_SIZE); again ?
	return (output);
}

// takes in a string, checks #BUFFER_SIZE characters, if it those characters contain an '\n', returns a string of all characters up to that point, otherwise returns 0
char	*ft_end_of_line(char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*output;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n' && buf[i]) // check if there is a \n in the buffer string
		i++;
	if (buf[i] == '\n')
	{
		output = malloc((i+1) * sizeof(char));
		if (output)
		{
			while (j <= i)
			{
				output[j] = buf[j];
				j++;
			}
			output[j + 1] = '\0';
		}
		return (output);
	}
	else
		return (0);
}

// adapted from ft_bzero (see libft)
// takes a string s, creates a pointer str to it of length ft_strlen(s), then fill that pointer with '\0', and return it
void	*ft_fill_zero(void *s, unsigned int n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) s;
	i = 0;
	if (str)
	{
		while (i <= n)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}

char	*ft_next_lines(char *buf)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	while (buf[i] != 0 && buf[i] != '\n') // check if there is a \n in the buffer string
		i++;
	if (buf[i++] == '\n')
	{
		// printf("\nin ft_next_lines:\ni is %d, buf[%d] is '%c' and buf[%d-1] is '%c'\n", i, i, buf[i], i, buf[i-1]);
		while (buf[i + j]) // we start at buf[i+1], one character after the \n
						// and go to the end of the buffer, thus we arrive at buf[i + j] == '\0'.
						// j will be the strlen + 1 of the rest of the buf/next_lines,
			j++;
		// printf("\nin ft_next_lines:\nj is %d, buf[%d] is '%c' and buf[%d-1] is '%c'\n", j, j, buf[j], j, buf[j-1]);
		// printf("\nin ft_next_lines:\nj is %d and buf[i+j-1] is '%c'\n", j, buf[i+j-1]);
		output = malloc((j + 1) * sizeof(char));
		if (output)
		{
			// printf("before the while, j is %d\n", j);
			output[j] = '\0';
			// printf("before the while, j is %d, output[j] is '%c'\n", j, output[j]);
			while (j > 0)
			{
				j--;
				output[j] = buf[i + j];
				// printf("output[%d] is %c (char # %d)\n", j, output[j], output[j]);
			}
		}
		// printf("in ft_next_lines:\noutput is \"%s\"\n", output);
		return (output);
	}
	else
		return (0);
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