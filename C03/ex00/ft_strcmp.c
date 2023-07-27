int ft_strcmp(char *s1, char *s2)
{
    while (*s1 != 0 && *s2 != 0 && *s1 == *s2)
    {
            s1++;
            s2++;
    }
    if (*s1 == 0 && *s2 == 0)
        return (0);
    else if (*s1 == 0 && *s2 != 0)
        return (- *s2);
    else if (*s2 == 0 && *s1 != 0)
        return (*s1);
    else // if ((*s1 > *s2) || (*s1 < *s2))
        return (*s1 - *s2);
}

/* #include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    argc = 3;
    int myfunction = ft_strcmp(argv[1], argv[2]);
    int benchmark = strcmp(argv[1], argv[2]);
// Test using strcmp
    if (benchmark == 0)
        printf("strcmp: the two strings, %s and %s are identical, the return value being %d.\n", argv[1], argv[2], benchmark);
    else if (benchmark > 0)
        printf("strcmp: the first non-matching character in %s is greater (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], benchmark);
    else if (benchmark < 0)
        printf("strcmp: the first non-matching character in %s is lower (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], benchmark);
// Test using my function
    if  (myfunction == 0)
        printf("my function: the two strings, %s and %s are identical, the return value being %d.\n", argv[1], argv[2], myfunction);
    else if (myfunction < 0)
        printf("my function: the first non-matching character in %s is greater (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], myfunction);
    else if (myfunction > 0)
        printf("my function: the first non-matching character in %s is lower (in ASCII) than that of %s, the return value being %d.\n", argv[1], argv[2], myfunction); 
    return(0);
} */
/* 
DESCRIPTION
     The strcmp() and strncmp() functions lexicographically myfunctionare the null-terminated 
     strings s1 and s2.
RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than, equal to, 
     or less than 0, according as the string s1 is
     greater than, equal to, or less than the string s2.  
     The myfunctionarison is done using unsigned characters, so that `\200' is greater than `\0'.
     s*/

/* Mini-moulinette errors:
    [2] myfunctionare two different strings of equal length Expected 108, got 0
    [3] myfunctionare two different strings of different length Expected -49, got 0
    [5] myfunctionare a string with an empty string Expected 72, got 0
    [15] myfunctionare two non-identical strings with different pointers Expected -15, got -1

Okay:
  ✓ [1] myfunctionare two equal strings Expected 0, got 0
  ✓ [4] myfunctionare two empty strings Expected 0, got 0
  ✓ [6] myfunctionare two strings of length 1 Expected -1, got -1
  ✓ [7] myfunctionare two strings of length 1 (reversed) Expected 1, got 1
  ✓ [8] myfunctionare two strings of length 2 Expected -1, got -1
  ✓ [9] myfunctionare two strings of length 2 (reversed) Expected 1, got 1
  ✓ [10] myfunctionare two strings with null character Expected 0, got 0
  ✓ [11] myfunctionare two strings with null character (reversed) Expected 0, got 0
  ✓ [12] myfunctionare two strings with multiple null characters Expected 0, got 0
  ✓ [13] myfunctionare two strings with multiple null characters (reversed) Expected 0, got 0
  ✓ [14] myfunctionare two identical strings with different pointers Expected 0, got 0 */