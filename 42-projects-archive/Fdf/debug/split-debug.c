#include "../lib/libft/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include <stdio.h>

int main()
{
	char *test = "0 0 0 0 0 1 2 3 4 5 6 7 7          7                    7                7 6 5 4 3 2 1 0 0 0 0 0";
	char **split = ft_split(test, ' ');
	int i = 0;
	while (split[i])
	{
		printf("split[%d]: %s  |", i, split[i]);
		i++;
	}

	return (0);
}