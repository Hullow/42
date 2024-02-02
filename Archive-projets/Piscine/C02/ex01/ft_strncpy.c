/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:58:10 by fallan            #+#    #+#             */
/*   Updated: 2023/07/27 21:05:55 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
/*
	if (sizeof(src) > n)
	{
	i = 0;
	else
	{
		i = 0;
		while (i < sizeof(src))
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			*dest = '\0';
			i++;
		}
	}
	return (temp);
}
*/
/*
#include<stdio.h>
int	main(void)
{
	char	dest[10] = "Worldd1";
// int argc, char **argv)

	ft_strncpy(dest, "Hello", 3);
	printf("The return value is : %s.\n", ft_strncpy(dest, "Hello", 3));
//	argc = 4;
//	printf("The return value is: %s.\n", ft_strncpy(argv[1], argv[2], *argv[3]));
	return (0);
} */

/* Fonctions Autorisées : Aucune
Reproduire à l’identique le fonctionnement de la fonction strcpy (man strcpy)
     char *
     strcpy(char * dst, const char * src, size_t len);
The stpcpy() and strcpy() functions copy the string src to dst (including the terminating ‘\0’ character.)
The stpncpy() and strncpy() functions copy at most len characters from src into dst.  If src is less than len characters
     long, the remainder of dst is filled with ‘\0’ characters.  Otherwise, dst is not terminated.
The strcpy() and strncpy() functions return dst.
The source and destination strings should not overlap, as the behavior is undefined.
*/
