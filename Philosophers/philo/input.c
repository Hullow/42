/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:05 by francis           #+#    #+#             */
/*   Updated: 2025/01/07 17:57:40 by fallan           ###   ########.fr       */
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

int	handle_error(int error)
{
	if (error == THREAD_CREATION_ERROR)
		write(2, "Thread creation error", 22);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Mutex init error", 17);
	return (-1);
}

// Stores the input parameters in a the s_params struct
// returns -1 if parameter count is not 4 or 5
// returns 0 otherwise
int	handle_input(struct s_params *params, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n");
		free(params);
		return (-1);
	}
	params->nb_philo = ft_atoi(argv[1]);
	params->tt_die = ft_atoi(argv[2]);
	params->tt_eat = ft_atoi(argv[3]);
	params->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->must_eat_times = ft_atoi(argv[5]);
	return (0);
}
