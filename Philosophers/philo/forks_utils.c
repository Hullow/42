/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:06:32 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 20:40:25 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* sets the fork state using memset:
	0 for free, 1 for locked as locked */
void	set_forks_status(t_philo *philo, char c)
{
	memset(philo->left_fork, c, sizeof(unsigned char));
	memset(philo->right_fork, c, sizeof(unsigned char));
}

pthread_mutex_t	*select_fork_mutex(t_philo *philo, enum e_fork fork_to_pick)
{
	if (fork_to_pick == LEFT)
		return (philo->left_fork_mutex);
	else if (fork_to_pick == RIGHT)
		return (philo->right_fork_mutex);
	else
		return (NULL);
}

unsigned char	*select_fork(t_philo *philo, enum e_fork fork_to_pick)
{
	if (fork_to_pick == LEFT)
		return (philo->left_fork);
	else if (fork_to_pick == RIGHT)
		return (philo->right_fork);
	else
		return (NULL);
}

/* check if the two forks for a given philosopher (id) are available */
int	forks_available(t_philo *philo, int id)
{
	if (*(philo->left_fork) == id && *(philo->right_fork) == id && \
	philo->left_fork_id != philo->right_fork_id)
		return (1);
	else
		return (0);
}
