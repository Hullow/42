#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	j;
	tab = (int*) malloc((max - min) * sizeof(int));
	i = min;
	j = min;	
	while (i < max)
	{
		tab[i] = i
	}	

	return(tab)
}
