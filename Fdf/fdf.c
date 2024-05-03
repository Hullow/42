/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:22:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/03 18:07:21 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "mlx test window"

// creates a new mlx window with
// hooks for key presses, launching
// key_handler, and for mouse clicks that
// close the window on event: ON_DESTROY = 17
void	launch_window_and_draw(t_list *point_list)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
	&env.line_length, &env.endian);
	env.point_list = point_list;
	env.drawn = 0;
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 0, window_closed, &env);
	mlx_loop(env.mlx);
}

// key hook handler for key pressing events:
// 1. ESC closes the window and stops the program
// 2. any other key launches the graph drawing functions
// and displays the output in a mlx-handled window
int	key_handler(int keycode, t_env *env)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		ft_printf("ESC key pressed, program stopping\n");
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	else if (!(env->drawn))
	{
		ft_z_axis_rotation(env->point_list);
		ft_isometric_projection(env->point_list);
		float zoom = ft_calculate_zoom(env->point_list);
		ft_apply_zoom(env->point_list, zoom);
		ft_center_points(env->point_list, ft_min_max(env->point_list));
		ft_draw_points(env);
		ft_draw_lines(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		env->drawn = 1;
	}
	else if (env->drawn)
		ft_printf("Graph already drawn, nothing to do!\n");
	return (0);
}

// program closer, is called if the window is closed with the mouse
int	window_closed(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	mlx_destroy_window(env->mlx, env->win);
	exit(1);
}

void	ft_free_list(t_list *point_list)
{
	t_list	*temp;

	temp = NULL;
	while (point_list)
	{
		temp = point_list;
		point_list = point_list->next;
		free(temp);
	}
}

t_list	*ft_file_to_list(int fd, char *arg)
{
	int		*line_data;

	line_data = malloc(sizeof(int) * 2);
	if (!line_data)
	{
		ft_printf("ft_file_to_list: malloc fail\n");
		return (NULL);
	}
	line_data[0] = 0;
	line_data = ft_examine_lines(fd, line_data);
	close(fd);
	fd = open(arg, O_RDONLY);
	return (ft_fill_list(fd, line_data));
}

// the main function opens the file,
// sends it to the input handling functions,
// then calls the window/event handling functions,
// which call the graph handling and drawing functions
int	main(int argc, char *argv[])
{
	int		fd;

	t_list	*point_list;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s opened\n", argv[1]);
			point_list = ft_file_to_list(fd, argv[1]);
			launch_window_and_draw(point_list);
			ft_free_list(point_list);
		}
	}
	else
		ft_printf("missing arguments\n");
	return (0);
}

/*
for debugging purposes
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
			printf("pt %d: (%d,%d), l:%d, c:%d – ", i++, \
			temp[0], temp[1], temp[3], temp[4]);
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
}
*/
