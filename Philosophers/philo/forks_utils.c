/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:06:32 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 20:48:23 by francis          ###   ########.fr       */
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