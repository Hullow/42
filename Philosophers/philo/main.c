/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/16 19:39:44 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	int			i;
	t_params	*params;
	t_table		table;

	params = malloc (sizeof(t_params));
	if (handle_input(params, argc, argv) == -1)
		return (-1);
	if (init_table(&table, params, params->nb_philo) == -1)
	{
		free(params);
		return (-1);
	}

	/* Grim reaper */
	while (1)
	{
		// lock global death mutex
		if (table->global_death_status == '1')
		{
			printf("A philosopher died – end of simulation\n");
			// unlock global death mutex
			break ;
		}
		// unlock global death mutex
		usleep(1000); // check every ms ?
	}

	/* End simulation */
	/* reap threads */
	i = 0;
	while(i < params->nb_philo)
	{
		pthread_join(&table.philos[i].thread, NULL); // add error handling
		i++;
	}

	/* destroy mutexes */
	i = 0;
	while(i < params->nb_philo)
	{
		pthread_mutex_destroy(&table.fork_mutex[i]); // add error handling
		i++;
	}
	/* destroy global mutex */

	/* need more error handling */
	free(params);
	return (0);
}
