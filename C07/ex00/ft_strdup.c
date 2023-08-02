#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char*	copy;

	i = 0;
	while (src[i])
		i++;
	copy = (char*) malloc(i * sizeof(char));
	if (copy == NULL)
		{
			printf("Memory not allocated.\n");
			exit(0);
		}
	else
	{
	i = 0;
	while (src[i])
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
// do I _need_ to null terminate ?
	return (copy);
	}
}


int main()
{
	char *result = ft_strdup("just a string:");
	printf("My function: %s\n", result);

	char *benchmark = strdup("just a string:");
	printf("strdup: %s\n", benchmark);

	if (strcmp(result, benchmark) == 0)
		printf("the strings are the same according to strcmp\n");
	free(result);
	free(benchmark);
	return (0);
}

/*      The strdup() function allocates sufficient memory a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be
     used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

     The strndup() function copies at most n characters from the string s1 always NUL terminating the copied string. */