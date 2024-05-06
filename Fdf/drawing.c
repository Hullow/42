/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/05/05 20:39:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_env *env)
{
	// printf("**************\ninput points:\n\n");
	// ft_print_point_list(env);
	// ft_max_altitude(env->point_list);
	// ft_z_rotation(env->point_list);
	// ft_x_rotation(env->point_list);
	// ft_print_point_list(env);
	// printf("\n\n**************\nprojectesd points:\n\n");
	// ft_print_point_list(env);
	ft_isometric_projection(env->point_list);
	float zoom = ft_calculate_zoom(ft_min_max(env->point_list), WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_apply_zoom(env->point_list, zoom);
	ft_center_points(env->point_list, ft_min_max(env->point_list));
	ft_draw_points(env);
	ft_draw_lines(env);
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
	free(temp);
	env->point_list = anchor;
}

// draws lines by calling 
// ft_draw_horizontal_lines and ft_draw_vertical_lines
// coord[4]: #lines
// coord[5]: #columns
void	ft_draw_lines(t_env *env)
{
	t_list	*anchor;
	int		*coord;

	coord = (int *)malloc(sizeof(int) * 7);
	coord[4] = ((int *) env->point_list->content)[3];
	coord[5] = ((int *) env->point_list->content)[4];
	anchor = env->point_list;
	ft_draw_horizontal(env, coord, 0);
	env->point_list = anchor;
	ft_draw_vertical(env, coord, coord[5]);
}

// draws horizontal lines of the grid, iteratively over the linked list
// go through all columns
void	ft_draw_horizontal(t_env *env, int *coord, int i)
{
	// int j = 0;
	int line = 0;
	// printf("\nhorizontal lines:\n**************\n");
	while (env->point_list->next) // && ++j < 25)
	{
		if (i < coord[5] - 1)
		{
			i++;
			coord[0] = ((int *) env->point_list->content)[0];
			coord[1] = ((int *) env->point_list->content)[1];
			coord[6] = ((int *) env->point_list->content)[5];
			if (env->point_list->next)
				env->point_list = env->point_list->next;
			coord[2] = ((int *) env->point_list->content)[0];
			coord[3] = ((int *) env->point_list->content)[1];
			// if (j < 21) // line length
			// 	coord[6] += 0xff00; // adding some green
			// else
			// 	coord[6] += 0xff00ff; // adding some red
			ft_line_put(env, coord);
			line++;
			// if (j == 21)
			// 	printf("\n");
			// printf("line %d:(%d, %d)->(%d, %d)\n", line, coord[0], coord[1], coord[2], coord[3]);
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
// for each point, checks if there is a point one line underneath
// before drawing a line, by iterating #columns point ahead:
// coord[4]: #lines
// coord[5]: #columns
// coord[6]: color
void	ft_draw_vertical(t_env *env, int *coord, int columns)
{
	t_list	*anchor;

	anchor = env->point_list;
	// printf("\nvertical now:\n**************\n");
	while (env->point_list)
	{
		coord[0] = ((int *)(env->point_list->content))[0];
		coord[1] = ((int *)(env->point_list->content))[1];
		coord[6] = ((int *)(env->point_list->content))[5];
		while (columns && env->point_list->next)
		{
			columns--;
			env->point_list = env->point_list->next;
		}
		if (columns)
			break ;
		else
		{
			coord[2] = ((int *)(env->point_list->content))[0];
			coord[3] = ((int *)(env->point_list->content))[1];
			ft_line_put(env, coord);
			// printf("line:(%d, %d)->(%d, %d)  –  ", coord[0], coord[1], coord[2], coord[3]);
		}
		columns = coord[5];
		anchor = anchor->next;
		env->point_list = anchor;
	}
}
/* 
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
 */