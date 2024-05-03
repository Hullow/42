/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:22:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/03 11:09:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

// creates a new mlx window with
// hooks for watches for a key press
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
	mlx_hook(env.win, 17, 0, close_window, &env);
	mlx_loop(env.mlx);
}

// handles key pressing events
// ESC closes the window and stops the program
// any other key launches the graph drawing functions
// and displays the output in a mlx-handled window
int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		ft_printf("ESCAPE key pressed, program stopping\n");
		mlx_destroy_window (env->mlx, env->win);
		exit(1);
	}
	else
	{
		ft_isometric_projection(env->point_list);
		ft_center_points(env->point_list, ft_min_max(env->point_list));
		ft_draw_points(env);
		ft_draw_lines(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	return (0);
}

int	close_window(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	mlx_destroy_window(env->mlx, env->win);
	exit(1);
}

// the main function opens the file,
// sends it to the input handling functions,
// then calls the window/event handling functions,
// which call the graph handling and drawing functions
int main(int argc, char *argv[])
{
	int	fd;
	int	*line_data = NULL;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s opened\n", argv[1]);
			line_data = ft_examine_lines(fd);
			close(fd);
			fd = open(argv[1], O_RDONLY);
			t_list *point_list;
			t_list *temp;
			point_list = ft_file_to_point_list(fd, -1, line_data);
			temp = point_list;
			launch_window_and_draw(temp);
		}
	}
	else
	{
		line_data[0] = 0;
		line_data[1] = 0;
		ft_printf("missing arguments\n");
	}
 	return (0);
}

/* for debugging purposes
void	ft_print_point_list(t_env *env)
{
	int i = 0;
	t_list	*anchor = env->point_list;
	int	*temp;

	temp = (int *)malloc (5 * sizeof(int));
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp = (int *) env->point_list->content;
			printf("pt %d: (%d,%d), l:%d, c:%d – ", i++, temp[0], temp[1], temp[3], temp[4]);
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
}
*/