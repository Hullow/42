/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/14 18:03:32 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_params	*params;
	t_table		table;

	params = malloc (sizeof(t_params));
	if (handle_input(params, argc, argv) == -1)
		return (-1);
	if (init_table(&table, params, params->nb_philo) == -1)
		return (-1);
	free(params);
	return (0);
}
