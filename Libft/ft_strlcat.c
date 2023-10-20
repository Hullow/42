/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2023/10/20 16:53:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	dstlen;
	unsigned long	srclen;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] != '\0')
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - dstlen - 1)
		{
			dst[dstlen+i] = src[i];
			i++;
		}
		dst[dstlen+i] = '\0';
	}
	return (dstlen + srclen);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[50];
	char	dst[50];

	strcpy(src, "Hiyaaa !!!!....b");
	strcpy(dst, "Booyakasha");

	printf("size of dst is: %lu\n", sizeof(dst));
	printf("size of src is: %lu\n\n", sizeof(src));
	printf("strlen(dst) is: %lu\n", strlen(dst));
	printf("strlen(src) is: %lu\n\n", strlen(src));

	// strlcat(dst, src, sizeof(dst));
	// printf("dst after strlcat:\n'%s'\n", dst);

 	printf("src : '%s'\n", src);
	printf("dst : '%s'\n\n", dst);

 	ft_strlcat(dst, src, sizeof(dst) + 1);
	 
	printf("dst after ft_ strlcat:\n'%s'\n", dst);

	return (0);
} */

/* Return values
Like snprintf(3), the strlcpy() and strlcat() functions return the total length of the string
they tried to create.  For strlcpy() that means the length of src.

If the return value is >= dstsize, the output string has been truncated. 
It is the caller's responsibility to handle this. */