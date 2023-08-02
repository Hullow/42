/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power - too powerful.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:07:04 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 18:55:26 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft(int nb, int power)
{
	int	result;
	int	i;

	i = 1;
	result = 1;
	while (i < power)
	{
		// nb = ft(nb, 1);
		result *= nb;
		i++;
	}
	return (result);
}

/* int	main(void)
{
	int	power = ft(2, 6);
	printf("%d\n", power);
	return (0);
} */








/* 	if (power < 0)
		
	if (power == 0)
		return (1); */