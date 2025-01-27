/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/27 17:40:56 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* checks if any philosopher is dead */
void	*checker_routine(void *vargp)
{
	t_philo			*philos;
	int				i;
	int				nb_philo;
	
	philos = (t_philo *)vargp;
	i = 0;
	nb_philo = philos[0].nb_philo;
	while (1)
	{
		while (i < nb_philo)
		{
			pthread_mutex_lock(&philos[i].last_eaten_mutex);
			if (get_time_stamp() - philos[i].last_eaten >= philos[i].time_to_die)
			{
				edit_status_var(&philos[i], philos[i].death_status_mutex, philos[i].death_status);
				pthread_mutex_unlock(&philos[i].last_eaten_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].last_eaten_mutex);
			i++;
			usleep(300);
		}
		i = 0;
	}
}

/* philosopher thread routine
Loop : eating, then sleeping
eat_return: if -1, means mutex error, if 1, means eat enough times */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;
	int		eat_return;
	long	timestamp;

	philo = (t_philo *)vargp;
	id = philo->philo_id;
	eat_return = 0;
	timestamp = get_time_stamp();
	print_status(philo, timestamp, MSG_THINKING);
	stagger_start(philo->nb_philo, id);
	while (1)
	{
        if (pthread_mutex_lock(philo->death_status_mutex))
            return NULL;
        if (*(philo->death_status) != 0)
        {
            pthread_mutex_unlock(philo->death_status_mutex);
            return NULL;
        }
        pthread_mutex_unlock(philo->death_status_mutex);
		if (attempt_take_fork(philo, LEFT) == -1)
			break ;
		if (attempt_take_fork(philo, RIGHT) == -1)
			break ;
		eat_return = attempt_to_eat(philo, id, philo->time_to_eat);
		if (eat_return == 1)
		{
			edit_status_var(philo, philo->finished_eating_mutex, philo->finished_eating);
			return (NULL);
		}
		else if (eat_return == -1) /* lock/unlock errors */
		{
			// error-mgmt
		}
	}
	// unlock_fork_mutexes(philo); /* necessary or not ??? */
	return (NULL);
}

/* Checks the death status variable to see if a philosopher died
	then sleep 0.5ms */
int	grim_reaper(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->death_status_mutex);
		if (table->death_status != 0)
		{
			printf("%ld A philosopher died – end of simulation\n", get_time_stamp()); /* write to stderr ? */
			pthread_mutex_unlock(&table->death_status_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->death_status_mutex);
		pthread_mutex_lock(&table->finished_eating_mutex);
		if (table->finished_eating == table->nb_philo)
		{
			printf("%ld All philosophers eat %d times - simulation stopping\n", get_time_stamp(), table->philos[0].must_eat); /* write to stderr ? */
			pthread_mutex_unlock(&table->finished_eating_mutex);
			break ;
		}
		else pthread_mutex_unlock(&table->finished_eating_mutex);
		usleep(500);
	}
	return (0);
}

/* Runs the simulation by starting the philo threads and the checker thread */
int	run_simulation(t_table *table)
{
	int	nb_philo;
	int	i;

	nb_philo = table->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(table->philos[i].thread), NULL, \
		philo_routine, &table->philos[i]))
			return (print_error(THREAD_CREATION_ERROR)); // add error handling (pthread_join)
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
	pthread_mutex_lock(&table->finished_eating_mutex);
	if (!table->finished_eating)
	{
		pthread_mutex_unlock(&table->finished_eating_mutex);
		while (i < table->nb_philo)
		{
			// pthread_detach(table->philos[i].threasd);
			pthread_join(table->philos[i].thread, NULL); // add error handling
			i++;
		}
	}
	pthread_mutex_unlock(&table->finished_eating_mutex);
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
	// pthread_mutex_unlock(&table->finished_eating_mutex);
	pthread_mutex_destroy(&table->finished_eating_mutex);
	return (0);
}
