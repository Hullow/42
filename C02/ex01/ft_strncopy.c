#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (*(src+i) != '\0')
    {
        i++;
    }
    if(i > n)
    {
        j = 0;
        while (j < n)
        {
        *dest = *src;
        src++;
        dest++;
        j++;
        }
    }
    else
    {
        j = 0;
        while (j < i)
        {
        *dest = *src;
        src ++;
        dest++;
        j++;
        }
        while (i <= n)
        {
            *dest = '\0';
            i++;
        }
    }
    return (dest);
}
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


int main(void)
{
    char chararray[6];
    int i;

    ft_strncpy(chararray, "abc", 6);
//    printf("The string copied is: %s. \n", chararray);
    i = 0;
    while (i < 9)
    {
        write(1, chararray+i, 1);
        i++;
    }
    return (0);
}