/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/24 11:09:08 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	grim_reaper(t_table *table)
{
	while (1)
	{
		if (pthread_mutex_lock(&table->global_death_mutex))
		{
			print_error(MUTEX_LOCK_ERROR);
			return (-1);
		}
		if (table->death_status == '1')
		{
			printf("%ld ms: A philosopher died – end of simulation\n", get_time_stamp()); /* write to stderr ? */
			if (pthread_mutex_unlock(&table->global_death_mutex))
			{
				print_error(MUTEX_UNLOCK_ERROR);
				return (-1);
			}
			break ;
		}
		if (pthread_mutex_unlock(&table->global_death_mutex))
		{
			print_error(MUTEX_UNLOCK_ERROR);
			return (-1);
		}
		usleep(50); // check every 0.5 ms
	}
	return (0);
}

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
	grim_reaper(&table);

	/* End simulation */
	/* reap threads */
	// i = 0;
	// while(i < params->nb_philo)
	// {
	// 	pthread_join(table.philos[i].thread, NULL); // add error handling
	// 	i++;
	// }

	/* destroy mutexes */
	i = 0;
	while(i < params->nb_philo)
	{
		if (pthread_mutex_destroy(&table.fork_mutex[i])) // add error handling
			print_error(MUTEX_DESTROY_ERROR);
		i++;
	}
	if (pthread_mutex_destroy(&table.global_death_mutex))
		print_error(MUTEX_DESTROY_ERROR);

	/* need more error handling */
	free(params);
	return (0);
}
