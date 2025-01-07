/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:05 by francis           #+#    #+#             */
/*   Updated: 2024/12/27 12:11:04 by francis          ###   ########.fr       */
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
int	handle_input(struct s_params params, int argc, char **argv)
{
	if (argc < 5 || argv > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n");
		free(params);
		return (-1);
	}
	params.nb_philo = ft_atoi(argv[1]);
	params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]);
	params.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params.nb_times_philos_must_eat = ft_atoi(argv[5]);
	return (0);
}
