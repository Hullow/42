/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:51:46 by francis           #+#    #+#             */
/*   Updated: 2025/01/29 19:23:42 by francis          ###   ########.fr       */
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
	return (0);
}

/* End simulation :
	- join threads (philos, checker) to reap them 
	- destroy mutexes
*/
int	end_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->checker, NULL);
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->fork_mutexes[i]);
		pthread_mutex_destroy(&table->philos[i].last_eaten_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->done_eating_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	return (0);
}
