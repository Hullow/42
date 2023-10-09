char *ft_strncat(char *dest, char *src, unsigned int nb)
{
unsigned int i;
int size;

i = 0;
size = 0;
while (dest[size] != 0)
size++;
while (src[i] != 0 && i < nb)
{
dest[size+i] = src[i];
i++;
}
dest[size+i] = 0;
return (dest);
}

/* 
#include <string.h>
#include <stdio.h>
int	main(void)
{
char	dest[] = "42 ";
char	src[] = "Network";
unsigned int nb = 6;

printf("my function: resulting string is \"%s\".\n", ft_strncat(dest, src, nb));
printf("dest is \"%s\".\n", dest);
printf("strcat: resulting string is \"%s\".\n", strncat(dest, src, nb));
return (0);
} */

/* Errors:

    [2] Append a string to a non-empty string Expected "42 Network", got "42 "
    [3] Append a string to itself Expected "HelloHello", got "Hello"
Ok:
  ✓ [1] Append a string to an empty string Expected "Hello", got "Hello"
  ✓ [4] Append an empty string to a non-empty string Expected "Hello", got "Hello"
  ✓ [5] Append an empty string to an empty string Expected "", got "" */

/*
 MAN STRCPY:
 The strcat() and strncat() functions append a copy of the null-terminated string s2 to the end of the null-terminated
  string s1, then add a terminating `\0'.  The string s1 must have sufficient space to hold the result.

     The strncat() function appends not more than n characters from s2, and then adds a terminating `\0'.

     The source and destination strings should not overlap, as the behavior is undefined.

     The strcat() and strncat() functions return the pointer s1.
*/

/*	int	i = 0;
	int	nullsize;
	printf("The size of s1 is %lu.\n", sizeof(s1));
	printf("The 4th value of s1, s1[3], is %c.\n", s1[3]);
	while (s1[i] != 0)
		i++;
	nullsize = sizeof(s1) - i;
	printf("The size of s1 is %lu and there are %d null characters.\n", sizeof(s1), nullsize);
*/