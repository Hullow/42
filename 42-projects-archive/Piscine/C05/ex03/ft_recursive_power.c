/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:07:04 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 18:55:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power > 0)
			nb *= ft_recursive_power(nb, power-1);
		return (nb);
	}
}

/* int	main(void)
{
	int	power = ft_recursive_power(10, 4);
	printf("%d\n", power);
	return (0);
} */