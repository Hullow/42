/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:05 by francis           #+#    #+#             */
/*   Updated: 2025/01/27 20:34:02 by francis          ###   ########.fr       */
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

/**
 * @brief	Checks the validity of the input parameters
 * @details	Cases:
 * 				- a parameter is < 0 or == 0
 * 			To determine:
 * 				- a parameter is > INT_MAX => will be negative
 * 				- INT_MAX likely works, just a very long time
 * @returns	returns a call (with error number) to print_error, which returns -1
 * */
int	input_checker(t_params *params)
{
	if (params->nb_philo < 0 || params->time_to_die < 0 || \
	params->time_to_eat < 0 || params->time_to_sleep < 0)
		return (print_error(INVALID_INPUT));
	if (params->nb_philo == 0 || params->time_to_die == 0 || \
	params->time_to_eat == 0 || params->time_to_sleep == 0 || \
	params->must_eat == 0)
		return (print_error(ZERO_AS_INPUT));
	return (0);
}

// Stores the input parameters in a the s_params struct
// returns -1 if parameter count is not 4 or 5
// returns 0 otherwise
int	handle_input(t_params *params, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n");
		printf("1) number of philosophers\n2) time to die\n");
		printf("3) time to eat\n4) time to sleep\n");
		printf("5) number of times each philosopher must eat (optional)\n");
		return (print_error(INVALID_INPUT));
	}
	if (argv[5])
		params->must_eat = ft_atoi_philo(argv[5]);
	else
		params->must_eat = -1;
	params->nb_philo = ft_atoi_philo(argv[1]);
	params->time_to_die = ft_atoi_philo(argv[2]);
	params->time_to_eat = ft_atoi_philo(argv[3]);
	params->time_to_sleep = ft_atoi_philo(argv[4]);
	return (input_checker(params));
}
