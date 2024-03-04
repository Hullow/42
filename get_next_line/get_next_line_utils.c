/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/03/03 00:02:59 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// we need a function to locate the \n
// if it locates one, return a null-terminated string stopping at \n
// if not, return 0 => usable in an if condition

/* ft_strjoin with a free for both input strings */
char	*ft_add_string(char *addition, unsigned int addition_count, char *base)
{
	char			*output;
	unsigned int	i;
	unsigned int	base_length;

	base_length = ft_strlen(base);
//	if (base_length == 0) 
//		return (base);
	output = malloc((base_length + addition_count + 2) * sizeof(char));
	if (!output)
		return (NULL);
	else
	{
		// output[0] = '\0';
		// output = output + 1;
		i = 0;
		while (i++ < base_length)
			output[i - 1] = base[i - 1];
		i = 0;
		while (++i <= addition_count)
			output[base_length + i - 1] = addition[i - 1];
		output[base_length + i - 1] = '\0';
	}
	// if (base_length)
	//	free(base);
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
	returns the index of '\n' + 1 (in case '\n' is at index 0)
	- otherwise, returns 0 */
unsigned int	ft_locate_end_of_line(char *buf)
{
	unsigned int	i;

	i = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		return (i + 1);
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

char	*ft_next_lines(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0' && i < (int)ft_strlen(buf))
		i++;
	if (buf[i++] == '\n')
	{
		if (buf[i] == '\0')
			return (0);
		else
			return (buf + i);
	}
	else
		return (0);
}
