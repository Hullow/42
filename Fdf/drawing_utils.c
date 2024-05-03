/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/05/03 14:15:55 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_points(t_env *env)
{
	t_list	*anchor;
	int		color;

	anchor = env->point_list;
	if (((int *) env->point_list->content)[5])
		color = ((int *) env->point_list->content)[5];
	else
		color = 0x00FFFFFF;
	if (env->point_list)
	{
		while (env->point_list)
		{
			my_mlx_pixel_put(env, ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1], color);
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
}

// draws lines by calling 
// ft_draw_horizontal_lines and ft_draw_vertical_lines
// lines_coordinates[4]: #lines
// lines_coordinates[5]: #columns
void	ft_draw_lines(t_env *env)
{
	t_list	*anchor;
	int		*line_coordinates;

	line_coordinates = (int *)malloc(sizeof(int) * 6);
	line_coordinates[4] = ((int *) env->point_list->content)[3];
	line_coordinates[5] = ((int *) env->point_list->content)[4];
	anchor = env->point_list;
	// ft_draw_horizontal_lines(env, line_coordinates, 0, 16777215);
	env->point_list = anchor;
	ft_draw_vertical_lines(env, line_coordinates, 0, 16777215);
}

// draws horizontal lines of the grid, iteratively over the linked list
// go through all columns
void	ft_draw_horizontal_lines(t_env *env, int *line_coordinates, int i, int color)
{
	while (env->point_list->next)
	{
		if (i < line_coordinates[5] - 1)
		{
			i++;
			line_coordinates[0] = ((int *) env->point_list->content)[0];
			line_coordinates[1] = ((int *) env->point_list->content)[1];
			if (env->point_list->next)
				env->point_list = env->point_list->next;
			line_coordinates[2] = ((int *) env->point_list->content)[0];
			line_coordinates[3] = ((int *) env->point_list->content)[1];
			if (((int *) env->point_list->content)[5])
				color = ((int *) env->point_list->content)[5];
			ft_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], color);
		}
		else
		{
			i = 0;
			if (env->point_list->next)
				env->point_list = env->point_list->next;
		}
	}
}

// draws vertical lines of the grid, iteratively over the linked list
// go through all lines
void	ft_draw_vertical_lines(t_env *env, int *line_coordinates, int i, int color)
{
	t_list	*anchor;
	int		j;
	int		l;

	j = 0;
	l = 0;
	while (j < line_coordinates[4] && env->point_list->next) // line_coordinates[4]: #lines
	{
		j++;
		while ((l < line_coordinates[5] - 1) && env->point_list->next) // line_coordinates[5]: #column
		{
			l++;
			line_coordinates[0] = ((int *) env->point_list->content)[0];
			line_coordinates[1] = ((int *) env->point_list->content)[1];
			anchor = env->point_list;
			i = 0;
			while (i < line_coordinates[5]) // go one line ahead (i.e. advance by #columns elements)
			{
				i++;
				if (env->point_list->next)
					env->point_list = env->point_list->next;
				else
				{
					ft_printf("break\n");
					break ;
				}
			}
			line_coordinates[2] = ((int *) env->point_list->content)[0];
			line_coordinates[3] = ((int *) env->point_list->content)[1];
			color += 0x00FF00;
			ft_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], color);

			if (anchor->next)
			{
				env->point_list = anchor->next;
				while (env->point_list)
					env->point_list = env->point_list->next;
				env->point_list = anchor->next;
			}
		}
		l = 0;
	}
}
