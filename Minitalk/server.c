/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/07/01 16:00:28 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("sa_handler: SIGUSR1 received\n");
	}
	else
		printf("sa_handler: received signal %d\n", signum);
}


int main()
{
	pid_t				sample_PID;
	
	sample_PID = getpid();
	ft_printf("%d\n", sample_PID);
	pause();
	struct	sigaction	sigact;
	sigact.sa_handler = handler;
	sigact.sa_flags =
	sigaction(SIGUSR1, &sigact, NULL);

	printf("server: signal received\n");
	return (0);
}