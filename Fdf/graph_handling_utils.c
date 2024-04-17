/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/17 14:38:15 by fallan           ###   ########.fr       */
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
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	// }
	return (0);
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

void	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	int line_ratio = (x2-x1) / (y2-y1);
	int inverse_line_ratio;
	int x_factor;
	int y_factor;

	if (line_ratio == 0)
		inverse_line_ratio = 1;
	else
		inverse_line_ratio = 1/line_ratio;

	// 2 cumulative variants (so 4 total):
	// if (x2 > x1)
	// multiply the added difference by 1
	// if (x2 < x1)
	// multiply the added difference by -1
	if (x1 <= x2)
		x_factor = 1;
	else
		x_factor = -1;
	if (y2 >= y1)
		y_factor = 1;
	else
		y_factor = -1;
	while (x1 * x_factor <= x2 * x_factor && y1 <= y_factor * y2)
	{
		if (x1 != x2)
			x1 += x_factor;
		y1 += y_factor * inverse_line_ratio;
		if (x1 != x2 && y1 != y2)
			my_mlx_pixel_put(env, x1, y1, color);
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
