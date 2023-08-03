/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:42:25 by fallan            #+#    #+#             */
/*   Updated: 2023/08/03 23:55:40 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	else
	{
		tab = malloc((max - min) * sizeof(int));
		if (tab == NULL)
			return (0);
		i = 0;
		while (min + i < max)
		{
			tab[i] = min + i;
			i++;
		}
		return (tab);
	}
}

/* int	main()
{
	int	i = 0;
	int	*tab;
	tab = ft_range(10, 20);
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