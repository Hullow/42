/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:15:23 by fallan            #+#    #+#             */
/*   Updated: 2023/07/31 21:16:33 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str);

/* int	main(void)
{
	int	nb;

	nb = ft_atoi("  ++-000456abcde");
	printf("The number is : %d\n", nb);
	return (0);
} */

int	ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == \
	'\v' | str[i] == '\f' | str[i] == '\r')
		i++;
	while (str[i] == '+' | str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
	nb *= 10;
	nb += str[i] -48;
	i++;
	}
	return (sign * nb);
}
