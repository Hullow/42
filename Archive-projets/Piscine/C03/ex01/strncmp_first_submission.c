int ft_strncmp(char *s1, char *s2, unsigned int n)
{
     if (n == 0)
          return (0);
     else if (*s1 > 0 && *s2 == 0)
          return (1);
     else if (*s1 == 0 && *s2 > 0)
          return (-1);
     else
     {    while (n && *s1 && *s2)
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
int  main(void)
{
     unsigned int   n;
     int  result;
     int  benchmark;

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

/*      Errors:
     [2] Comparing non-empty string with empty string: expected positive value, got 0
     [3] Comparing empty string with non-empty string: expected negative value, got 0
     [22] Comparing empty string with non-empty string: expected negative value, got 0
     [23] Comparing non-empty string with empty string: expected positive value, got 0

     Ok:
     ✓ [1] Comparing empty strings with n > 0: expected 0, got 0
     ✓ [4] Comparing same string with n = 0: expected 0, got 0
     ✓ [5] Comparing strings with different character case: expected negative value, got -1
     ✓ [6] Comparing strings with different character case: expected negative value, got -1
     ✓ [7] Comparing strings with different character case: expected negative value, got -1
     ✓ [8] Comparing same string with n > length of string: expected 0, got 0
     ✓ [9] Comparing different string with n > length of string: expected negative value, got -1
     ✓ [10] Comparing different string with n > length of both strings: expected negative value, got -1
     ✓ [11] Comparing strings where n is smaller than s1: expected negative value, got -1
     ✓ [12] Comparing strings where n is smaller than s2: expected negative value, got -1
     ✓ [13] Comparing empty strings with n smaller than 1: expected 0, got 0
     ✓ [14] Comparing empty string and non-empty string with n smaller than 1: expected 0, got 0
     ✓ [15] Comparing non-empty string and empty string with n smaller than 1: expected 0, got 0
     ✓ [16] Comparing equal strings with n = 0: expected 0, got 0
     ✓ [17] Comparing different strings with n = 0: expected 0, got 0
     ✓ [18] Comparing equal strings with n > string length: expected 0, got 0
     ✓ [19] Comparing different strings with n > string length: expected negative value, got -1
     ✓ [20] Comparing strings with same prefix and n < string length: expected 0, got 0
     ✓ [21] Comparing strings with different prefix and n < string length: expected negative value, got -1
     ✓ [24] Comparing string with different ends and n is smaller than size: expected 0, got 0 */

  /*    Argc argv:
            if (!(ft_strncmp(argv[1], argv[2], *argv[3])))
          printf("my function, the strings \"%s\" and \"%s\" are the same for the first %s characters.\n", argv[1], argv[2], argv[3]);
     else
          printf("my function, the strings \"%s\" and \"%s\" are different for the first %s characters.\n", argv[1], argv[2], argv[3]);
    if (!(strncmp(argv[1], argv[2], *argv[3])))
          printf("strncmp: the strings \"%s\" and \"%s\" are the same for the first %s characters.\n", argv[1], argv[2], argv[3]);
     else
          printf("strncmp: the strings \"%s\" and \"%s\" are different for the first %s characters.\n", argv[1], argv[2], argv[3]);  */