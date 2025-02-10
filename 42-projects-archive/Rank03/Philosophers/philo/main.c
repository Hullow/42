/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 22:35:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_table		*table;

	table = malloc (sizeof(t_table));
	if (handle_input(table, argc, argv) == -1)
	{
		free(table);
		return (-1);
	}
	if (init_table(table) < 0)
	{
		free(table);
		return (-1);
	}
	run_simulation(table);
	end_simulation(table);
	free(table);
	return (0);
}
