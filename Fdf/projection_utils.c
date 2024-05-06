/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/05/06 15:09:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* uses the minimal and maximal values of x and y
to calculate a centering vector which is used to
center the points */
void	ft_center_points(t_list *point_list, double *min_max)
{
	double	cent_vect[2];

	cent_vect[0] = 0;
	cent_vect[1] = 0;
	while (cent_vect[0] + min_max[0] - ((min_max[0] - min_max[2]) / 2) \
	< WINDOW_WIDTH / 2)
		cent_vect[0]++;
	while (cent_vect[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) \
	< WINDOW_HEIGHT / 2)
		cent_vect[1]++;
	while (cent_vect[0] + min_max[0] - ((min_max[0] - min_max[2]) / 2) \
	> WINDOW_WIDTH / 2)
		cent_vect[0]--;
	while (cent_vect[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) \
	> WINDOW_HEIGHT / 2)
		cent_vect[1]--;
	while (point_list)
	{
		((double *)point_list->content)[0] += cent_vect[0];
		((double *)point_list->content)[1] += cent_vect[1];
		point_list = point_list->next;
	}
	free(min_max);
}

// iterates through list to find min max values
// output: 
// min_max[0]: x_max, min_max[1]: y_max
// min_max[2]: x_min, min_max[3]: y_min
double	*ft_min_max(t_list *point_list)
{
	double	*min_max;

	min_max = (double *)malloc(sizeof(double) * 4);
	min_max[0] = 0;
	min_max[1] = 0;
	min_max[2] = 0;
	min_max[3] = 0;
	while (point_list)
	{
		if (((double *)point_list->content)[0] > min_max[0])
			min_max[0] = ((double *)point_list->content)[0];
		if (((double *)point_list->content)[0] < min_max[2])
			min_max[2] = ((double *)point_list->content)[0];
		if (((double *)point_list->content)[1] > min_max[1])
			min_max[1] = ((double *)point_list->content)[1];
		if (((double *)point_list->content)[1] < min_max[3])
			min_max[3] = ((double *)point_list->content)[1];
		point_list = point_list->next;
	}
	return (min_max);
}

double	ft_calculate_zoom(double *min_max, int WIN_W, int WIN_H)
{
	double	zoom;

	zoom = 1;
	printf("zoom at start: %f\n", zoom);
	while (zoom * (min_max[0] - min_max[2]) < WIN_W * 0.75 && \
	zoom * (min_max[1] - min_max[3]) < WIN_H * 0.75)
		zoom += 0.1;
	printf("zoom: %f\n", zoom);
	while (zoom * (min_max[0] - min_max[2]) > WIN_W * 0.75 || \
	zoom * (min_max[1] - min_max[3]) > WIN_H * 0.75)
		zoom -= 0.1;
	ft_printf("zoom: %d\n", (int)(zoom));
	free(min_max);
	return (zoom);
}

void	ft_apply_zoom(t_list *point_list, float zoom)
{
	while (point_list)
	{
		((double *)point_list->content)[0] *= zoom;
		((double *)point_list->content)[1] *= zoom;
		point_list = point_list->next;
	}
}

// z_rotation (try with 45 degrees)
void	ft_z_rotation(t_list *point_list)
{
	double	pt[3];
	float	a;

	a = 45 * (M_PI / 180);
	while (point_list)
	{
		pt[0] = ((double *)(point_list->content))[0];
		pt[1] = ((double *)(point_list->content))[1];
		pt[2] = ((double *)(point_list->content))[2];
		((double *)(point_list->content))[0] = (cos(a) * pt[0] - sin(a) * pt[1]);
		((double *)(point_list->content))[1] = (sin(a) * pt[0] + cos(a) * pt[1]);
		((double *)(point_list->content))[2] = pt[2];
		point_list = point_list->next;
	}
}

// x_rotation (try with arctan(sqrt2))
void	ft_x_rotation(t_list *point_list)
{
	double	a;
	double	rotation[3];
	double	pt[5];

	a = atan(1/sqrt(2));
	while (point_list)
	{
		pt[0] = ((double *)point_list->content)[0];
		pt[1] = ((double *)point_list->content)[1];
		pt[2] = ((double *)point_list->content)[2];
 		rotation[0] = pt[0];
		rotation[1] = cos(a) * pt[1] - sin(a) * pt[2];
		rotation[2] = sin(a) * pt[1] + cos(a) * pt[2];
 		((double *)point_list->content)[0] =  rotation[0];
		((double *)point_list->content)[1] =  rotation[1];
		((double *)point_list->content)[2] =  rotation[2];
		point_list = point_list->next;
	}
}

void	ft_orthographic_projection(t_list *point_list)
{
	double		pt[3];
	double		projection[2];
	double		scale;

	scale = 1;
	while (point_list)
	{
		pt[0] = (double)((double *)point_list->content)[0];
		pt[1] = (double)((double *)point_list->content)[1];
		pt[2] = (double)((double *)point_list->content)[2];
		projection[0] = (scale * (pt[0] - pt[1]));
		projection[1] = (scale * ((pt[0] + pt[1]) / (2 - pt[2])));
		((double *)point_list->content)[0] =  projection[0];
		((double *)point_list->content)[1] =  projection[1];
		point_list = point_list->next;
	}
}
