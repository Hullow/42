/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/06 10:53:59 by francis          ###   ########.fr       */
=======
/*   Updated: 2024/05/07 16:52:50 by fallan           ###   ########.fr       */
>>>>>>> fixing_projection
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

<<<<<<< HEAD
void	ft_draw(t_env *env)
{
	// printf("**************\ninput points:\n\n");
	// ft_print_point_list(env);
	// ft_max_altitude(env->point_list);

	// ft_z_rotation(env->point_list);
	// ft_x_rotation(env->point_list);
	// ft_orthographic_projection(env->point_list);

	ft_isometric_projection(env->point_list);

	// ft_print_point_list(env);
	// printf("\n\n**************\nprojectesd points:\n\n");
	// ft_print_point_list(env);
	// float zoom = ft_calculate_zoom(ft_min_max(env->point_list), WINDOW_WIDTH, WINDOW_HEIGHT);
	// ft_apply_zoom(env->point_list, 15);
	ft_center_points(env->point_list, ft_min_max(env->point_list));
	ft_draw_points(env);
	ft_draw_lines(env);
}
=======
// DEBUGGING FUNCTIONS:
	// ft_print_point_list(env);
	// ft_draw_points(env);
>>>>>>> fixing_projection

// applies all transformations
// 1. isometric projection:
// 1.1 z-rotation (45 deg)
// 1.2 x-rotation (arctan(1/sqrt(2)) radians)
// 2. zoom:
// 2.2 calculates zoom (using x,y min and max values)
// 2.3 applies zoom to each point of the list
// 3. centers points in the image
// 4. draws lines (using DDA algorithm)
// 4.4 draws "horizontal" lines of grid
// 4.4 draws "vertical" lines of grid
// other variables:
// coord[4]: #lines of grid
// coord[5]: #columns of grid
void	ft_draw(t_env *env)
{
	t_list	*anchor;
	double	*minmax;
	double	*translation_vector;	translation_vector = (double *)malloc(sizeof(double) * 2);	ft_free((void **)&translation_vector);
	double	*coord;
	double	zoom;

	anchor = env->point_list;
	translation_vector = (double *)malloc(sizeof(double) * 2);
	coord = (double *)malloc(sizeof(double) * 7);
	coord[5] = ((double *) env->point_list->content)[4];
	ft_z_rotation(env->point_list);
	ft_x_rotation(env->point_list);
	minmax = ft_min_max(env->point_list);
	zoom = ft_calculate_zoom(minmax, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_apply_zoom(env->point_list, zoom);
	
	// ft_center_points(env->point_list, minmax);
	translation_vector = ft_calculate_center(minmax, translation_vector);
	ft_translate(env->point_list, translation_vector);

	ft_draw_horizontal(env, coord, 0);
	env->point_list = anchor;
	ft_draw_vertical(env, coord, coord[5]);
	
	ft_free((void **)&coord);
	ft_free((void **)&translation_vector);
	ft_free((void **)&minmax);
}

// draws horizontal lines of the grid, iteratively over the linked list
// go through all columns
void	ft_draw_horizontal(t_env *env, double *coord, int i)
{
<<<<<<< HEAD
	// int j = 0;
	int line;
	line = 0;
	printf("\nhorizontal lines: %d so far\n**************\n", line);
	while (env->point_list->next) // && ++j < 25)
=======
	while (env->point_list)
>>>>>>> fixing_projection
	{
		if (i < coord[5] - 1)
		{
			i++;
			coord[0] = ((double *) env->point_list->content)[0];
			coord[1] = ((double *) env->point_list->content)[1];
			coord[6] = ((double *) env->point_list->content)[5];
			env->point_list = env->point_list->next;
			coord[2] = ((double *) env->point_list->content)[0];
			coord[3] = ((double *) env->point_list->content)[1];
			ft_line_put(env, coord);
		}
		else
		{
			i = 0;
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
void	ft_draw_vertical(t_env *env, double *coord, int columns)
{
	t_list	*anchor;

	anchor = env->point_list;
	while (env->point_list)
	{
<<<<<<< HEAD
		coord[0] = ((int *)(env->point_list->content))[0];
		coord[1] = ((int *)(env->point_list->content))[1];
		coord[6] = ((int *)(env->point_list->content))[5];
		while (columns && env->point_list)
=======
		coord[0] = ((double *)(env->point_list->content))[0];
		coord[1] = ((double *)(env->point_list->content))[1];
		coord[6] = ((double *)(env->point_list->content))[5];
		while (columns && env->point_list->next)
>>>>>>> fixing_projection
		{
			columns--;
			env->point_list = env->point_list->next;
		}
		if (columns)
			break ;
		else
		{
			coord[2] = ((double *)(env->point_list->content))[0];
			coord[3] = ((double *)(env->point_list->content))[1];
			ft_line_put(env, coord);
		}
		columns = coord[5];
		anchor = anchor->next;
		env->point_list = anchor;
	}
}
