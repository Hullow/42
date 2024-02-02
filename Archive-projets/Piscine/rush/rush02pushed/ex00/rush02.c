/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:46:18 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 14:12:55 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// ======================================================================

int			is_valid(char *str);
long int	ft_atoi(char *str);
void		number_to_word(long int number);

// ======================================================================

int	main(int argc, char **argv)
{
	long int	number;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!is_valid(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	number = ft_atoi(argv[argc - 1]);
	if (number == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	number_to_word(number);
	write(1, "\n", 1);
	return (0);
}
