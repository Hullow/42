/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/19 18:33:39 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

void	launch_window_and_draw(t_list *point_list)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	env.point_list = point_list;
	env.color = "white";
	env.drawn = 0;

	mlx_hook(env.win, 2, 1L<<0, key_handler, &env);
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_loop(env.mlx);
}

int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		ft_printf("ESCAPE key pressed, program stopping\n");
		mlx_destroy_window (env->mlx, env->win);
		exit(1);
	}
	else if (!(env->drawn))
	{
		if (keycode == 15)
			env->color = "red";
		else if (keycode == 11)
			env->color = "blue";
		else if (keycode == 5)
			env->color = "green";

		ft_graph_transformation(env->point_list);
		ft_put_point_list(env);
		ft_draw_line_to_next_point(env);
		// my_mlx_line_put(env, 700, 500, 10, 10, my_color_to_hex(env->color));
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		env->drawn = 1;
	}
	else if (env->drawn == 1)
		ft_printf("image already drawn, please press ESC to stop the program, and try again\n");
	return (0);
}

void	ft_draw_line_to_next_point(t_env *env)
{
	t_list	*anchor;
	t_list	*current = NULL;
	int		i;
	int		start_point[6];
	int		end_point[6];

	// ft_memcpy(start_point, ((int *) env->point_list->content), 6);
	// point[0] = j;
	// point[1] = i;
	// point[2] = ft_atoi(split_string[j]);
	// point[3] = line_data[0];
	// point[4] = line_data[1];
	// point[5] = 1;
	start_point[3] = ((int *) env->point_list->content)[3];
	start_point[4] = ((int *) env->point_list->content)[4];
	ft_printf("start_point[3] : %d, start_point[4]: %d\n", start_point[3], start_point[4]);
	anchor = env->point_list;
	i = 0;
	ft_printf("before printing points: env->point_list: {%p}\n", env->point_list);
	if (env->point_list)
	{
		while (env->point_list->next)
		{
			start_point[0] = ((int *) env->point_list->content)[0];
			start_point[1] = ((int *) env->point_list->content)[1];
			current = env->point_list;
			i = -1;
			while (++i < start_point[4] + 1 && current->next)
				current = current->next;
			end_point[0] = ((int *) current->content)[0];
			end_point[1] = ((int *) current->content)[1];
			if (i == start_point[4] + 1)
			{
				ft_printf("i: %d, printing out the line \n", i);
				my_mlx_line_put(env, start_point[0], start_point[1], end_point[0], end_point[1], my_color_to_hex(env->color));
			}
			else
				ft_printf("i: %d, not printing out the line \n", i);
			env->point_list = env->point_list->next;
		}
	}
	ft_printf("supposedly we've printed all points out\n");
	env->point_list = anchor;
}

int	close_window(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	mlx_destroy_window(env->mlx, env->win);
	exit(1);
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

void	my_mlx_line_put_bresenham(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;

	while (x1 < x2)
	{
		ft_printf("while loop: p is %d –>", p);
		if (p >= 0)
		{
			my_mlx_pixel_put(env, x1, y1, color);
			y1++;
			p += 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(env, x1, y1, color);
			p += 2 * dy;
		}
		ft_printf("p reset to %d\n", p);
		x1++;
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
