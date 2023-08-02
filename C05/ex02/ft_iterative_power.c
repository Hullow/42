/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:36:28 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 16:39:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	if (power < 0)
		return (0);
	else
	{
		i = 1;
		result = 1;
		while (i <= power)
		{
			result *= nb;
			i++;
		}
		return (result);
	}
}

/* int	main(void)
{
	int	power = ft_iterative_power(2, 1);
	printf("%d\n", power);
	return (0);
} */