// key hook handler for key pressing events:
// 1. ESC closes the window and stops the program
// 2. any other key launches the graph drawing functions
// and displays the output in a mlx-handled window
int	key_handler(int keycode, t_env *env)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		ft_printf("ESC key pressed, program stopping\n");
		ft_printf("env->point_list address before free: {%p}", env->point_list);
		ft_free_list(env->point_list);
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		ft_printf("freeing list:\n");
		ft_exit(env);
	}
	else if (env->drawn && ((keycode == 8) || (keycode == 117)))
	{
		ft_printf("Graph drawn, clearing window\n");
		mlx_clear_window(env->mlx, env->win);
	}
	else if (!(env->drawn)) 
	{
		ft_draw(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		env->drawn = 1;
	}
	else if ((env->drawn))
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

// window closer, is called if the window is closed with the mouse
int	window_closed(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	printf("freeing list:\n");
	ft_exit(env);
	exit(1);
}

// program closer, frees the list's memory and exits
void	ft_exit(t_env *env)
{
	ft_free_list(env->point_list);
	exit(1);
}