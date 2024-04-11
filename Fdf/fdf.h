/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:42 by fallan            #+#    #+#             */
/*   Updated: 2024/04/11 17:31:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"
#include "./lib/get_next_line/get_next_line.h"
#include "./lib/minilibx/mlx.h"

#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH 800
#endif

#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 600
#endif

#ifndef WINDOW_NAME
#define WINDOW_NAME "mlx test window"
#endif

typedef struct s_point{
	int				x;
	int				y;
	int				z;
	int				line_count;
	int				column_count;
} 	t_point;

typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_list	*point_list;
}				t_env;

// input utils
int		ft_count_elements_in_2d_char_array(char **array);
int		*ft_examine_lines(int fd);
void	ft_print_map(int **map, int* line_data);
t_point	*ft_fill_list_element(char **split_string, int i, int j, int *line_data);
t_list	*ft_file_to_point_list(int fd, int *line_data);
void	ft_print_point_list(t_list *point_list);

// graph utils
int		my_color_to_hex(char *color);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color);
t_point	*ft_isometric_transform(t_point *point);
void	ft_put_isometric_projection(t_env *env);
int		key_handler(t_env *env, int keycode);
void	launch_window_and_draw(t_list **point_list);
int		mlx_launch_window(void);