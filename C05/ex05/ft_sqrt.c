#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	half;
	unsigned int	start;
	unsigned int	end;
	unsigned int	mid;

	nb = end;
	i = 0;
	if (nb < 0 || nb % 10 == 2 || nb % 10 == 3 || nb % 10 == 7 || nb % 10 == 8)
		return (0);

	mid = nb / 2;
	
	start = 0;

	if ((start + end / 2) > ())

	else
	{
		while (i < half)
		{
			i++;
			if (i*i == (unsigned int) nb)
				return (i);
			else
				return (0);
		}
		else return (0);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		printf("%d\n", ft_sqrt(atoi(argv[1])));
	else
		return (0);
}