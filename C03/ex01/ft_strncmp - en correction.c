/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:26:23 by fallan            #+#    #+#             */
/*   Updated: 2023/07/31 23:29:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	else if (*s1 > 0 && *s2 == 0)
		return (1);
	else if (*s1 == 0 && *s2 > 0)
		return (-1);
	else
	{
		while (*s1 && *s2)
		{
			s1++;
			s2++;
			while (n > 0)
			{
				if (*s1 == *s2)
				n--;
			}
			return (*s1-*s2);
		}
	}
	return (*s1 - *s2);
}

int main(void)
{
unsigned int n;
int result;
int benchmark;

n = 5;
result = ft_strncmp("abcdef", "abcde", n); // ma fonction
benchmark = strncmp("abcdef", "abcde", n); // strncmp

// Test de ma fonction
if (result == 0)
printf("my function: same string for %d characters, return value: %d.\n", n, result);

else
printf("my function, different strings %d characters, return value: %d.\n", n, result);


// Test de la fonction strncmp
if (benchmark == 0)
printf("strncmp: same string for %d characters return value: %d.\n", n, benchmark);

else
printf("strncmp: different strings for %d characters, return value: %d.\n", n, benchmark);
return(0);
} 
