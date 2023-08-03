#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = (int*) malloc((max - min) * sizeof(int));
		if (*range == NULL)
			return (-1);
		i = 0;
		while (i < max - min)
		{
			range[0][i] = min + i;
			i++;
		}
		return (max - min);
	}
}

/* int	main()
{
	int	i = 0;
	int	*tab;
	tab = ft_ultimate_range(10, 20);
	printf("%d\n", tab[0]);
		while (tab[i] >= 10 && tab[i] <= 19)
		{
			printf("%d ", tab[i]);
			i++;
		}
		printf("\n");
		free(tab);
	return (0);
} */

/* int	main(int argc, char **argv)
{
	int	i = 0;
	int	*tab;
	if (argc == 3)
	{
		tab = ft_ultimate_range(atoi(argv[1]), atoi(argv[2]));
		while (tab[i] >= (atoi(argv[1])) && tab[i] <= ((atoi(argv[2]) - 1)))
		{
			printf("%d ", tab[i]);
			i++;
		}
		printf("\n");
	}
	else
	{	
		printf("wrong input");
		return (0);
	}
	free(tab);
} */

