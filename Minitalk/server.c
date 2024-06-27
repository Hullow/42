/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:49:34 by francis           #+#    #+#             */
/*   Updated: 2024/06/26 17:05:18 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	ft_signal_handler(int sig)
{
	if (sig == 30)
		printf("signal 30");
	else if (sig == 31)
		printf("signal 31");
	else
		printf("signal: %d\n", sig);
}

int main()
{
	pid_t				sample_PID;
	// sigset_t			*set;
	struct sigaction	s_sigaction;

	s_sigaction.__sigaction_u = ft_signal_handler;
	s_sigaction.sa_mask 
	sample_PID = getpid();
	printf("%d\n", sample_PID);
	// sigemptyset(set);

	// sigaddset(set, 30);
	sigaction(30, ft_signal_handler(30), NULL);
	kill (sample_PID, 30);
	// ft_putnbr_fd(sample_PID, 0);

	// sigemptyset(signal_set); //initializes a signal set to be empty: signal_set
		// sigset_t *sigset = NULL;
		// sigemptyset(sigset);  //initializes a signal set to be empty: signal_set
		// sigaddset(sigset, SIGUSR2); // add the signal no 30 (SIGUSR1) to the signal set signal_setq
	while (1)
	{
		pause();
		kill(getpid(), SIGKILL);
		// signal(SIGUSR2, (sig_t) write(1, "signal 31 received\n", 20));
	
	}
	// write(1, &sample_PID, 50);
	return (0);
}