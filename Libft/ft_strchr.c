/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:03 by fallan            #+#    #+#             */
/*   Updated: 2023/10/26 16:26:02 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

// To do: test edge cases like null string, null characters etc

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		else
			ptr++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	char	string[4];
	int		character = 0;

	strcpy(string, "abc");
	
	printf("For str. \"%s\" and char. \"%c\", \
	strchr produces: \"%s\"\n", string, character, \
	strchr(string, character));
	
	printf("For str. \"%s\" and char. \"%c\", \
	ft_strchr produces: \"%s\"\n", string, character, \
	ft_strchr(string, character));
	return (0);
}
*/