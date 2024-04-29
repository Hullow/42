/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:49:34 by francis           #+#    #+#             */
/*   Updated: 2024/04/28 19:52:19 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	process_generating_function(void)
{
	pid_t	sample_PID;

	sample_PID = getpid();
	write(1, &sample_PID, 50);
	// sleep(5);
}

int main()
{
	// sigemptyset(signal_set); //initializes a signal set to be empty: signal_set
	// sigaddset(signal_set, 30); // add the signal no 30 (SIGUSR1) to the signal set signal_setq

	process_generating_function();


}