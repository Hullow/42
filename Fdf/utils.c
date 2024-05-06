/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:13 by fallan            #+#    #+#             */
/*   Updated: 2024/05/06 15:39:26 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_list(t_list *point_list)
{
	t_list	*temp;

	temp = NULL;
	while (point_list)
	{
		temp = point_list;
		point_list = point_list->next;
		free(temp);
	}
}

void	ft_free_array(char ***split, int *line_data)
{
	int	i;

	i = -1;
	if (split)
	{
		while (++i < line_data[0])
			free(split[i]);
		free(split);
	}
}
