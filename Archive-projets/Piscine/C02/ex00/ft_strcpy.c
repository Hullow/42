/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:57:54 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 19:07:42 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
    char *temp;

    temp = dest;
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return (temp);
}

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
    char    chararray[10];

    ft_strcpy(chararray, "abcd");
    strcpy(chararray, "abcd");
    printf("%s", chararray);
    return (0);
}
/* Fonctions Autorisées : Aucune
Reproduire à l’identique le fonctionnement de la fonction strcpy (man strcpy)
     char *
     strcpy(char * dst, const char * src);
The stpcpy() and strcpy() functions copy the string src to dst (including the terminating ‘\0’ character.)
The strcpy() and strncpy() functions return dst.
*/