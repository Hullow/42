/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/02/12 16:33:54 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// we need a function to locate the \n
// if it locates one, return a null-terminated string stopping at \n
// if not, return 0 => usable in an if condition

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char) c)
			return (ptr);
		else
			ptr++;
	}
	if (*ptr == (char) c)
		return (ptr);
	else
		return (NULL);
}

char	*ft_locatenewline(char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*output;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n') // check if there is a \n in the buffer string
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


// ft_strjoin with a free for both input strings
char	*ft_addstring(char const *addition, char const *base)
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
		output[len2 + i] = '\0';
	}
	// free((void *)addition); // is this really needed ? isn't it automatically freed when we call read(fd, buf, BUFFER_SIZE); again ?
	return (output);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}