#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	unsigned int	i;

	str = malloc(len * sizeof(char));
		if (str)
		{
			i = 0;
			while (s[start] && len > 0)
			{
				str[i] = s[start];
				start++;
				i++;
				len--;
			}
		}
			return (str);
}

#include <stdio.h>
int	main()
{
	char s[] = "blabloble";
	unsigned int start = 3;
	size_t len = 3;

	printf("ft_substr, operating on '%s' at address '%p' with parameters start = %d and len = %zu, yields string '%s' at address '%p'\n", s, s, start, len, ft_substr(s, start, len), ft_substr(s, start, len));
	return (0);
}