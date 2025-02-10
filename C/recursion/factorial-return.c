#include <stdio.h>
#include <stdlib.h>

int	factorial(int a)
{
	if (a == 0)
		return (1);
	else
		return (a * factorial (a - 1));
}

int main(int argc, char **argv)
{
	int	a;
	if (argc != 2)
		return (0);
	a = atoi(argv[1]);
	if (a < 0)
		return(printf("sorry, your input %d is negative. not taking negative input for a factorial. abort\n", a));
	printf("factorial(%d): %d\n", a, factorial(a));
	return (0);
}