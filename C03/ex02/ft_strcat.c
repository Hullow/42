char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int size;
	
	i = 0;
	size = 0;
	while (dest[size] != 0)
		size++;
	while (src[i] != 0)
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
printf("my function: resulting string is \"%s\".\n", ft_strcat(dest, src));
printf("dest is \"%s\".\n", dest);
printf("strcat: resulting string is \"%s\".\n", strcat(dest, src));
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