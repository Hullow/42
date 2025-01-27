/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 22:47:04 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_table		*table;

	table = malloc (sizeof(t_table));
	if (handle_input(&params, argc, argv) == -1)
		return (-1);
	if (init_table(table, &params, params.nb_philo) == -1)
		return (-1);
	if (run_simulation(table) == -1)
	{
		end_simulation(table);
		return (-1);
	}
	grim_reaper(table);
	end_simulation(table); /* need more error handling */
	free(table);
	return (0);
}
