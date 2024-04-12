/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/12 17:40:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

int	*ft_isometric_transform(int *point)
{
	int	*projected_point;

	projected_point = (int *)malloc (2 * sizeof(int));
	projected_point[0] = (1/sqrt(6)) * (sqrt(3) * point[0] - sqrt(3) * point[2]); // cx
	projected_point[1] = (1/sqrt(6)) * (point[0] + 2 * point[1] + point[2]); // cy
	// cz = (1/sqrt(6)) * (sqrt(2) * point.x - sqrt(2) * point.y + sqrt(2) * point.z);
	return(projected_point);
}

void	launch_window_and_draw(t_list **point_list)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	env.point_list = *point_list;
	env.color = "red";
	ft_printf("launch_window_and_draw: env address: %p, &env:%p\n", env, &env);
	// if (env.point_list)
	// {
	// 	while (env.point_list->next)
	// 	{
	// 		int *temp = (int *)env.point_list->content;
	// 		ft_printf("launch_window: env.point_list->content not NULL, it is %d, %d\n", temp[0], temp[1]);
	// 		env.point_list = env.point_list->next;
	// 	}
	// }
	// ft_put_isometric_projection(env);
	mlx_hook(env.win, 2, 1L<<0, key_handler, &env);
	mlx_loop(env.mlx);
}

int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		printf("ESCAPE\n");
	else
	{
		ft_printf("key_handler: env is %p and &env is %p\n", env, &env);
		ft_put_isometric_projection(env);
	}
	return (0);
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

void	ft_put_isometric_projection(t_env *env)
{
	// int	*projected_point;
	// int i = 1;
	
	// int *temp = (int *)env->point_list->content;
	// t_list *anchor = env->point_list;
	if (env->point_list)
	{
		ft_printf("ft_put_isometric_projection: env address is : %p, &env is : %p\n", env, &env);
		ft_printf("env->point_list address: %p\n", env->point_list);
		// while (env->point_list->next)
		// {
		// 	ft_printf("ft_put_isometric_projection: env->point_list->content not NULL, it is %d, %d\n", temp[0], temp[1]);
		// 	env->point_list = env->point_list->next;
		// }
	}
	// ft_printf("env->point_list->content[0] not NULL, it is %d\n", temp[0]);
	// projected_point = ft_isometric_transform(env->point_list->content);
	// ft_printf("point %d: x: %d, y: %d\n", i, projected_point[x], projected_point[y]);
	// my_mlx_pixel_put(env, projected_point[x] + (WINDOW_WIDTH / 2), projected_point[y] + (WINDOW_HEIGHT / 2), 0x00FFFFFF);
	
	// while (env->point_list)
	// {
	// 	projected_point = ft_isometric_transform(env->point_list->content);
	// 	ft_printf("point %d: x: %d, y: %d\n", i, projected_point[x], projected_point[y]);
	// 	my_mlx_pixel_put(env, projected_point[x] + (WINDOW_WIDTH / 2), projected_point[y] + (WINDOW_HEIGHT / 2), 0x00FFFFFF);
	// 	free(projected_point);
	// 	i++;
	// 	env->point_list = env->point_list->next;
	// }
	ft_printf("my_mlx_pixel_put_passed\n");
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