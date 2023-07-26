int ft_strcmp(char *s1, char *s2)
{
   /*  What the function should do is take both strings, and:
        advance until one is equal 0. In that case 

    if (sizeof(s1) == sizeof(s2))
    {

    } */
    while (*s1 != 0 && *s2 != 0)
    {
        if (*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else if (*s1 > *s2)
            {
            return (1);
            }
        else if (*s1 < *s2)
            {
            return (-1);
            }
    }
    if (*s1 == 0 && *s2 == 0)
        return (0);
    else if (*s1 != 0)
        return (1);
    else if (*s2 != 0)
        return (-1);
    else return(1);
}

/* #include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    argc = 3;
    int comp = ft_strcmp(argv[1], argv[2]);
    int bench = strcmp(argv[1], argv[2]);
    if  (comp == 0)
        printf("According to my function ft_strcmp, the two strings, %s and %s, are equal.\n", argv[1], argv[2]);
    else if (comp == 1)
        printf("According to my function ft_strcmp, the first non-matching character in %s is greater (in ASCII) than that of %s.\n", argv[1], argv[2]);
    else if (comp  == -1)
        printf("According to my function ft_strcmp, the first non-matching character in %s is lower (in ASCII) than that of %s.\n", argv[1], argv[2]);
    
    if (bench == 0)
        printf("According to strcmp, the two strings, %s and %s, are equal.\n", argv[1], argv[2]);
    else if (bench > 0)
    {
        printf("According to strcmp, the first non-matching character in %s is greater (in ASCII) than that of %s.\n", argv[1], argv[2]);
        printf("The return value of the function is: %d.\n", bench);
    }
    else if (bench < 0)
    {
        printf("According to strcmp, the first non-matching character in %s is lower (in ASCII) than that of %s.\n", argv[1], argv[2]);
        printf("The return value of the function is: %d.\n", bench);
    }
    return(0);
} */
/* 
DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the null-terminated 
     strings s1 and s2.
RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than, equal to, 
     or less than 0, according as the string s1 is
     greater than, equal to, or less than the string s2.  
     The comparison is done using unsigned characters, so that `\200' is greater than `\0'.
     s*/

/* Mini-moulinette errors:
    [2] Compare two different strings of equal length Expected 108, got 0
    [3] Compare two different strings of different length Expected -49, got 0
    [5] Compare a string with an empty string Expected 72, got 0
    [15] Compare two non-identical strings with different pointers Expected -15, got -1

Okay:
  ✓ [1] Compare two equal strings Expected 0, got 0
  ✓ [4] Compare two empty strings Expected 0, got 0
  ✓ [6] Compare two strings of length 1 Expected -1, got -1
  ✓ [7] Compare two strings of length 1 (reversed) Expected 1, got 1
  ✓ [8] Compare two strings of length 2 Expected -1, got -1
  ✓ [9] Compare two strings of length 2 (reversed) Expected 1, got 1
  ✓ [10] Compare two strings with null character Expected 0, got 0
  ✓ [11] Compare two strings with null character (reversed) Expected 0, got 0
  ✓ [12] Compare two strings with multiple null characters Expected 0, got 0
  ✓ [13] Compare two strings with multiple null characters (reversed) Expected 0, got 0
  ✓ [14] Compare two identical strings with different pointers Expected 0, got 0 */