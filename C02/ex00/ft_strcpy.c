#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
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
/*
    src = a => dst
    src++ => b

    src = b => dest
    src++ => c 

    src == c => dest
    src++ => d

    src == d => dest
    src++ => e

    src == e => dest
    src ++ => \0
    (dest++)

    src == \0 => no loop
*/
//   *dest = *src;

    return (temp);
}
/* 
int main(void)
{
    char    chararray[10];

    ft_strcpy(chararray, "abcd");

    printf("%s", chararray);
    return (0);
} */
/*    char *chararray;
    chararray = (char*)malloc(5 * sizeof(char));
    strcpy(chararray, "abc");
    char    *src;
    

    src = "abcde";
*/

//    printf("The string copied is: %s. \n", chararray);
 

/* Fonctions Autorisées : Aucune
Reproduire à l’identique le fonctionnement de la fonction strcpy (man strcpy)
     char *
     strcpy(char * dst, const char * src);
The stpcpy() and strcpy() functions copy the string src to dst (including the terminating ‘\0’ character.)
The strcpy() and strncpy() functions return dst.
*/