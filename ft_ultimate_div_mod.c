#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int	main(void)
{
	int	i;
	int	j;

	i = 26;
	j = 5;

	int *a;
	a = &i;
	int *b;
	b = &j;

	ft_ultimate_div_mod(a, b);
	printf("The division is %d and the module is %d.\n", i, j);
	return (0);
}

//nb: if the function call were ft_ultimate_div_mod(&a, &b);
it would pass the addresses of the pointers themselves, not the addresses of the values we want to manipulate (i and j)
