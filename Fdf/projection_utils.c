/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/05/03 16:47:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* uses the minimal and maximal values of x and y
to calculate a centering vector which is used to
center the points */
void	ft_center_points(t_list *point_list, int *minmax)
{
	t_list	*anchor;
	int		cent_vect[2];

	anchor = point_list;
	cent_vect[0] = 0;
	cent_vect[1] = 0;
	while (cent_vect[0] + minmax[0] - ((minmax[0] - minmax[2]) / 2) \
	< WINDOW_WIDTH / 2)
		cent_vect[0]++;
	while (cent_vect[1] + minmax[1] - ((minmax[1] - minmax[3]) / 2) \
	< WINDOW_HEIGHT / 2)
		cent_vect[1]++;
	while (cent_vect[0] + minmax[0] - ((minmax[0] - minmax[2]) / 2) \
	> WINDOW_WIDTH / 2)
		cent_vect[0]--;
	while (cent_vect[1] + minmax[1] - ((minmax[1] - minmax[3]) / 2) \
	> WINDOW_HEIGHT / 2)
		cent_vect[1]--;
	while (point_list)
	{
		((int *)point_list->content)[0] += cent_vect[0];
		((int *)point_list->content)[1] += cent_vect[1];
		point_list = point_list->next;
	}
	free(minmax);
	point_list = anchor;
}

/* finds the minimal and maximal x and y values 
for the whole point list */
int	*ft_min_max(t_list *point_list)
{
	t_list	*anchor;
	int		*minmax;

	anchor = point_list;
	minmax = (int *)malloc(sizeof(int) * 4);
	minmax[0] = 0;
	minmax[1] = 0;
	minmax[2] = 0;
	minmax[3] = 0;
	while (point_list)
	{
		if (((int *)point_list->content)[0] > minmax[0])
			minmax[0] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[0] < minmax[2])
			minmax[2] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[1] > minmax[1])
			minmax[1] = ((int *)point_list->content)[1];
		if (((int *)point_list->content)[1] < minmax[3])
			minmax[3] = ((int *)point_list->content)[1];
		point_list = point_list->next;
	}
	point_list = anchor;
	return (minmax);
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

/* pt[3]: #lines
pt[4]: #columns */

void	ft_isometric_projection(t_list *point_list)
{
	t_list	*anchor;
	int		pt[5];
	int		size;
	double	a;

	anchor = point_list;
	a = 30 * (M_PI / 180);
	pt[3] = ((int *)point_list->content)[3];
	pt[4] = ((int *)point_list->content)[4];
	size = 1;
	while (size * pt[4] < WINDOW_WIDTH && size * pt[3] < WINDOW_HEIGHT)
		size++;
	while (point_list)
	{
		pt[0] = ((int *)point_list->content)[0];
		pt[1] = ((int *)point_list->content)[1];
		pt[2] = ((int *)point_list->content)[2];
		// ((int *)point_list->content)[0] = (int)(pt[0] * cos(a + 2) + pt[1] * cos(a + 2) + pt[2] * cos(a - 2)) * (size / 2);
		// ((int *)point_list->content)[1] = (int)(pt[0] * sin(a) + pt[1] * sin(a + 2) + pt[2] * sin(a - 2)) * (size / 2);
		// ((int *)point_list->content)[0] = (1/sqrt(6)) * (sqrt(3) * pt[0] - sqrt(3) * pt[2]) * (size / 2);
		// ((int *)point_list->content)[1] = (1/sqrt(6)) * (pt[0] + 2 * pt[1] + pt[2]) * (size / 2);
		// ((int *)point_list->content)[0] = (pt[0] - pt[1]) * cos(a);
		// ((int *)point_list->content)[1] = (int) pt[1] + ((pt[0] + pt[2]) * sin(a)) / sqrt(2);

		((int *)point_list->content)[0] = (size / 2) * (pt[0] * cos(a) + pt[1] * cos(a + (4 * a)) + pt[2] * cos(a - (4 * a)));
		((int *)point_list->content)[1] = (size / 2) * (pt[0] * sin(a) + pt[1] * sin(a + (4 * a)) + pt[2] * sin(a - (4 * a)));

		point_list = point_list->next;
	}
	point_list = anchor;
}

void	ft_z_axis_rotation(t_list *point_list)
{
	int	pt[3];
	int	a;

	a = 0 * (M_PI / 180);
	while (point_list)
	{
		pt[0] = ((int *)(point_list->content))[0];
		pt[1] = ((int *)(point_list->content))[1];
		pt[2] = ((int *)(point_list->content))[2];

		((int *)(point_list->content))[0] = cos(a) * pt[0] - sin(a) * pt[1];
		((int *)(point_list->content))[1] = sin(a) * pt[0] - cos(a) * pt[1];
		// ((int *)(point_list->content))[0] = cos(a) * pt[0] - sin(a) * pt[2];
		// ((int *)(point_list->content))[2] = -sin(a) * pt[0] + cos(a) * pt[1];
		point_list = point_list->next;
	}
}