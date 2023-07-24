/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:58:30 by fallan            #+#    #+#             */
/*   Updated: 2023/07/24 20:58:39 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	i;
	int	*nbr;

	nbr = &i;
	ft_ft(nbr);
	printf("This is not a drill: %d\n", i);
	i += 48;
	write(1, &i, 1);

	int t = 90;
	write(1, &t, 1);
	return (0);
}
