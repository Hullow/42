/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:49:34 by francis           #+#    #+#             */
/*   Updated: 2024/06/20 19:00:54 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int main()
{
	pid_t	sample_PID;

	sample_PID = getpid();
	printf("%d\n", sample_PID);
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