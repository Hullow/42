#include <stdio.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen] != 0)
		strlen++;
	return(strlen);
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		printf("Your string has %d characters\n", ft_strlen(argv[1]));
	return (0);
} */
