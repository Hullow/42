/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/25 17:20:09 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_table		table;

	// printf("main thread: %ld\n", (long) pthread_self());
	if (handle_input(&params, argc, argv) == -1)
		return (-1);
	/* Initialization of table: philosophers, forks, mutexes */
	if (init_table(&table, &params, params.nb_philo) == -1)
		return (-1);
	/* Running the simulation */
	if (run_simulation(table) == -1)
	{
		end_simulation(table);
		return (-1);
	}
	grim_reaper(&table);
	end_simulation(table); /* need more error handling */
	return (0);
}
