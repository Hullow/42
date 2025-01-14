/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:05 by francis           #+#    #+#             */
/*   Updated: 2025/01/14 17:11:13 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// homemade atoi to convert our input to int type
int	ft_atoi(char *str)
{
	int	out;
	int	sign;
	int	i;

	out = 0;
	if (str[0] == '-')
		sign = 1;
	else
		sign = 0;
	i = sign;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (out);
		if (out)
			out *= 10;
		out += (int) str[i] - 48;
		i++;
	}
	if (sign)
		out *= -1;
	return (out);
}

// Stores the input parameters in a the s_params struct
// returns -1 if parameter count is not 4 or 5
// returns 0 otherwise
int	handle_input(t_params *params, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n"); // replace with write
		free(params);
		return (-1);
	}
	params->nb_philo = ft_atoi(argv[1]);
	params->tt_die = ft_atoi(argv[2]);
	params->tt_eat = ft_atoi(argv[3]);
	params->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->must_eat = ft_atoi(argv[5]);
	if (params->nb_philo > 200)
	{
		printf("Philosophers – number of philosophers too high: must be <= 200\n"); // replace with write
		free(params);
		return (-1);
	}
	return (0);
}
