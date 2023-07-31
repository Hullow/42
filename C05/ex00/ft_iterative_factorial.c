#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		{
			printf("The factorial is: %d\n", ft_iterative_factorial(atoi(argv[1])));
		}
	return (0);
} */