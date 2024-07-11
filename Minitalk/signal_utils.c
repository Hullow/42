/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:23:31 by fallan            #+#    #+#             */
/*   Updated: 2024/07/11 20:23:40 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_send_signal_one(int server_pid)
{
	if (kill(server_pid, SIGUSR1) == -1)
	{
		ft_printf("\nft_send_signal_one: kill error");
		exit(-1);
	}
	usleep (600);
}

void	ft_send_signal_two(int server_pid)
{
	if (kill(server_pid, SIGUSR2) == -1)
	{
		ft_printf("\nft_send_signal_two: kill error");
		exit(-1);
	}
	usleep (600);
}

// recursive function converting decimal to binary, sending SIGUSR1 signal for
// each '0' bit and SIGUSR2 for each '1' bit
// usleep slows down execution to allow for each bit to be received by server 
void	ft_send_binary_signal(int target_pid, unsigned int number)
{
	if (number == 0)
		ft_send_signal_one(target_pid);
	else if (number == 1)
		ft_send_signal_two(target_pid);
	else
	{
		ft_send_binary_signal(target_pid, number / 2);
		ft_send_binary_signal(target_pid, number % 2);
	}
}