/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bravnar <bravnar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:33:06 by bravnar           #+#    #+#             */
/*   Updated: 2023/08/09 21:34:19 by bravnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_count(int nbr)

{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count++;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int nbr)
{
	int	str_len;
	char *output;
	int is_neg;

	str_len = ft_count(nbr);
	is_neg = 0;
	output = malloc(sizeof(char) * (str_len + 1));
	if (!output)
		output = NULL;
	if (nbr < 0)
	{
		output[0] = '-';
		is_neg = 1;
	}
	output[str_len--] = '\0';
	while (str_len >= is_neg)
	{
		output[str_len--] = (ft_abs(nbr % 10) + '0');
		nbr /= 10;
	}
	return (output);
}

int main(int ac, char **av)
{
	if (ac == 2)
		printf("The printed string is %s\n", ft_itoa(atoi(av[1])));
	return (0);
}
