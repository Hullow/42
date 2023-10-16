char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	while (i > 0)
	{
		if (*ptr == c)
			return (ptr);
		else
		{
			ptr--;
			i--;
		}
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
int	main()
{
	char	string[30];
	int		character = 75;

	strcpy(string, "King Charles is Kong");
	printf("For string \"%s\" and character \"%c\", strrchr produces the string: \"%s\"\n", string, character, strrchr(string, character));
	printf("For string \"%s\" and character \"%c\", ft_strrchr produces the string: \"%s\"\n", string, character, ft_strrchr(string, character));
	return (0);
}