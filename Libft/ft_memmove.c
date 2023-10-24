/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:55 by fallan            #+#    #+#             */
/*   Updated: 2023/10/24 16:23:28 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *) src;
	s2 = (char *) dst;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (s1 > s2)
		while (i++ < len)
			s2[i] = s1[i];
	else
		while (len-- > 0)
			s2[len - 1] = s1[len - 1];
	return (dst);
}

/* #include <string.h>
int main()
{
	char test1[] = "abcdef";
	printf("before memmove: '%s'\n", test1);
	memmove(test1, test1 + 2, 4);
	printf("after memmove: src: '%s' and dst: '%s'\n\n", test1, test1 + 2);

	char test2[] = "abcdef";
	printf("before ft_memmove: '%s'\n", test2);
	ft_memmove(test2, test2 + 2, 4);
	printf("after ft_memmove: src: '%s' and dst: '%s'\n", test2, test2 + 2);

	return (0);
} */