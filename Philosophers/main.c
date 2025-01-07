/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2024/12/27 12:11:30 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	struct s_params	params;

	params = malloc (sizeof(struct s_params));
	if (handle_input(params, argc, argv) == -1)
		return (-1);
	free(params);
	return (0);
}
