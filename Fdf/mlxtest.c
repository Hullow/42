/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/03/26 19:00:20 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	else if (*s1 > 0 && *s2 == 0)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else if (*s1 == 0 && *s2 > 0)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else
	{
		while (n > 0 && *s1 && *s2)
		{
			if (*s1 == *s2)
				n--;
			else if (*s1 > *s2)
				return ((unsigned char) *s1 - (unsigned char) *s2);
			else if (*s1 < *s2)
				return ((unsigned char) *s1 - (unsigned char) *s2);
			if (n != 0)
			{
				s1++;
				s2++;
			}
		}
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
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
	return (0);
}

int main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	
	env.color = "purple";
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
