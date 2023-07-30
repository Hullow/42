#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str);
/*
int	main(void)
{
	int	nb;

	nb = ft_atoi("  ++---000456");
	printf("The number is : %d\n", nb);
	return (0);
}
*/
int	ft_atoi(char *str)
{
	int	nb;
	int	i; 
	int	j;
	int	minus;
	int	decimal;
	char	integer[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	i = 0;

// Whitespace
 	while (str[i] != 0 && (str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == '\v' | str[i] == '\f' | str[i] == '\r'))
		i++;

// Sign: go through '+' and '-' and increment minus for each '-'
	minus = 0;
	while (str[i] != 0 && (str[i] == '+' | str[i] == '-'))
	{
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			minus++;
			i++;
		}
	}

// Fill up integer[j]
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
	integer[j] = str[i];
	j++;
	i++;
	}
//	printf("j is : %d\n", j);

// Assign value to nb from integer[i] in an iterative way, adding smallest numbers, then each multiple of ten
	decimal = 1;
	nb = decimal - 1;

	while (j >= 0 && integer[j-1] >= '0' && integer[j-1] <= '9')
	{
//	printf("nb is currently: %d, to which we will add: %d times %d\n", nb, integer[j-1]-48, decimal);
	nb += ((integer[j-1]-48)*decimal); 
	decimal*=10;
	j--;
	}

	if (minus % 2 == 1)
		nb *= (-1);
	return(nb);
}
