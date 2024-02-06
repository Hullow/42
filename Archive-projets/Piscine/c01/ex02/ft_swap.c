#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;
	
	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int	i;
	int	j;

	i = 49;
	j = 55;
	printf("Before swapping, the values of i and j are %d and %d.\n", i, j);
	ft_swap(&i, &j);
	printf("After swapping, the values of i and j are %d and %d", i, j);
	return (0);
}
