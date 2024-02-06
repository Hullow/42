/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:29:45 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 09:01:33 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sleep_ms(unsigned int milliseconds)
{
	usleep(milliseconds * 1000);
}

void	ft_putchar(char *str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		sleep_ms(50);
		i++;
	}
}
