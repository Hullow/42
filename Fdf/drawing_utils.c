/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/04/30 11:47:37 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_to_next_point(t_env *env)
{
	t_list	*anchor;
	int		i;
	int		j = 0;
	int		k = 0;
	int		l = 0;
	int		line_coordinates[6];

	i = 0;
	line_coordinates[4] = ((int *) env->point_list->content)[3]; // #lines
	line_coordinates[5] = ((int *) env->point_list->content)[4]; // #columns
	ft_printf("before printing points: env->point_list: {%p}\n", env->point_list);
	ft_printf("line_coordinates[4] : %d, line_coordinates[5]: %d\n", line_coordinates[4], line_coordinates[5]);
	anchor = env->point_list;

	// horizontal lines of the grid
	if (env->point_list)
		{
			ft_printf("\n\nprinting \"horizontal\" lines:\n**************************\n");
			while (env->point_list->next)
			{
				if (i < line_coordinates[5] - 1) // go through all columns
				{
					i++;
					line_coordinates[0] = ((int *) env->point_list->content)[0];
					line_coordinates[1] = ((int *) env->point_list->content)[1];
					if (env->point_list->next)
						env->point_list = env->point_list->next;
					line_coordinates[2] = ((int *) env->point_list->content)[0];
					line_coordinates[3] = ((int *) env->point_list->content)[1];
					my_mlx_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], my_color_to_hex(env->color));
				}
				else
				{
					i = 0;
					if (env->point_list->next)
						env->point_list = env->point_list->next;
				}
			}
		}
	env->point_list = anchor;

	// vertical lines of the grid
	if (env->point_list)
		{
			printf("\n\nprinting \"vertical\" lines:\n**************************\n");
			while (j < line_coordinates[4] && env->point_list->next) // go through all lines
			{
				j++;
				while (l < line_coordinates[5] - 1 && env->point_list->next)
				{
					l++;
					line_coordinates[0] = ((int *) env->point_list->content)[0];
					line_coordinates[1] = ((int *) env->point_list->content)[1];
					anchor = env->point_list;
					while (i < line_coordinates[5]) // go one line ahead (i.e. advance by #columns)
					{
						i++;
						if (env->point_list->next)
							env->point_list = env->point_list->next;
					}
					i = 0;
					line_coordinates[2] = ((int *) env->point_list->content)[0];
					line_coordinates[3] = ((int *) env->point_list->content)[1];
					my_mlx_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], my_color_to_hex(env->color));
					k++;
			// printf(" line %d: (%d,%d) to (%d,%d)–", k, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3]);
					if (k % 4 == 0)
			// printf("\n");
					if (anchor->next)
						env->point_list = anchor->next;
					if (!(env->point_list->next))
			printf("we've arrived at the end\n");
				}
				l = 0;
			}
		}
}

void	ft_put_point_list(t_env *env)
{
	t_list	*anchor;

	anchor = env->point_list;
	ft_printf("before printing points: env->point_list: {%p}\n", env->point_list);
	if (env->point_list)
	{
		while (env->point_list)
		{
			if (ft_strncmp(env->color, "undefined", 10))
				my_mlx_pixel_put(env, ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1], ((int *) env->point_list->content)[5]);
			else
				my_mlx_pixel_put(env, ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1], my_color_to_hex(env->color));
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
	ft_printf("after printing points: env->point_list: {%p}\n", env->point_list);
	ft_printf("line_coordinates[4] : %d, line_coordinates[5]: %d\n", \
	 ((int *) env->point_list->content)[3], ((int *) env->point_list->content)[4]);
}

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// DDA algorithm
void	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	float	X;
	float	Y;
	int		steps;
	int		i;

    // calculate steps required for generating pixels
    if (abs(x2 - x1) > abs(y2 - y1))
		steps = abs(x2 - x1);
	else
		steps = abs(y2 - y1);
  
    // Put pixel for each step 
    X = x1;
	Y = y1;
	i = 0;
    while (i <= steps)
	{
		my_mlx_pixel_put(env, round(X), round(Y), color);
        X += (x2 - x1) / (float)steps; // increment in x at each step
        Y += (y2 - y1) / (float)steps; // increment in y at each step
		i++;
	}
}

