/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:15:23 by fallan            #+#    #+#             */
/*   Updated: 2023/11/16 17:17:10 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int	remove_whitespaces(char *str, int i)
{
	while (str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == \
	'\v' | str[i] == '\f' | str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	i = remove_whitespaces(str, i);
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && nb >= 0) //  && nb > 0 => solves >INT_MAX problem but creates another problem
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	// if (nb >= 2147483647)
	// 	return (0);
	return (sign * nb);
}

#include <unistd.h>
#include <stdlib.h>
int	test(int number, char *str)
{
	int result1 = ft_atoi(str);
	int result2 = atoi(str);

	if (result1 == result2)
		printf("test %d OK: same return '%d'\n", number, result2);
	else
		printf("test %d KO: atoi returns '%d', \
		ft_atoi returns '%d'\n", number, result2, result1);
	return (0);
}

int	main(void)
{
	// test(1, "123456");
	// test(2, "-123456");
	// test(3, "123456abcde");
	// test(4, "abcde123456");
	// test(5, "123456abcde123456");
	test(6, "  +000456abcde----");
	test(7, "  -000456393939393939393939393abc55554de     ");
	test(8, "  -000456abc55554de     ");
	return (0);
}
