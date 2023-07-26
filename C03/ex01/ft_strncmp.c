int ft_strncmp(char *s1, char *s2, unsigned int n)
{
     while (n && s1 && s2)
          {
          if (*s1 == *s2)
               n--;
          else if (*s1 > *s2)
               return(1);
          else if (*s1 < *s2)
               return(-1);
          s1++;
          s2++;
          }
     return (0);
}

#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    argc = 4;
     if (!(ft_strncmp(argv[1], argv[2], argv[3])))
          printf("According to my function, the strings \"%s\" and \"%s\" are the same when comparing the first %s characters.\n", argv[1], argv[2], argv[3]);
     else
          printf("According to my function, the strings \"%s\" and \"%s\" are different when comparing the first %s characters.\n", argv[1], argv[2], argv[3]);
    if (!(strncmp(argv[1], argv[2], *argv[3])))
          printf("According to strncmp, the strings \"%s\" and \"%s\" are the same when comparing the first %s characters.\n", argv[1], argv[2], argv[3]);
     else
          printf("According to strncmp, the strings \"%s\" and \"%s\" are different when comparing the first %s characters.\n", argv[1], argv[2], argv[3]);
    return(0);
}
/* 
DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the null-terminated 
     strings s1 and s2.

     The strncmp() function compares not more than n characters.  
     Because strncmp() is designed for comparing strings rather than
     binary data, characters that appear after a `\0' character are not compared.

RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than, equal to, 
     or less than 0, according as the string s1 is
     greater than, equal to, or less than the string s2.  
     The comparison is done using unsigned characters, so that `\200' is greater than `\0'.
     s*/