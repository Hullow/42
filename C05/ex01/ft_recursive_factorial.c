/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:34 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 19:10:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		if (nb > 1)
			nb *= ft_recursive_factorial(nb-1);
	return(nb);
	}
}

/* int	main(void)
{
	printf("%d\n", ft_recursive_factorial(5));
	return (0);
} */

/* #include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 0)
	printf("The factorial is: %d\n", ft_recursive_factorial(atoi(argv[1])));
	return (0);
} */