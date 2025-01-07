/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:08 by francis           #+#    #+#             */
/*   Updated: 2025/01/07 17:57:02 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	struct s_params	*params;

	params = malloc (sizeof(struct s_params));
	if (handle_input(params, argc, argv) == -1)
		return (-1);
	if (initialize_table(params) == -1)
		return (-1);
	free(params);
	return (0);
}
