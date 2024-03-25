/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:07:40 by fallan            #+#    #+#             */
/*   Updated: 2024/03/25 19:06:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_mlx_square_put(t_data *data, int x, int y, int color)
{
	x = 500;
	y = 500;
	while (x++ < 600)
	{
		while (y++ < 600)
			my_mlx_pixel_put(data, x, y, color);
		y = 500;
	}
	return (0);
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

typedef struct	s_params {
	t_data	*img;
	int		x;
	int		y;
	int		color;
}				square_params;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}



int main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx test window");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	// int (*put_square_pointer)(t_data *data, int x, int y, int color) = &my_mlx_put_square_put;
	// square_params params = {&img, 500, 500, my_color_to_hex("yellow")};

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	// mlx_hook(mlx_win, 2, 1L<<0, my_mlx_square_put, &params);
	// mlx_mouse_hook(mlx, my_mlx_put_square_put, &params);
	t_vars vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}

// Triangle