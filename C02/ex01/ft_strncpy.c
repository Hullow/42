/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:58:10 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 22:32:26 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// started replacing i with sizeof(src) => but src varies

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    i;
    char    *temp;

    temp = dest;
    if (sizeof(src) > n)
    {
        i = 0;
        while (i < n)
        {
        *dest = *src;
        src++;
        dest++;
        i++;
        }
    }
    else 
    {
        i = 0;
        while (i < sizeof(src))
        {
        *dest = *src;
        src++;
        dest++;
        i++;
        }
        while (i < n)
        {
            *dest = '\0';
            i++;
        }
    }
    dest = temp;
    return (dest);
}

/* #include<stdio.h>
int main(void)
{
    char dest[10] = "Worldd1";

    ft_strncpy(dest, "Hello", 8);
    printf("%s\n", dest);
    printf("length of destination array is : %lu", sizeof(dest));
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
