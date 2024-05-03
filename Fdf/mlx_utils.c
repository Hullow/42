/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:08 by fallan            #+#    #+#             */
/*   Updated: 2024/05/03 23:04:20 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// draws a pixel
void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	// if (color == 255)
	// 	return ;
	char	*dst;

	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// DDA line drawing algorithm
// 1. calculate steps required for generating pixels
// 2. put pixels for each step
void	ft_line_put(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	float	X;
	float	Y;
	int		steps;
	int		i;

    if (abs(x2 - x1) > abs(y2 - y1))
		steps = abs(x2 - x1);
	else
		steps = abs(y2 - y1);
    X = x1;
	Y = y1;
	i = 0;
    while (i <= steps)
	{
		my_mlx_pixel_put(env, round(X), round(Y), color);
        X += (x2 - x1) / (float)steps; // increment in x at each step
        Y += (y2 - y1) / (float)steps; // increment in y at each step
		i++;
	}
}
