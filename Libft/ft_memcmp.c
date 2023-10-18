/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:44 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:26:58 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char*) s1;
	string2 = (unsigned char*) s2;

	while (n > 0)
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
			n--;
		}
		else
			return (*string1 - *string2);
	}
	return (*string1 - *string2);
}

/* #include <string.h>
int	main()
{
	char string1[10];
	char string2[10];

	strcpy(string1, "abed");
	strcpy(string2, "abcd");
	
	const void *s1 = string1;
	const void *s2 = string2;


	if (ft_memcmp(s1, s2, 3) == 0)
		printf("my function: The two strings are identical.\n");
	else
		printf("my function:The two strings are different.\n");
	printf("my function's return value is %d.\n\n", ft_memcmp(s1, s2, 3));

	if (memcmp(s1, s2, 3) == 0)
		printf("memcmp: The two strings are identical.\n");
	else
		printf("memcmp: The two strings are different.\n");
	printf("memcmp's return value is %d.\n", memcmp(s1, s2, 3));

	return (0);
} */