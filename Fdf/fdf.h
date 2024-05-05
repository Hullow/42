/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:42 by fallan            #+#    #+#             */
/*   Updated: 2024/05/05 12:41:28 by fallan           ###   ########.fr       */
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
#define WINDOW_WIDTH 1200
#endif

#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 900
#endif

#ifndef WINDOW_NAME
#define WINDOW_NAME "Fil de Fer"
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
int		ft_count_array_elements_debug(char **array);
int		ft_count_array_elements(char **array);
int		ft_hex_string_to_int(char *hex_string);
char	*ft_whitespace_to_space(char *str);
void	ft_free_list(t_list *point_list);

// for debugging:
void	ft_print_point_list(t_env *env);
void	ft_max_altitude(t_list *point_list);

// input handling
int		*ft_examine_lines(int fd, int *line_data);
int		*ft_fill_point(char **split_string, int i, int j, int *line_data);
t_list	*ft_fill_list(int fd, int *line_data, int i, int j);
t_list	*ft_file_to_list(int fd, char *input);

// graph transformation
int		*ft_min_max(t_list *point_list);
void	ft_center_points(t_list *point_list, int *min_max);
void	ft_isometric_projection(t_list *point_list);
int		*ft_min_max(t_list *point_list);
float	ft_calculate_zoom(int *min_max, int WIN_W, int WIN_H);
void	ft_apply_zoom(t_list *point_list, float zoom);
void	ft_z_axis_rotation(t_list *point_list);

// graph utils
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	ft_line_put(t_env *env, int x1, int y1, int x2, int y2, int color);

// drawing functions
void	ft_draw(t_env *env);
void	ft_draw_points(t_env *env);
void	ft_draw_lines(t_env *env);
void	ft_draw_horizontal(t_env *env, int *coord, int i);
void	ft_draw_vertical(t_env *env, int *coord, int columns);

// window and event handling
void	launch_window_and_draw(t_list *point_list);
int		window_closed(t_env *env);
int		key_handler(int keycode, t_env *env);
