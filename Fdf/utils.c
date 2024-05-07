/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:13 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 12:07:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char ***split, int *line_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (split)
	{
		while (i < line_data[0])
		{
			while (split[i][j])
			{
				ft_free((void **)&split[i][j]);
				j++;
			}
			ft_free((void **)&split[i]);
			i++;
			j = 0;
		}
		ft_free((void **)&split);
	}
}

void	ft_free_list(t_list *point_list)
{
	void	*node;
	void	*content;
	// int 	i = 0;

	node = NULL;
	content = NULL;
	while (point_list)
	{
		node = point_list;
		content = point_list->content;
		point_list = point_list->next;
		ft_free((void **)&node);
		ft_free((void **)&content);
	}
}
