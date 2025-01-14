/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/14 17:21:35 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// initializes forks as an array of integers filled with '0' (not used)
void	*initialize_forks(int nb_philo)
{
	int	*forks;

	forks = malloc(nb_philo * sizeof(int));
	if (!forks)
	{
		print_error(MALLOC_FAIL);
		return (NULL);
	}
	memset(forks, '0', nb_philo);
	return (forks);
}

// fills the philosopher struct with our parameters from input
void	fill_params(t_philo	*philo, t_params *params, int id)
{
	philo->philo_id = id;
	philo->must_eat = params->must_eat;
	philo->tt_die = params->tt_die;
	philo->tt_eat = params->tt_eat;
	philo->tt_sleep = params->tt_sleep;
	philo->last_eaten = get_time_stamp();
}

/* 
> Upon successful completion pthread_create() will store the
ID of the created thread in the location specified by thread.
	 
In my words: 
pthread_t *thread is a pointer that specifies a location. In that location, the ID of the created
thread will be stored to get the ID you'll have to dereference [pthread_t *thread] using [*thread] */

int	initialize_philos(t_table *table, int nb_philo, int i, t_params *params)
{
	t_philo	*philo[MAX_THREADS];

	while (i < nb_philo)
	{
		philo[i] = (t_philo *) malloc(sizeof(t_philo));
		if (!philo[i])
		{
			while (--i > 0)
				free(philo[i]->thread);
			free(philo[i]);
			return (1);
		}
		philo[i]->thread = (pthread_t *) malloc(sizeof(pthread_t));
		if (!philo[i]->thread)
		{
			free(philo[i]);
			while (--i > 0)
			{
				free(philo[i]->thread);
				free(philo[i]);
			}
			return (1);
		}
		fill_params(philo[i], params, i);
		i++;
	}
	return (0);
}

pthread_mutex_t	**initialize_mutexes(int nb_philo, int i, pthread_mutex_t ***fork_mutexes)
{
	(*fork_mutexes) = (pthread_mutex_t **) malloc(sizeof(pthread_mutex_t *) * nb_philo);
	if (!(*fork_mutexes))
	{
		print_error(MALLOC_FAIL);
		return (NULL);
	}
	while (++i < nb_philo)
	{
		(*fork_mutexes)[i] = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
		if (!(*fork_mutexes)[i])
		{
			while (--i)
				free((*fork_mutexes)[i]);
			free((*fork_mutexes));
			print_error(MALLOC_FAIL);
			return (NULL);
		}
	}
	while (nb_philo)
	{
		if (pthread_mutex_init((*fork_mutexes)[nb_philo], NULL))
		{
			print_error(MUTEX_INIT_ERROR);
			// free ?
			// return ?
		}
		nb_philo--;
	}
	return (*fork_mutexes);
}

// initializes table:
// calls initialize_forks first
// then creates the philosophers thread with all the parameters
int	init_table(t_table *table, t_params *params)
{
	int				nb_philo;
	int				*forks;

	t_philo			*philo[params->nb_philo];
	pthread_mutex_t	*fork_mutexes[params->nb_philo];

	nb_philo = params->nb_philo;

	/* Initialize forks */
	forks =	initialize_forks(nb_philo);
	if (!forks)
		return (-1);
	
	/* Initialize mutexes */
	fork_mutexes = initialize_mutexes(nb_philo, -1, &fork_mutexes);
	if (!fork_mutexes)
	{
		free(forks);
		return (-1);
	}

	/* Initialize philosophers */
	philo = ;
	if (initialize_philos(nb_philo, 0))
	{
		free(forks);
		free(fork_mutexes); // ft_free mutexes up to a certain point i
		return (-1);
	}

	/* Initialize table */
	table = (t_table *) malloc(sizeof(table));
	if (!table)
	{
		free(forks);
		free(fork_mutexes); // ft_free mutexes up to a certain point i
		free(philo); // free philos and threads inside up to a certain point i
		return (print_error(MALLOC_FAIL));
	}
	table->forks = forks;
	table->fork_mutexes = fork_mutexes;
	table->philos = philo;
	table->nb_philo = params->nb_philo;

	/* Starting philosopher threads */
	while (nb_philo)
	{
		table->table_id = nb_philo; // data race ?
		if (pthread_create(table->philos[nb_philo]->thread, NULL, philo_routine, (void *) table))
		{
			// free everything
			print_error(THREAD_CREATION_ERROR);
		}
		nb_philo--;
	}

	/* error handling */
	return (0);
}

// philosopher thread initialization routine
void	*philo_routine(void *vargp)
{
	t_table			*table;
	long			timestamp;
	int				id;

	/* Initialization */
	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (NULL);
	table = (t_table *)vargp;
	id = table->table_id;

	/* Thinking */
	printf("%ld Philosopher %d is thinking\n", timestamp, table->philos[id]->philo_id);
	
	/* Check if alive every 10 ms */
	while (check_if_alive(table->philos))
		usleep(10000);

	/* Even number of philosophers */
	if (table->nb_philo % 2)
	{
		if (table->table_id % 2) // if uneven
			usleep(5000); // sleep 5 ms
		printf("%ld Philosopher %d is thinking\n", timestamp, table->philos[id]->philo_id);

		pthread_mutex_lock(table->fork_mutexes[id]);
		table->forks[id] = '1';
		pthread_mutex_unlock(table->fork_mutexes[id]);
		
	}

	return (NULL);
}
