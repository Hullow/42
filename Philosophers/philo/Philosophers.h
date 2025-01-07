/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/07 18:44:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

enum error {
	MALLOC_FAIL,
	MUTEX_INIT_ERROR,
	THREAD_CREATION_ERROR
};

// Structure to store the input parameters
struct s_params
{
	int	nb_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	must_eat_times;
};

struct s_philo
{
	pthread_t	thread_id;
	int			*forks;
	int			philo_id;
	long		last_eaten;
	int			must_eat_times;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
};

// Utils
	// Input
int		ft_atoi(char *str);
int		handle_input(struct s_params *params, int argc, char **argv);
	// Running
long	get_time_stamp(void);
int		handle_error(int error);

// Simulation
	// Initialization
void	*initialize_forks(int nb_philo);
int		initialize_table(struct s_params *params);
void	fill_params(struct s_philo *philo, int **forks, struct s_params *params, int philo_id);
void	*philo_routine(void *vargp);