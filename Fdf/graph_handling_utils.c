/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/18 18:40:00 by fallan           ###   ########.fr       */
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

	mlx_hook(env.win, 2, 1L<<0, key_handler, &env);
	mlx_loop(env.mlx);
}

void	ft_put_point_list(t_env *env)
{
	if (env->point_list)
	{
		while (env->point_list->next)
		{
			my_mlx_pixel_put(env, ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1], my_color_to_hex(env->color));
			env->point_list = env->point_list->next;
		}
	}
}

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	// if (keycode == 53)
	// 	printf("ESCAPE\n");
	// else
	// {
		// ft_treat_point_list(env);
		ft_graph_transformation(env->point_list);
		ft_put_point_list(env);
		my_mlx_line_put(env, 90, 150, 0, 50, my_color_to_hex("white"));
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	// }
	return (0);
}

// My thinking (not this implementation, as a thinking help to understand the differential analyzer algo):
//
// if abs(line_ratio) >= 1, then y difference >= x difference, so we increment x, then figure out y
// if abs(line_ratio) < 1, then y difference < x difference, so we increment y, then figure out x

// method: line_ratio tells us the frequency with which we increment a given axis with relation to
// the other. e.g. line_ratio == 1 means we add one x pixel for each y pixel.
void	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	float	dx;
	float	dy;
	float 	step;
	int		i;
	
	dx = x2-x1;
	dy = y2-y1;

	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);

	dx = dx / step;
	dy = dy / step;
	i = 0;

	while (i <= step)
	{
		my_mlx_pixel_put(env, x1, y1, color);
		x1 += dx;
		y1 += dy;
		i += 1;
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
