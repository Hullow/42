/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_multi_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:57:25 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 09:58:13 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// ======================================================================

void	ft_putchar(char *str);
char	*number_in_file(int number);
void	number_to_word(long int number);

// ======================================================================

void	handle_double_digit(long int number)
{
	int		tens;
	int		units;
	char	*tens_str;

	if (number < 20)
	{
		tens_str = number_in_file(number);
		ft_putchar(tens_str);
		free(tens_str);
	}
	else
	{
		tens = (number / 10) * 10;
		units = number % 10;
		tens_str = number_in_file(tens);
		ft_putchar(tens_str);
		free(tens_str);
		if (units > 0)
		{
			ft_putchar(" ");
			number_to_word(units);
		}
	}
}

void	handle_hundreds(long int number)
{
	int		hundreds;
	int		remainder;
	char	*hundreds_str;

	hundreds = number / 100;
	remainder = number % 100;
	hundreds_str = number_in_file(hundreds);
	ft_putchar(hundreds_str);
	free(hundreds_str);
	ft_putchar(" hundred");
	if (remainder > 0)
	{
		ft_putchar(" ");
		number_to_word(remainder);
	}
}

void	handle_thousands(long int number)
{
	number_to_word(number / 1000);
	ft_putchar(" thousand ");
	if (number % 1000 > 0)
		number_to_word(number % 1000);
}

void	handle_millions(long int number)
{
	number_to_word(number / 1000000);
	ft_putchar(" million ");
	if (number % 1000000 > 0)
		number_to_word(number % 1000000);
}

void	handle_billions(long int number)
{
	number_to_word(number / 1000000000);
	ft_putchar(" billion ");
	if (number % 1000000000 > 0)
		number_to_word(number % 1000000000);
}
