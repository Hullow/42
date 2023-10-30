/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:55 by fallan            #+#    #+#             */
/*   Updated: 2023/10/30 11:07:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

/* void	*ft_memmove(void *dst, const void *src, size_t len);
#include <string.h>
int main()
{
	char test1[] = "abcdefgh";
	printf("before memmove: src is '%s', dst is '%s'\n", test1 + 2, test1);
	memmove(test1, test1 + 2, 4);
	printf("after memmove: src is '%s' and dst is '%s'\n\n", test1 + 2, test1);

	char test2[] = "abcdefgh";
	printf("before ft_memmove: '%s', dst is '%s'\n", test2 + 2, test2);
	ft_memmove(test2, test2 + 2, 4);
	printf("after ft_memmove: src is '%s' and dst is '%s'\n", test2 + 2, test2);

	return (0);
} */

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
	if (s1 < s2)
		while (len-- > 0) // evaluates len, then decrements, then runs the loop
		{
			// printf("len is %lu\n", len);
			// printf("s2[len]: '%c', is set to s1[len]: '%c'\n", s2[len], s1[len]);
			s2[len] = s1[len];
		}
	else // when s2 < s1
		while (i++ < len) // evaluates i, then increments, then runs the loop
			s2[i - 1] = s1[i - 1];
	return (dst);
}