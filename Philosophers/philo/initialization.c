/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/28 21:03:06 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 *	@brief	custom atoi to convert our input to int type
 *  @returns 	(positive) int if valid
 * 				-1 if negative number or any invalid characters
*/
int	ft_atoi_philo(char *str)
{
	int	out;
	int	i;

	if (str[0] == '-')
		return (-1);
	out = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (out)
			out *= 10;
		out += (int) str[i] - 48;
		i++;
	}
	return (out);
}

void	fill_philo_params(t_philo *philo, t_table **table, int id)
{
	int	nb_philo;

	nb_philo = (*table)->nb_philo;
	philo->philo_id = id + 1;
	philo->nb_philo = nb_philo;
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;
	philo->time_to_die = (long)(*table)->time_to_die;
	philo->time_to_eat = (long)(*table)->time_to_eat;
	philo->time_to_sleep = (long)(*table)->time_to_sleep;
	philo->must_eat = (*table)->must_eat;
	philo->times_eaten = 0;
}

/** @brief		fills the philosopher struct with our parameters from input
 * 	@details 	- mutexes: pointers to the mutexes initialized in the table
 * 				- philo_id : table->id + 1, because philosophers start at 1
 * 
 */
int	init_philo(t_table *table, int id)
{
	t_philo	*philo;
	int		nb_philo;

	philo = &table->philos[id];
	fill_philo_params(philo, &table, id);
	nb_philo = table->nb_philo;
	philo->start_time = table->start_time;
	philo->last_eaten = table->start_time;
	philo->left_fork = &table->forks[id % nb_philo];
	philo->right_fork = &table->forks[(id + 1) % nb_philo];
	philo->left_fork_mutex = &table->fork_mutex[id % nb_philo];
	philo->right_fork_mutex = &table->fork_mutex[(id + 1) % nb_philo];
	pthread_mutex_init(&philo->last_eaten_mutex, NULL);
	philo->death_status = &table->death_status;
	philo->death_status_mutex = &table->death_status_mutex;
	philo->done_eating_mutex = &table->done_eating_mutex;
	philo->done_eating = &table->done_eating;
	return (0);
}

// Stores the input parameters in a the s_table struct
// returns -1 if parameter count is not 4 or 5
// returns 0 otherwise
int	handle_input(t_table *table, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Philosophers – wrong number of parameters: must be 4 or 5\n");
		printf("1) number of philosophers\n2) time to die\n");
		printf("3) time to eat\n4) time to sleep\n");
		printf("5) number of times each philosopher must eat (optional)\n");
		return (print_error(INVALID_INPUT));
	}
	if (argv[5])
		table->must_eat = ft_atoi_philo(argv[5]);
	else
		table->must_eat = -1;
	table->nb_philo = ft_atoi_philo(argv[1]);
	table->time_to_die = ft_atoi_philo(argv[2]);
	table->time_to_eat = ft_atoi_philo(argv[3]);
	table->time_to_sleep = ft_atoi_philo(argv[4]);
	if (table->nb_philo < 0 || table->time_to_die < 0 || \
	table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (print_error(INVALID_INPUT));
	if (table->nb_philo == 0 || table->time_to_die == 0 || \
	table->time_to_eat == 0 || table->time_to_sleep == 0 || \
	table->must_eat == 0)
		return (print_error(ZERO_AS_INPUT));
	return (0);
}

/* initializes table:
calls init_forks first
then creates the philosophers thread with all the parameters
Set death status to 0 (no philosopher is dead)
Set finished eating status to 0 (no philosopher finished eating) */
int	init_table(t_table *table, int argc, char **argv)
{
	int	i;

	if (handle_input(table, argc, argv) == -1)
		return (-1);
	table->start_time = get_time_stamp();
	memset(&table->death_status, NO_DEATHS, sizeof(unsigned char));
	memset(&table->done_eating, NO_DEATHS, sizeof(unsigned char));
	if (pthread_mutex_init(&table->death_status_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&table->done_eating_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	i = 0;
	while (i < table->nb_philo)
	{
		memset(&table->forks[i], FREE, sizeof(unsigned char));
		if (pthread_mutex_init(&table->fork_mutex[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		if (init_philo(table, i))
			return (print_error(GET_TIME_OF_DAY_ERROR));
		i++;
	}
	return (0);
}
