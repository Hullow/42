/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/25 12:44:55 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// sets the global death status to 1
// prints a death statement
// returns 0 on success, -1 in case of error
int	handle_philo_death(t_philo *philo)
{
	if (pthread_mutex_lock(philo->global_death_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	memset(philo->death_status, philo->philo_id, sizeof(unsigned char));
	if (pthread_mutex_unlock(philo->global_death_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
	print_status(philo, get_time_stamp(0), "died");
	return (0);
}

/* checks if a philosopher is dead */
void	*checker_routine(void *vargp)
{
	t_philo	*philos;
	int		nb_philo;
	int		time_to_die;
	int		i;

	philos = (t_philo *)vargp;
	nb_philo = philos[0].nb_philo;
	time_to_die = philos[0].time_to_die;
	i = 0;
	while (1)
	{
		while (i < nb_philo)
		{
			if (get_time_stamp(philos[0].start_time) - philos[i].last_eaten >= time_to_die)
			{
				handle_philo_death(&philos[i]);
				return (NULL);
			}
			i++;
			usleep(300);
		}
		i = 0;
	}
}

int	attempt_take_fork(t_philo *philo, int fork_to_pick)
{
	pthread_mutex_t	*fork_mutex = NULL;
	unsigned char	*fork;

	if (fork_to_pick == LEFT)
	{
		fork_mutex = philo->left_fork_mutex;
		fork = philo->left_fork;
	}
	else if (fork_to_pick == RIGHT)
	{
		fork_mutex = philo->right_fork_mutex;
		fork = philo->right_fork;
	}
	if (lock_single_fork_mutex(fork_mutex))
		return (-1);
	if (*(fork) == 0) /* if fork available */
	{
		memset(fork, philo->philo_id, sizeof(unsigned char));
		if (unlock_single_fork_mutex(fork_mutex))
			return (-1);
		print_status(philo, get_time_stamp(0), "has taken a fork");
	}
	else if (unlock_single_fork_mutex(fork_mutex))
		return (-1);
	return (0);
}

/* Staggers the start of the simulation, so even and uneven philos eat 
at different times:
	- In all simulations, even-numbered philos wait 0.2ms before trying to eat
	- In simulations with an uneven number of philosophers, the first philo
	waits 0.5ms before trying to eat, so that there it can alternate with 
	the last philo, which is its neighbor, and also uneven-numbered
	*/
void	stagger_start(int nb_philo, int id)
{
	if (id % 2 == 0)
		usleep(200);
	if (nb_philo % 2 != 0 && id == 1)
		usleep(500);// 1st philo waits 0.5 ms before trying to eat => likely no change; and yet, it seems to have changed things
}

/* Attempt to eat :
	- locks both forks mutexes
	- checks status of each fork: if both are set to the philo's id, go ahead
		-> if not, unlocks both forks mutexes and sleeps 0.05ms
	- unlocks both forks mutexes
	- calls function to eat
	- relocks both forks mutexes
	- sets forks statuses back to 0 to free them
	- unlocks both forks mutexes
	- calls function to sleep
*/
	
int	attempt_to_eat(t_philo *philo, int id)
{
	if (lock_fork_mutexes(philo))
		return (-1);
	if (*(philo->left_fork) == id && *(philo->right_fork) == id)
	{
		if (unlock_fork_mutexes(philo)) /* unlock both mutexes */
			return (-1);
		perform_activity(philo, get_time_stamp(0), EATING); /* start eating */
		if (lock_fork_mutexes(philo))
			return (-1); // add error handling
		set_forks_status(philo, 0);
		if (unlock_fork_mutexes(philo))
			return (-1); // add error handling
		perform_activity(philo, get_time_stamp(0), SLEEPING);
	}
	else
	{
		if (unlock_fork_mutexes(philo)) /* otherwise, unlock both mutexes */
			return (-1); // add error handling
		usleep(50);
	}
	return (0);
}

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo		*philo;
	int			id;
	long		timestamp;

	/* Initialization */
	philo = (t_philo *)vargp;
	id = philo->philo_id; /* Set ids */

	/* Loop : eating, then sleeping */
	timestamp = get_time_stamp(0);
	print_status(philo, timestamp, "is thinking");
	stagger_start(philo->nb_philo, id);
	while (1)
	{
		/* Take each fork, if possible */
		if (attempt_take_fork(philo, LEFT) == -1)
			break ;
		if (attempt_take_fork(philo, RIGHT) == -1)
			break ;
		if (attempt_to_eat(philo, id) == -1)
			break ;
	}
	return (NULL);
}
