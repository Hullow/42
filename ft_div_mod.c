#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
	*div = (a / b);
	}
	else *div = 0;
	*mod = (a % b); 
}


int	main(void)
{

	int result_div;
	int result_mod;
	ft_div_mod(11, 2, &result_div, &result_mod);
	printf("The result is division = %d and modulo = %d", result_div, result_mod);
	result_div += 48;
	write(1, &result_div, 1); //doesn't output anything
//	write(1, &(*mod), 1);

	return (0);
}
