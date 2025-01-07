/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2024/12/27 12:11:21 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Structure to store the input parameters
struct s_params
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_times_philos_must_eat;
}

// Input
int	handle_input(struct s_params params, int argc, char **argv);
int	ft_atoi(char *str);