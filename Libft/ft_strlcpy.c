/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:12:01 by fallan            #+#    #+#             */
/*   Updated: 2023/10/27 03:47:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long				i;

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
	return (sizeof(src));
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[50];
	char	dst[50];

	strcpy(src, "Hiyaaaaaaaaaaa !!!!....b");
	strcpy(dst, "Booyakasha ----*****c");

	printf("src : '%s'\n", src);
	printf("dst : '%s'\n", dst);
	// strlcpy(dst, src, sizeof(dst));
	// printf("dst after strlcpy:\n'%s'\n", dst);
 	ft_strlcpy(dst, src, sizeof(dst));
	printf("dst after ft_ strlcpy:\n'%s'\n", dst);

	return (0);
} */

/* Return values
Like snprintf(3), the strlcpy() and strlcat() \
functions return the total length of the string
they tried to create.  For strlcpy() that means the length of src.

If the return value is >= dstsize, the output string has been truncated. 
It is the caller's responsibility to handle this. */