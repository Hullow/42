/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_transformation_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/04/29 17:32:36 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Applies all the graphical transforms to our point coordinates
void	ft_graph_transformation(t_list *point_list)
{
	float	zoom;

	zoom = 1;
	if (point_list)
	{
		ft_printf("before manipulating points: point_list: {%p}\n", point_list);
		ft_isometric_projection(point_list);
		// zoom = ft_calculate_zoom(point_list);
		ft_apply_zoom(point_list, zoom);
		ft_center_points(point_list);
		ft_printf("after manipulating points: point_list: {%p}\n", point_list);
	}
}

// Centering our projection in the window:
// 1. finding our min max values
// 2. 
// the initial center is : x_max - ((x_max - x_min) / 2);
// we want to move the initial center to the desired center, which is WINDOW_WIDTH/HEIGHT / 2
void	ft_center_points(t_list *point_list)
{
	t_list	*anchor;
	int		centering_vector[2];
	int		x_max = 0;
	int		y_max = 0;
	int		x_min = 0;
	int		y_min = 0;

	centering_vector[0] = 0;
	centering_vector[1] = 0;
	anchor = point_list;
	while (point_list)
	{
		if (((int *)point_list->content)[0] > x_max)
			x_max = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[0] < x_min)
			x_min = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[1] > y_max)
			y_max = ((int *)point_list->content)[1];
		if (((int *)point_list->content)[1] < y_min)
			y_min = ((int *)point_list->content)[1];
		point_list = point_list->next;
	}
	// ft_printf("x_min: %d ", x_min);
	// ft_printf("x_max: %d ", x_max);
	// ft_printf("y_max: %d ", y_max);
	// ft_printf("y_min: %d\n", y_max);

	while (centering_vector[0] + x_max - ((x_max - x_min) / 2) < WINDOW_WIDTH / 2)
		centering_vector[0]++;
	while (centering_vector[1] + y_max - ((y_max - y_min) / 2) < WINDOW_HEIGHT / 2)
		centering_vector[1]++;
	while (centering_vector[0] + x_max - ((x_max - x_min) / 2) > WINDOW_WIDTH / 2)
		centering_vector[0]--; 
	while (centering_vector[1] + y_max - ((y_max - y_min) / 2) > WINDOW_HEIGHT / 2)
		centering_vector[1]--;
	point_list = anchor;
	while (point_list)
	{
		((int *)point_list->content)[0] += centering_vector[0];
		((int *)point_list->content)[1] += centering_vector[1];
		point_list = point_list->next;
	}
}

float	ft_calculate_zoom(t_list *point_list)
{
	int		x_max = 0;
	int		y_max = 0;
	int		x_min = 0;
	int		y_min = 0;
	float 	zoom = 1;

	// finding our min max values
	while (point_list)
	{
		if (((int *)point_list->content)[0] > x_max)
			x_max = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[0] < x_min)
			x_min = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[1] > y_max)
			y_max = ((int *)point_list->content)[1];
		if (((int *)point_list->content)[1] < y_min)
			y_min = ((int *)point_list->content)[1];
		point_list = point_list->next;
	}

	// at the end : printing our min max values and setting the zoom
	ft_printf("x_min: %d ", x_min);
	ft_printf("x_max: %d ", x_max);
	ft_printf("y_max: %d ", y_max);
	ft_printf("y_min: %d\n", y_max);

	// defining zoom from maximum and minimum values
	while  ((float)(x_max - x_min) * zoom < (float)WINDOW_WIDTH * 3/4 && (float)(y_max - y_min) * zoom < (float)WINDOW_HEIGHT * 3/4)
		zoom += 0.1;
	printf("zoom: %f\n", zoom);
	while  ((float)(x_max - x_min) * zoom > (float)WINDOW_WIDTH * 3/4 || (float)(y_max - y_min) * zoom > (float)WINDOW_HEIGHT * 3/4)
		zoom -= 0.1;
	printf("zoom: %f\n", zoom);
	ft_printf("zoom: %d\n", (int)(zoom));
	return (zoom);
}

void	ft_apply_zoom(t_list *point_list, float zoom)
{
	while (point_list)
	{
		((int *)point_list->content)[0] *= zoom;
		((int *)point_list->content)[1] *= zoom;
		point_list = point_list->next;
	}
}

void	ft_isometric_projection(t_list *point_list)
{
	int	temp[5];
	int	size;

	temp[3] = ((int *)point_list->content)[3]; // #lines
	temp[4] = ((int *)point_list->content)[4]; // #columns
	size = 1;
	while (size * temp[4] < WINDOW_WIDTH && size * temp[3] < WINDOW_HEIGHT)
		size++;
	printf("size is %d\n", size);
	while (point_list)
	{
		temp[0] = ((int *)point_list->content)[0];
		temp[1] = ((int *)point_list->content)[1];
		temp[2] = ((int *)point_list->content)[2];
		((int *)point_list->content)[0] = (size / 2) * (temp[0] - temp[2]) / sqrt(2);
		((int *)point_list->content)[1] = (size / 2) * (temp[0] + 2 * temp[1] + temp[2]) / sqrt(6);
		point_list = point_list->next;
	}
}

/* 
void	ft_isometric_projection(t_list *point_list)
{
	int	temp[5];
	int	size;

	temp[3] = ((int *)point_list->content)[3]; // #lines
	temp[4] = ((int *)point_list->content)[4]; // #columns
	size = 1;
	while (size * temp[4] < WINDOW_WIDTH && size * temp[3] < WINDOW_HEIGHT)
		size++;
	printf("size is %d\n", size);
	while (point_list)
	{
		temp[0] = ((int *)point_list->content)[0];
		temp[1] = ((int *)point_list->content)[1];
		temp[2] = ((int *)point_list->content)[2];
		((int *)point_list->content)[0] = (1/sqrt(6)) * (sqrt(3) * temp[0] - sqrt(3) * temp[2]) * (size / 2);
		((int *)point_list->content)[1] = (1/sqrt(6)) * (temp[0] + 2 * temp[1] + temp[2]) * (size / 2);
		point_list = point_list->next;
	}
}
*/