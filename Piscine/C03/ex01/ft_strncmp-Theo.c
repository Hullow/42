#include <stdio.h>
#include <string.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	i = 0;
	if (n == 0)
		return(0);
	else
	{
		while ((s1[i] || s2[i]) && (i < n)) //  && s1[i] == s2[i] 
		{
			if (s1[i] != s2[i])
				return(s1[i] - s2[i]);
			i++;
		}
		printf("i is %d\n", i);
		printf("n is %d\n", n);
	//if (n != 0)
		return(s1[i] - s2[i]);

	//	return(s1[i-1] - s2[i-1]);
	}
}

int main(void)
{
unsigned int n;
int result;
int benchmark;

n = 4;
result = ft_strncmp("abcde", "abcdf", n); // ma fonction
benchmark = strncmp("abcde", "abcdf", n); // strncmp
//						s1	 ,	  s2  , n

// Test de ma fonction
if (result == 0)
printf("my function: same string for %d characters, returns: %d.\n", n, result);

else
printf("my function, different strings for %d characters, returns: %d.\n", n, result);

// Test de la fonction strncmp
if (benchmark == 0)
printf("strncmp: same string for %d characters, returns: %d.\n", n, benchmark);

else
printf("strncmp: different strings for %d characters, returns: %d.\n", n, benchmark);
return(0);
}