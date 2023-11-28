#include<stdio.h>
#include<stdlib.h>

static int nbr_of_digits(n)
{
	int i;
	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while(n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void _itoa(char *memory, int n)
{
	if (n > 9)
	{
		_itoa(memory, n / 10);
	}
	*memory = (n % 10) + '0';
	printf("memory : %s\n", memory);
	printf("adress : %p\n", memory);
	memory++;
}

char *ft_itoa(int n)
{
	int size;
	char *memory;

	size = nbr_of_digits(n);
	printf("SIZE %i\n", size);

	memory = (char *)malloc(size + 1);
	_itoa(memory, n);
	memory[size] = 0;
	return memory;
}

int main()
{
	char *str = ft_itoa(113001);
	printf("> %s",str);
}