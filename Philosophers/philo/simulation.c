/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:51:46 by francis           #+#    #+#             */
/*   Updated: 2025/01/27 20:51:57 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* Runs the simulation by starting the philo threads and the checker thread */
int	run_simulation(t_table *table)
{
	int	nb_philo;
	int	i;

	nb_philo = table->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		pthread_create(&(table->philos[i].thread), NULL, \
		philo_routine, &table->philos[i]);
		i++;
	}
	pthread_create(&table->checker, NULL, checker_routine, table->philos);
	// grim_reaper(&table);
	return (0);
}

/* End simulation :
	- join threads (philos, checker) to reap them 
	- destroy mutexes
	- ?
*/
int	end_simulation(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->done_eating_mutex);
	if (!table->done_eating)
	{
		pthread_mutex_unlock(&table->done_eating_mutex);
		while (i < table->nb_philo)
		{
			// pthread_detach(table->philos[i].threasd);
			pthread_join(table->philos[i].thread, NULL); // add error handling
			i++;
		}
	}
	pthread_mutex_unlock(&table->done_eating_mutex);
	pthread_join(table->checker, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		// if (table->nb_philo)
			// pthread_mutex_unlock(&table->fork_mutex[0]); // unlock mutex before destroying to prevent error if only one philo 
		pthread_mutex_destroy(&table->fork_mutex[i]);
		i++;
	}
	// pthread_mutex_unlock(&table->death_status_mutex);
	pthread_mutex_destroy(&table->death_status_mutex);
	// pthread_mutex_unlock(&table->done_eating_mutex);
	pthread_mutex_destroy(&table->done_eating_mutex);
	return (0);
}
