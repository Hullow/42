#include <stdio.h>
#include <unistd.h>
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, (str+i), 1);
		i++;
	}
//	write(1, "\n", 1);
}
/*
int	main(int argc, char **argv)
{
	if (argc > 0)
	ft_putstr(argv[1]);	
//	printf("Your string's characters are %s\n", ft_putstr(argv[1]));
	return (0);
}*/
