/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/05/02 15:35:59 by fallan           ###   ########.fr       */
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
		ft_graph_transformation(env->point_list);
		ft_put_point_list(env);
		// ft_print_point_list(env);
		ft_draw_line_to_next_point(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		env->drawn = 1;
	}
	// else if (env->drawn == 1)
	// 	ft_printf("image already drawn, please press ESC to stop the program, and try again\n");
	return (0);
}

int	close_window(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	mlx_destroy_window(env->mlx, env->win);
	exit(1);
}
