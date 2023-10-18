/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:39 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:27:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*string;
	unsigned char	character;

	string = (const char*) s;
	character = c;
	while (n > 0 && string)
	{
		if (*string == character)
			return (void *)string;
		else
			{
				string++;
				n--;
			}
	}
	return (NULL);
}

/* #include <string.h>
int	main()
{
	char string[15];
	const void *s = string;
	int	c = 97; // 'a'

	strcpy(string, "Braquemart");
	
	// printf("Memchr points to string %s\n", memchr(s, c, 5));
	printf("ft_memchr points to string %s\n", ft_memchr(s, c, 2));
		return (0);
} */