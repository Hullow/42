/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:33:59 by fallan            #+#    #+#             */
/*   Updated: 2023/07/30 22:46:56 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		i;
	int		d;
	int		temp;
	char	*str[11];

	i = 0;
	d = 0;
	temp = nb;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{	
		if (nb < 0)
		{
			nb *= (-1);
			write(1, "-", 1);
		}
		while (temp != 0)
		{
		temp /= 10;
		d++;
		}
		while (i < d)
		{
	str[d - i - 1] = (nb % 10) + 48;
	nb /= 10;
	i++;
		}
	i = 0;
		while (i <= d)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
/*
int	main(int argc, char **argv)
{
	int	nb;
	if (argc > 0)
	{
	nb = atoi(argv[1]);
	ft_putnbr(nb);
	}
	return (0);
} */
