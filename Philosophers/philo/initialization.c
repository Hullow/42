/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/07 18:44:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// initializes forks as an array of integers filled with '0' (not used)
void	*initialize_forks(int nb_philo)
{
	int	*forks;
	int	i;

	forks = malloc(nb_philo * sizeof(int));
	if (!forks)
	{
		handle_error(MALLOC_FAIL);
		return (NULL);
	}
	memset(forks, '0', nb_philo);
	return (forks);
}

// fills the philosopher struct with our parameters from input
void	fill_params(struct s_philo	*philo, int **forks, struct s_params *params, int philo_id)
{
	philo->forks = *forks;
	philo->philo_id = philo_id;
	philo->must_eat_times = params->must_eat_times;
	philo->tt_die = params->tt_die;
	philo->tt_eat = params->tt_eat;
	philo->tt_sleep = params->tt_sleep;
	philo->last_eaten = get_time_stamp();
}

// initializes table:
// calls initialize_forks first
// then creates the philosophers thread with all the parameters
int	initialize_table(struct s_params *params)
{
	int				nb_philo;
	int*			forks;
	pthread_t		philo_thread[params->nb_philo];
	pthread_mutex_t	fork[params->nb_philo];
	struct s_philo	*philo[params->nb_philo];

	nb_philo = params->nb_philo;
	forks =	initialize_forks(nb_philo);
	if (!forks)
		return (-1);
	while (nb_philo)
	{
		philo[nb_philo] = (struct s_philo *)malloc(sizeof(struct s_philo));
		fill_params(philo[nb_philo], &forks, params, nb_philo);
		pthread_create(&(philo_thread[nb_philo]), NULL, philo_routine, (void *) philo[nb_philo]);
		philo[nb_philo]->thread_id = philo_thread[nb_philo];
		nb_philo--;
	}
	nb_philo = params->nb_philo;
	while (nb_philo)
	{
		if (pthread_mutex_init(&fork[nb_philo], NULL))
			handle_error(MUTEX_INIT_ERROR);
		nb_philo--;
	}
	// need to add error handling
	return (0);
}

// philosopher thread initialization routine
void	*philo_routine(void *vargp)
{
	struct s_philo	*philo;
	long			timestamp;

	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (NULL);
	philo = (struct s_philo *)vargp;
	printf("%ld Philosopher %d is thinking\n", timestamp, philo->philo_id);
	while (check_if_alive(philo))
		usleep(10);
	return (NULL);
}