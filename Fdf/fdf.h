/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:42 by fallan            #+#    #+#             */
/*   Updated: 2024/04/09 16:15:55 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/get_next_line/get_next_line.h"
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH 800

#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 600

#ifndef WINDOW_NAME
#define WINDOW_NAME "mlx test window"

#endif

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

// mlx functions
int		my_color_to_hex(char *color);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
int		key_handler(int keycode, t_env *env);
int		mlx_demo();