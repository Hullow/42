/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:59:05 by francis           #+#    #+#             */
/*   Updated: 2024/07/11 19:25:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

void	ft_send_signal_one(int server_pid);
void	ft_send_signal_two(int server_pid);
void	ft_send_binary_signal(int target_pid, unsigned int number, int c);