/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/05/04 19:06:45 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_env *env)
{
	ft_print_point_list(env);
	// ft_max_altitude(env->point_list);
	// ft_z_axis_rotation(env->point_list);
	// ft_isometric_projection(env->point_list);
	// float zoom = ft_calculate_zoom(env->point_list);
	// ft_apply_zoom(env->point_list, zoom);
	// ft_center_points(env->point_list, ft_min_max(env->point_list));
	// ft_draw_points(env);
	// ft_draw_lines(env);
}

void	ft_draw_points(t_env *env)
{
	t_list	*anchor;
	int		*temp;

	anchor = env->point_list;
	temp = (int *) malloc (sizeof(int) * 6);
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp = ((int *) env->point_list->content);
			my_mlx_pixel_put(env, temp[0], temp[1], temp[5]);
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

	line_coordinates = (int *)malloc(sizeof(int) * 7);
	line_coordinates[4] = ((int *) env->point_list->content)[3];
	line_coordinates[5] = ((int *) env->point_list->content)[4];
	anchor = env->point_list;
	ft_draw_horizontal_lines(env, line_coordinates, 0);
	env->point_list = anchor;
	ft_draw_vertical_lines(env, line_coordinates);
}

// draws horizontal lines of the grid, iteratively over the linked list
// go through all columns
#include <time.h>
void	ft_draw_horizontal_lines(t_env *env, int *line_coordinates, int i)
{
	while (env->point_list->next)
	{
		if (i < line_coordinates[5] - 1)
		{
			i++;
			line_coordinates[0] = ((int *) env->point_list->content)[0];
			line_coordinates[1] = ((int *) env->point_list->content)[1];
			line_coordinates[6] = ((int *) env->point_list->content)[5];
			if (env->point_list->next)
				env->point_list = env->point_list->next;
			line_coordinates[2] = ((int *) env->point_list->content)[0];
			line_coordinates[3] = ((int *) env->point_list->content)[1];
			ft_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], line_coordinates[6]);
		}
		else
		{
			i = 0;
			if (env->point_list->next)
				env->point_list = env->point_list->next;
		}
	}
}

// for each point, we want to know that there is a point one line underneath before drawing a line
// the way to do this is to iterate #columns point ahead:
// draws vertical lines of the grid, iteratively over the linked list
// lines_coordinates[4]: #lines
// lines_coordinates[5]: #columns
void	ft_draw_vertical_lines(t_env *env, int *line_coordinates)
{
	t_list	*anchor;
	int		columns;

	anchor = env->point_list;
	columns = line_coordinates[5];
	while (env->point_list)
	{
		line_coordinates[0] = ((int *)(env->point_list->content))[0];
		line_coordinates[1] = ((int *)(env->point_list->content))[1];
		line_coordinates[6] = ((int *)(env->point_list->content))[5];
		while (columns-- && env->point_list->next)
			env->point_list = env->point_list->next;
		if (columns)
			break ;
		else
		{
			line_coordinates[2] = ((int *)(env->point_list->content))[0];
			line_coordinates[3] = ((int *)(env->point_list->content))[1];
			ft_line_put(env, line_coordinates[0], \
			line_coordinates[1], line_coordinates[2], line_coordinates[3], line_coordinates[6]);
		}
		columns = line_coordinates[5];
		anchor = anchor->next;
		env->point_list = anchor;
	}
}

void	ft_max_altitude(t_list *point_list)
{
	int	max_altitude;

	max_altitude = 0;
	while (point_list)
	{
		if (((int *)point_list->content)[2] > max_altitude)
			max_altitude = ((int *)point_list->content)[2];
		point_list = point_list->next;
	}
	ft_printf("final max altitude: %d\n", max_altitude);
}
