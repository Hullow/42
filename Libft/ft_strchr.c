// To do: test edge cases like null string, null characters etc


char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		else
			ptr++;
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
int	main()
{
	char	string[4];
	int		character = 0;

	strcpy(string, "abc");
	printf("For string \"%s\" and character \"%c\", strchr produces the string: \"%s\"\n", string, character, strchr(string, character));
	printf("For string \"%s\" and character \"%c\", ft_strchr produces the string: \"%s\"\n", string, character, ft_strchr(string, character));
	return (0);
}