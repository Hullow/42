#include <stdlib.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
		factorial = 1;
		factorial *= nb-1;
		nb = (nb-i);
		while (i > 0)
		ft_recursive_factorial(nb);
	return (factorial);
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		{
			printf("The factorial is: %d\n", ft_recursive_factorial(atoi(argv[1])));
		}
	return (0);
}