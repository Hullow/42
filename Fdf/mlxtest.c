/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/11 15:19:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/libft/libft.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_env;

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

int	my_mlx_triangle_put(t_env *env, int i, int color)
{
	printf("WINDOW_HEIGHT == %d\n", WINDOW_HEIGHT);
	printf("WINDOW_WIDTH) == %d\n", WINDOW_WIDTH);
	while (++i < WINDOW_HEIGHT / 2)
		my_mlx_pixel_put(env, i, WINDOW_HEIGHT - i, color);
	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
		my_mlx_pixel_put(env, (WINDOW_HEIGHT / 2) + i, (WINDOW_HEIGHT / 2) + i, color);
	while (i-- > - (WINDOW_HEIGHT / 2))
		my_mlx_pixel_put(env, (WINDOW_HEIGHT / 2) + i, WINDOW_HEIGHT - 1, color);
	return (0);
}

int	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color)
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
			my_mlx_pixel_put(env, x1, y1, "white");
	}

}

int	my_mlx_hexagon_put(t_env *env, int i, int color)
{
	printf("WINDOW_HEIGHT == %d\n", WINDOW_HEIGHT);
	printf("WINDOW_WIDTH) == %d\n", WINDOW_WIDTH);
	int center[2] = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
	int	edge_x1;
	int	edge_x2;
	int	edge_y1;
	int	edge_y2;

	// if (WINDOW_HEIGHT <= WINDOW_WIDTH)
		edge_y1 = center[1] - WINDOW_HEIGHT * 1/4;
		edge_y2 = center[1] + WINDOW_HEIGHT * 1/4;
		edge_x1 = center[0] - WINDOW_HEIGHT * 1/4;
		edge_x2 = center[0] + WINDOW_HEIGHT * 1/4;

		int hex_edge_y1 = center[1] - WINDOW_HEIGHT * 1/12;
		int hex_edge_y2 = center[1] + WINDOW_HEIGHT * 1/12;

		int y = hex_edge_y1 - 1;
		while (++y < hex_edge_y2)
			my_mlx_pixel_put(env, edge_x1, y, color);
		while (--y > hex_edge_y1 - 1)
			my_mlx_pixel_put(env, edge_x2, y, color);
		
		int hex_edge_x1 = center[0] - WINDOW_HEIGHT * 1/12;
		int hex_edge_x2 = center[0] + WINDOW_HEIGHT * 1/12;
		
		int x = hex_edge_x1 - 1;
		while (++x < hex_edge_x2)
			my_mlx_pixel_put(env, x, edge_y1, color);
		while (--x > hex_edge_x1 - 1)
			my_mlx_pixel_put(env, x, edge_y2, color);

	x = edge_x1 - 1;
	y = hex_edge_y1 + 1;
	while (++x < hex_edge_x1 && --y > edge_y1)
			my_mlx_pixel_put(env, x, y, color);

	x = hex_edge_x2;
	while (x++ <= edge_x2 && y++ <= hex_edge_y1)
			my_mlx_pixel_put(env, x - 1, y - 1, color);

	my_mlx_pixel_put(env, center[0], center[1], color);
	my_mlx_pixel_put(env, edge_x1, edge_y1, color);
	my_mlx_pixel_put(env, edge_x1, edge_y2, color);
	my_mlx_pixel_put(env, edge_x2, edge_y1, color);
	my_mlx_pixel_put(env, edge_x2, edge_y2, color);
	
	i = 0;
	return (0);
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

int main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	
	env.color = "white";
	mlx_hook(env.win, 2, 1L<<0, key_handler, &env);
	mlx_loop(env.mlx);
}

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx test window");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_square_put(3, &img, 500, 500, my_color_to_hex("purple"));
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
