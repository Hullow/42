/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/09 16:16:43 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/libft/libft.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

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

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		printf("ESCAPE\n");
	else if (keycode == 2)
		printf("d\n");
	else if (keycode == 1)
	{
		printf("key pressed: s, drawing a square\n");
		my_mlx_square_put(env, 500, 500, my_color_to_hex(env->color));
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (keycode == 17)
	{
		printf("key pressed: t, drawing a triangle\n");
		my_mlx_triangle_put(env, -1, my_color_to_hex(env->color));
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (keycode == 4)
	{
		printf("key pressed: h, drawing a hexagon\n");
		my_mlx_hexagon_put(env, -1, my_color_to_hex(env->color));
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	return (0);
}

// int mlx_demo()
// {
// 	t_env	env;

// 	env.mlx = mlx_init();
// 	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
// 	env.img = mlx_new_image(env.mlx, 800, 600);
// 	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	
// 	env.color = "white";
// 	mlx_hook(env.win, 2, 1L<<0, key_handler, &env);
// 	mlx_loop(env.mlx);
// }

int mlx_launch_window()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_square_put(3, &img, 500, 500, my_color_to_hex("purple"));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
