#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	i; 
	int	j;
	int	minus;
	int	decimal;
	char	integer[] = {9, 9, 9, 4, 5, 6, 7, 8, 9};

	printf("integer[4] is worth: %c", integer[4]+48);
	write(1, &integer[4]+48, 1);
	printf("\n");


	i = 0;

/*	while (str[i] != 0)
	{i++;}
	i--; */

	// Whitespace
 	while (str[i] != 0 && (str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == '\v' | str[i] == '\f' | str[i] == '\r'))
		i++;
//includes the following standard characters:
////////////////     ``\t''``\n''``\v''``\f''``\r''`` ''
/*	nb = str[i] - 48;
	write(1, &str[i],1);
	printf("We are at character %c, the %d-th character.\n", str[i], i+1);
	printf("Output number is %d.\n", nb);
*/
	// Sign
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
	
	if (minus % 2 == 1)
		write(1, "-", 1);
// fill up integer[j]
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
	integer[j] = str[i] + 48;
	j++;
	i++;
	}
	printf("j is : %d\n", j);
//	printf("Our int array is composed of:");
	i = 0;
	while (integer[i] != 0)
	{
		write(1, &integer[i], 1);
		i++;
	}


	decimal = 1;
	nb = decimal - 1;
	while (j >= 0)
	{
	nb += ((integer[j-1])*decimal); 
	decimal*=10;	
	j--;
	}
	printf("The result int is : %d\n", nb);
	write(1, &nb, 4);
/*  COMMENT

	decimal = 1;
	nb = 0;
	while (j >= 0)
	{
	integer[j-1] += 0;
	printf("Adding this: %d\n", integer[j-1]); 
	nb += (integer[j-1]+48) * decimal;
	decimal *= 10;
	j--;
	}
*/
	return(nb);
}

int	main(void)
{

	ft_atoi("    ++---456");
/*
	int	nb;

	nb = ft_atoi("  ++-456");
	printf("The number is : %d\n", nb);
*/	return (0);
}
