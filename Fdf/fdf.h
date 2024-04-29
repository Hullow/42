/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:42 by fallan            #+#    #+#             */
/*   Updated: 2024/04/29 14:32:15 by fallan           ###   ########.fr       */
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

typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		drawn;
	t_list	*point_list;
}				t_env;

// input utils
int		ft_count_elements_in_2d_char_array(char **array);
int		*ft_examine_lines(int fd);
void	ft_print_map(int **map, int* line_data);
int		*ft_fill_point(char **split_string, int i, int j, int *line_data);
t_list	*ft_file_to_point_list(int fd, int i, int *line_data);
void	ft_treat_point_list(t_env *env);

// graph handling utils
int		my_color_to_hex(char *color);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	my_mlx_line_put(t_env *env, int x1, int y1, int x2, int y2, int color);
void	ft_draw_line_to_next_point(t_env *env);
int		my_mlx_square_put(t_env *env, int x, int y, int color);
void	ft_put_point_list(t_env *env);

// graph transformation utils
void	ft_graph_transformation(t_list	*point_list);
void	ft_isometric_projection(t_list *point_list);
float	ft_calculate_zoom(t_list	*point_list);
void	ft_apply_zoom(t_list	*content, float zoom);
void	ft_center_points(t_list *point_list);

// window and event handling
void	launch_window_and_draw(t_list *point_list);
int		close_window(t_env *env);
int		key_handler(int keycode, t_env *env);
int		mouse_handler(int button, t_env *env);

void	ft_print_point_list(t_env *env);