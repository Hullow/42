int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return(0);
	else
		while (s1[i] != 0 | s2[i] != 0)
			i++;
		return(s1[i]-s2[i]);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
unsigned int n;
int result;
int benchmark;

n = 5;
result = ft_strncmp("abcd", "abcde", n); // ma fonction
benchmark = strncmp("abcd", "abcde", n); // strncmp

// Test de ma fonction
if (result == 0)
printf("my function: same string for %d characters, return value: %d.\n", n, result);

else
printf("my function, different strings %d characters, return value: %d.\n", n, result);

// Test de la fonction strncmp
if (benchmark == 0)
printf("strncmp: same string for %d characters return value: %d.\n", n, benchmark);

else
printf("strncmp: different strings for %d characters, return value: %d.\n", n, benchmark);
return(0);
}