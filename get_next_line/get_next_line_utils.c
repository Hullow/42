/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/02/27 14:19:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// we need a function to locate the \n
// if it locates one, return a null-terminated string stopping at \n
// if not, return 0 => usable in an if condition

/* ft_strjoin with a free for both input strings */
char	*ft_add_string(char const *addition, char const *base)
{
	char			*output;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(addition);
	len2 = ft_strlen(base);
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (!output)
		return (NULL);
	else
	{
		i = 0;
		while (i++ < len2)
			output[i - 1] = base[i - 1];
		i = 0;
		while (i++ < len1)
			output[len2 + i - 1] = addition[i - 1];
		output[len2 + i + 1 - 1] = '\0';
	}
	return (output);
}

// //
// int ft_clean(char *ptr)
// {
// 	free(ptr);
// 	ptr = NULL;
// 	return (NULL);
// }

/* looks at #BUFFER_SIZE characters in a string: 
	- if those characters contain an '\n', 
	returns a string of all characters up to that point
	- otherwise, returns 0 */
char	*ft_locate_end_of_line(char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*output = NULL;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
	{
		output = malloc((i + 2) * sizeof(char));
		if (!output)
			return (NULL);
		while (j <= i && buf[j])
		{
			output[j] = buf[j];
			j++;
		}
		output[j] = '\0';
		return (output);
	}
	else
		return (0);
}

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
		while (i < n)
		{
			str[i] = c;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_next_lines(char *buf)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	while (buf[i] != 0 && buf[i] != '\n')
		i++;
	if (buf[i++] == '\n')
	{
		while (buf[i + j])
			j++;
		output = malloc((j + 1) * sizeof(char));
		if (!output)
			return (NULL);
		output[j] = '\0';
		while (j-- > 0)
			output[j] = buf[i + j];
		return (output);
	}
	else
		return (0);
}
