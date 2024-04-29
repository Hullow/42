/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/04/29 14:56:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_to_next_point(t_env *env)
{
	t_list	*anchor;
	int		i;
	int		j;
	int		line_coordinates[6];

	// point[0] = j aka x;
	// point[1] = i aka y;
	// point[2] = ft_atoi(split_string[j]);
	// point[3] = line_data[0];
	// point[4] = line_data[1];
	// point[5] = 1;
	line_coordinates[4] = ((int *) env->point_list->content)[3]; // #lines
	line_coordinates[5] = ((int *) env->point_list->content)[4]; // #columns
	ft_printf("before printing points: env->point_list: {%p}\n", env->point_list);
	ft_printf("line_coordinates[4] : %d, line_coordinates[5]: %d\n", line_coordinates[4], line_coordinates[5]);
	anchor = env->point_list;
	i = 0;
	j = 0;
	int k = 0;
	// usleep(2000000);
	if (env->point_list)
		{
			ft_printf("\n\nprinting \"horizontal\" lines:\n*************\n");
			while (env->point_list->next)
			{
				if (i < line_coordinates[5]) // go through all columns
				{
					// ft_printf("line_coordinates[4] : %d, line_coordinates[5]: %d\n", line_coordinates[4], line_coordinates[5]);
					i++;
					// ft_printf("i: %d- ", i);
					line_coordinates[0] = ((int *) env->point_list->content)[0];
					line_coordinates[1] = ((int *) env->point_list->content)[1];
					// ft_printf("line_coordinates[0] : %d, line_coordinates[1]: %d, env->point_list: %p\n", \
					//line_coordinates[0], line_coordinates[1], env->point_list);
					if (env->point_list->next)
						env->point_list = env->point_list->next;
					// if (i > 7)
						// ft_printf("current element: address {%p}, values %d,%d\n", line_coordinates[0], line_coordinates[1]);
					line_coordinates[2] = ((int *) env->point_list->content)[0];
					line_coordinates[3] = ((int *) env->point_list->content)[1];
					my_mlx_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], my_color_to_hex(env->color));
					k++;
					ft_printf("line %d: (%d,%d) to (%d,%d) ", k, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3]);
					if (k % 7 == 0)
						ft_printf("\n");
				}
				else
				{
					// ft_printf("\n*****  we hit end of line (last column: %d)\n\n", i);
					i = 0;
					if (env->point_list->next)
						env->point_list = env->point_list->next;
				}
				// usleep(25000);
			}
		}
	
	
	env->point_list = anchor;


	if (env->point_list)
		{
			ft_printf("\n\nprinting \"vertical\" lines:\n*************\n");
			while (j < line_coordinates[4] && env->point_list->next) // go through all lines
			{
				j++;
				ft_printf("j: %d ", j);
				line_coordinates[0] = ((int *) env->point_list->content)[0];
				line_coordinates[1] = ((int *) env->point_list->content)[1];
				anchor = env->point_list;
				while (i < line_coordinates[5]) // go one line ahead (i.e. advance by #columns)
				{
					i++;
					if (env->point_list->next)
						env->point_list = env->point_list->next;
				}
				ft_printf("i: %d ", i);
				i = 0;
				line_coordinates[2] = ((int *) env->point_list->content)[0];
				line_coordinates[3] = ((int *) env->point_list->content)[1];
				my_mlx_line_put(env, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3], my_color_to_hex(env->color));
				k++;
				ft_printf("line %d: (%d,%d) to (%d,%d)", k, line_coordinates[0], line_coordinates[1], line_coordinates[2], line_coordinates[3]);
				if (k % 7 == 0)
					ft_printf("\n");
				if (anchor->next)
					env->point_list = anchor->next;
			}
				// usleep(25000);
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

// My thinking (not this implementation, as a thinking help to understand the differential analyzer algo):
//
// if abs(line_ratio) >= 1, then y difference >= x difference, so we increment x, then figure out y
// if abs(line_ratio) < 1, then y difference < x difference, so we increment y, then figure out x

// method: line_ratio tells us the frequency with which we increment a given axis with relation to
// the other. e.g. line_ratio == 1 means we add one x pixel for each y pixel.

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

int		my_color_to_hex(char *color)
{
	if (!ft_strncmp(color, "red", 3))
		return (0x00FF0000);
	else if (!ft_strncmp(color, "blue", 4))
		return (0x000000FF);
	else if (!ft_strncmp(color, "green", 5))
		return (0x0000FF00);
	else if (!ft_strncmp(color, "purple", 6))
		return (0x009900FF);
	else if (!ft_strncmp(color, "yellow", 6))
		return (0x00FFFF00);
	else if (!ft_strncmp(color, "white", 5))
		return (0x00FFFFFF);
	else
		return (0xFFFFFFFF);
}
