/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:50 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:23:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	else if (*s1 > 0 && *s2 == 0)
		return (1);
	else if (*s1 == 0 && *s2 > 0)
		return (-1);
	else
	{
		while (n && *s1 && *s2)
		{
			if (*s1 == *s2)
				n--;
			else if (*s1 > *s2)
				return (1);
			else if (*s1 < *s2)
				return (-1);
			s1++;
			s2++;
		}
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int main(void)
{
unsigned int n;
int result;
int benchmark;

n = 0;
result = ft_strncmp("aaa", "", n);
benchmark = strncmp("aaa", "", n);
if (!result)
printf("my function, the strings are the same for the first %d characters, the return value being %d.\n", n, result);
else
printf("my function, the strings are different for the first %d characters, the return value being %d.\n", n, result);
if (!benchmark)
printf("strncmp: the strings are the same for the first %d characters, the return value being %d.\n", n, benchmark);
else
printf("strncmp: the strings are different for the first %d characters, the return value being %d.\n", n, benchmark);
return(0);
} */