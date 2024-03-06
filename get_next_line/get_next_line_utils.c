/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/03/06 16:39:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// int ft_clean(char *ptr)
// {
// 	free(ptr);
// 	ptr = NULL;
// 	return (NULL);
// }


/* adapted from ft_bzero (see libft)
takes a string s, creates a pointer str to it of length ft_strlen(s), 
then fills that pointer with '\0', and return it */
void	*ft_fill_char(void *s, unsigned int n, char c)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) s;
	i = 0;
	if (str)
	{
		while (i < BUFFER_SIZE && i < n && str[i])
		{
			str[i] = c;
			i++;
		}
	}
	if (str[i])
		str[i] = '\0';
	return (str);
}

// abcde.\n\0
// abcde.\n\n
// abcde.\n\0\n
// abcde.\n\0ab

char	*ft_next_lines(char *dst, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\n' && src[i] && i < BUFFER_SIZE)
		i++;
	if (!src[i] || i == BUFFER_SIZE)
		return (0);
	else if (src[i++] == '\n')
	{
		if (src[i] == '\0')
			return (0);
		else
		{
			while (src[i + j] && i + j < BUFFER_SIZE)
			{
				dst[j] = src[i + j];
				j++;
			}
			dst[j] = '\0';
		}
		return (dst);
	}
	else
		return (0);
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
