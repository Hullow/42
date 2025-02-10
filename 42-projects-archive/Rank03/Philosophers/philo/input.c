/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/30 16:07:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 *	@brief	custom atoi to convert our input to int type
 *  @returns 	(positive) int if valid
 * 				-1 if negative number or any invalid characters
*/
int	ft_atoi_philo(char *str)
{
	int	out;
	int	i;

	if (str[0] == '-')
		return (-1);
	out = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (out)
			out *= 10;
		out += (int) str[i] - 48;
		i++;
	}
	return (out);
}

int	handle_must_eat_input(t_table *table, char **argv)
{
	if (argv[5])
	{
		table->must_eat = ft_atoi_philo(argv[5]);
		if (table->must_eat < 0)
			return (print_error(INVALID_INPUT));
	}
	else
		table->must_eat = -1;
	return (0);
}

// Stores the input parameters in a the s_table struct
// returns -1 if parameter count is not 4 or 5
// returns 0 otherwise
int	handle_input(t_table *table, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n");
		printf("1) number of philosophers\n2) time to die\n");
		printf("3) time to eat\n4) time to sleep\n");
		printf("5) number of times each philosopher must eat (optional)\n");
		return (print_error(INVALID_INPUT));
	}
	if (handle_must_eat_input(table, argv))
		return (-1);
	table->nb_philo = ft_atoi_philo(argv[1]);
	table->time_to_die = ft_atoi_philo(argv[2]);
	table->time_to_eat = ft_atoi_philo(argv[3]);
	table->time_to_sleep = ft_atoi_philo(argv[4]);
	if (table->nb_philo < 0 || table->time_to_die < 0 || \
	table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (print_error(INVALID_INPUT));
	if (table->nb_philo == 0 || table->time_to_die == 0 || \
	table->time_to_eat == 0 || table->time_to_sleep == 0 || \
	table->must_eat == 0)
		return (print_error(ZERO_AS_INPUT));
	return (0);
}
