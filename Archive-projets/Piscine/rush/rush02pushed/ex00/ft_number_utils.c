/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbinet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:31:30 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 16:15:49 by nbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// ======================================================================

char	*number_in_file(int number);
char	*ft_strdup(const char *str);
void	ft_putchar(char *str);
void	handle_double_digit(long int number);
void	handle_hundreds(long int number);
void	handle_thousands(long int number);
void	handle_millions(long int number);
void	handle_billions(long int number);

// ======================================================================

void	handle_single_digit(long int number)
{
	char	*units;

	units = number_in_file(number);
	ft_putchar(units);
	free(units);
}

void	number_to_word(long int number)
{
	if (number < 10)
		handle_single_digit(number);
	else if (number < 100)
		handle_double_digit(number);
	else if (number < 1000)
		handle_hundreds(number);
	else if (number < 1000000)
		handle_thousands(number);
	else if (number < 1000000000)
		handle_millions(number);
	else if (number < 1000000000000)
		handle_billions(number);
}
