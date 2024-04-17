/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/15 19:06:55 by francis          ###   ########.fr       */
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
		ft_put_point_list(env, NULL, 0.1);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	// }
	return (0);
}

void	ft_put_point_list(t_env *env, t_list *anchor, float zoom)
{
	int temp[3];
	int	x_max;
	int	y_max;
	int	x_min;
	int	y_min;

	x_max = 0;
	y_max = 0;
	x_min = 0;
	y_min = 0;

	ft_printf("zoom: %d\n", (int)zoom);
	anchor = env->point_list;
	ft_printf("before: address of env->point_list: %p\nnow, the isometric transformed points:\n", env->point_list);
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp[0] = ((int *) env->point_list->content)[0];
			temp[1] = ((int *) env->point_list->content)[1];
			temp[2] = ((int *) env->point_list->content)[2];
			((int *) env->point_list->content)[0] = ft_isometric_transform('x', temp[0], temp[1], temp[2]);
			((int *) env->point_list->content)[1] = ft_isometric_transform('y', temp[0], temp[1], temp[2]);
			// ft_printf("x : %d, y: %d\n", ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1]);
			// finding x_max, x_min, y_max, y_min
			if ((int)((int *) env->point_list->content)[0] > (int)x_max)
			{
				x_max = ((int *) env->point_list->content)[0];
				// ft_printf("x_max reset to %d\n", (int)x_max);
			}
			if ((int)((int *) env->point_list->content)[0] < (int)x_min)
			{
				x_min = ((int *) env->point_list->content)[0];
				// ft_printf("x_min reset to %d\n", (int)x_min);
			}
			if ((int)((int *) env->point_list->content)[1] > (int)y_max)
			{
				y_max = ((int *) env->point_list->content)[1];
				// ft_printf("y_max reset to %d\n", (int)y_max);
			}
			if ((int)((int *) env->point_list->content)[1] < (int)y_min)
			{
				y_min = ((int *) env->point_list->content)[1];
				// ft_printf("y_min reset to %d\n", (int)x_min);
			}
			env->point_list = env->point_list->next;
		}
	}

	ft_printf("x_min: %d ", x_min);
	ft_printf("x_max: %d ", x_max);
	ft_printf("y_max: %d ", y_max);
	ft_printf("y_min: %d\n", y_max);
	// defining zoom from maximum and minimum values
	ft_printf("zoom: %d\n", (int)(zoom));
	while  ((((x_max - x_min) * zoom) < (int)WINDOW_WIDTH) && (((y_max - y_min) * zoom) < (int)WINDOW_HEIGHT))
		zoom += 0.1;
	printf("zoom: %f\n", zoom);
	while  ((((x_max - x_min) * zoom) > (int)WINDOW_WIDTH) || (((y_max - y_min) * zoom) > (int)WINDOW_HEIGHT))
		zoom -= 0.1;
	while  (((x_max * zoom) > (int)WINDOW_WIDTH) || (((y_max) * zoom) > (int)WINDOW_HEIGHT))
		zoom -= 0.1;
	zoom -= 10.25;
	printf("zoom: %f\n", zoom);
	ft_printf("zoom: %d\n", (int)(zoom));

	// printing our points
	ft_printf("after: address of env->point_list: %p\n", env->point_list);
	env->point_list = anchor;
	ft_printf("after reset: address of env->point_list: %p\n", env->point_list);
	if (env->point_list)
	{
		while (env->point_list->next)
		{
			my_mlx_pixel_put(env, ((int *) env->point_list->content)[0] * zoom, ((int *) env->point_list->content)[1] * zoom, my_color_to_hex(env->color));
			env->point_list = env->point_list->next;
		}
	}
}

int	ft_isometric_transform(char c, int x, int y, int z)
{
	int	projected_coordinate;

	if (c == 'x')
		projected_coordinate = (1/sqrt(6)) * (sqrt(3) * x - sqrt(3) * z);
	else if (c == 'y')
		projected_coordinate = (1/sqrt(6)) * (x + 2 * y + z);
	else
		return(-1);
	return(projected_coordinate);
}

// void	ft_treat_point_list(t_env *env)
// {
// 	if (env->point_list)
// 	{
// 		while (env->point_list->next)
// 		{
// 			((int *) env->point_list->content)[0] = y;
// 			ft_printf("((int *) env->point_list->content)[0] is %d\n", ((int *) env->point_list->content)[0]);
// 			env->point_list = env->point_list->next;
// 		}
// 	}

// int	*ft_center_in_window(int	*point)
// {
// }

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

int	my_mlx_square_put(t_env *env, int x, int y, int color)
{
	x = WINDOW_WIDTH / 4;
	y = WINDOW_HEIGHT / 4;
	while (x++ < WINDOW_WIDTH * 3/4)
	{
		while (y++ < WINDOW_HEIGHT * 3/4)
			my_mlx_pixel_put(env, x, y, color);
		y = WINDOW_HEIGHT / 4;
	}
	return (0);
}
