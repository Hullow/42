/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:26 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 19:10:27 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		{
			printf("The factorial is: %d\n", ft_iterative_factorial(atoi(argv[1])));
		}
	return (0);
} */