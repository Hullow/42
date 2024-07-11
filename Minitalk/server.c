/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/07/11 20:19:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

// uses binary signal to reconstruct 7-bit numbers to integers,
// which are then used as ascii codes to be written to stdout
void	server_sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static int	byte = 0;
	static int	multiplicator = 128;

	if (signum == SIGUSR1 && multiplicator)
	{
		multiplicator /= 2;
	}
	else if (signum == SIGUSR2 && multiplicator)
	{
		byte += multiplicator;
		multiplicator /= 2;
	}
	if (multiplicator == 0)
	{
		write(1, &byte, 1);
		int i = 5;
		while (i-- > 0)
			ft_send_signal_one(info->si_pid);
		ft_send_binary_signal(info->si_pid, (unsigned int) 6, 8);
		byte = 0;
		multiplicator = 128;
	}
}

// prints out PID
// defines a sigaction structure that designates a handler
// establishes that SIGUSR1 and SIGUSR2 are handled by said handler
// constantly waits for signals with pause()
int	main(void)
{
	pid_t				sample_pid;
	struct sigaction	sigact;

	sample_pid = getpid();
	ft_printf("%d\n", sample_pid);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = server_sigaction_handler;
	sigemptyset(&sigact.sa_mask);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
	{
		pause();
	}
	ft_printf("\n");
	return (0);
}


/* // For testing and debugging purposes
void	handler_binary(int signum)
{	
	if (signum == SIGUSR1) // if bit is 0
	{
// printf("\nhandler: SIGUSR1, byte is %d and \
// multiplicator is %d\n", byte, multiplicator);
		write(1, "0", 1);
	}
	else if (signum == SIGUSR2) // if bit is 1
	{
		write(1, "1", 1);
	}
} */