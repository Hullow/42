/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 18:20:58 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* Checks the death status variable to see if a philosopher died
	then sleep 0.5ms */
int	grim_reaper(t_table *table)
{
	while (1)
	{
		/* checking for deaths */
		if (pthread_mutex_lock(&table->death_status_mutex))
			return (print_error(MUTEX_LOCK_ERROR));
		if (table->death_status != 0)
		{
			printf("%ld A philosopher died – end of simulation\n", get_time_stamp()); /* write to stderr ? */
			if (pthread_mutex_unlock(&table->death_status_mutex))
				return (print_error(MUTEX_UNLOCK_ERROR));
			break ;
		}
		// else
		// 	printf("%ld\t\t***reaping***\n", get_time_stamp());
		if (pthread_mutex_unlock(&table->death_status_mutex))
			return (print_error(MUTEX_UNLOCK_ERROR));
	
		/* checking if finished eating */
		if (pthread_mutex_lock(&table->finished_eating_mutex))
			return (print_error(MUTEX_UNLOCK_ERROR));
		if (table->finished_eating == table->nb_philo)
		{
			printf("%ld All philosophers eat %d times - simulation stopping\n", get_time_stamp(), table->philos[0].must_eat); /* write to stderr ? */
			if (pthread_mutex_unlock(&table->finished_eating_mutex))
				return (print_error(MUTEX_UNLOCK_ERROR));
			break ;
		}
		else
		{
			// printf("%ld Philosophers have eaten %d times so far\n", get_time_stamp(), table->finished_eating);
			if (pthread_mutex_unlock(&table->finished_eating_mutex))
					return (print_error(MUTEX_UNLOCK_ERROR));
		}
		usleep(500); // check every 0.5 ms
	}
	return (0);
}

/* Runs the simulation by starting the philo threads and the checker thread */
int	run_simulation(t_table table)
{
	int	nb_philo;
	int	i;

	nb_philo = table.nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(table.philos[i].thread), NULL, \
		philo_routine, &table.philos[i]))
			return (print_error(THREAD_CREATION_ERROR)); // add error handling (pthread_join)
		i++;
	}
	pthread_create(&table.checker, NULL, checker_routine, table.philos);
	// printf("%ld exited routine\n", (long) pthread_self()); // remove
	// grim_reaper(&table);
	// printf("thread %ld: run simulation: when does this run?\n", (long) pthread_self());
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
	while (i < table->nb_philo)
	{
		// pthread_detach(table->philos[i].threasd);
		pthread_join(table->philos[i].thread, NULL); // add error handling
		i++;
	}
	pthread_join(table->checker, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		if (table->nb_philo)
			pthread_mutex_unlock(&table->fork_mutex[0]); // unlock mutex before destroying to prevent error if only one philo 
		if (pthread_mutex_destroy(&table->fork_mutex[i])) // add error handling
			return (print_error(MUTEX_DESTROY_ERROR));
		i++;
	}
	if (pthread_mutex_destroy(&table->death_status_mutex))
		return (print_error(MUTEX_DESTROY_ERROR));
	if (pthread_mutex_destroy(&table->finished_eating_mutex))
		return (print_error(MUTEX_DESTROY_ERROR));
	return (0);
}
