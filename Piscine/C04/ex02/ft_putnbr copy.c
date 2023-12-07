/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:28:46 by fallan            #+#    #+#             */
/*   Updated: 2023/07/31 21:21:56 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
		nb *= (-1);
			write(1, "-", 1);
		}
		if (nb >= 0 && nb <= 9)
		{
		nb += 48;
			write(1, &nb, 1);
		nb -= 48;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_putnbr(atoi(argv[1]));
	return (0);
} */