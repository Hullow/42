#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	len;

	len = 0;
	while (s1[len])
		len++;
	str = malloc(len * sizeof(char));
	while (len > 0)
	{
		str[len - 1] = s1[len - 1];
		len--;
	}
	return (str);
}

int	main()
{
	char	s1[] = "blablabla";

	printf("strdup copies the string s1: '%s' at address '%p' to the string str '%s' at address '%p'\n", s1, s1, strdup(s1), strdup(s1));
	//printf("ft_strdup copies the string s1: '%s' at address '%p' to the string str '%s' at address '%p'\n", s1, s1, ft_strdup(s1), ft_strdup(s1));
	
	return (0);
}