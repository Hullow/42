/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:55 by fallan            #+#    #+#             */
/*   Updated: 2023/10/23 16:36:28 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int	i;
	unsigned char *s1 = (unsigned char *) src;
	unsigned char *s2 = (unsigned char *) dst;

	i = 1;
		while (i <= len)
		{
			s2[len - i] = s1[len - i];e
			i++;
		}
	return (dst);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	char *src = "Blablabla Hello";
	char *dest = src + 3;
	// char dest2[50];
	unsigned int len = 1;

	// strcpy(dest, "Hello");

	printf("src is: '%s'\n", src);
	printf("dest is: '%s'\n\n", dest);

	memmove(dest, src, len);
	printf("dest after memmove is: '%s'\n\n", dest);

 	char *dest = src + 3;
	printf("dest is re-initialized to:'%s'\n\n", dest);
	

	ft_memmove(dest, src, len);
	printf("dest after ft_memmove is: '%s'\n", dest);

	return (0);
} */