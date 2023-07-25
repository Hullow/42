// started replacing i with sizeof(src) +> but src varies

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    j;
    char    *temp;

    temp = dest;
    /*  while (src[i] != '\0')
    {
        i++;
    } 
    if(i > n) */
    if (sizeof(src) > n)
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
    else {
        j = 0;
        while (j < sizeof(src))
        {
        *dest = *src;
        src++;
        dest++;
        j++;
        }
        while (j <= (n - sizeof(src)))
        {
            *dest = '\0';
            j++;
        }
    }
    dest = temp;
    return (dest);
}

#include<stdio.h>
int main(void)
{
    char dest[10] = "Worldd1";
    ft_strncpy(dest, "Hello", 5);
    printf("%s", dest);
    return (0);
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
