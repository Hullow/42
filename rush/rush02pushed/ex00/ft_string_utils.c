/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:27:15 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 11:09:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// ======================================================================

void	ft_putchar(char *str);

// ======================================================================

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(str);
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		ft_putchar("Error\n");
		return (NULL);
	}
	ft_strcpy(duplicate, str);
	return (duplicate);
}
