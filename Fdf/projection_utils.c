/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/05/06 10:48:36 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* uses the minimal and maximal values of x and y
to calculate a centering vector which is used to
center the points */
void	ft_center_points(t_list *point_list, int *min_max)
{
	int		cent_vect[2];

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
		((int *)point_list->content)[0] += cent_vect[0];
		((int *)point_list->content)[1] += cent_vect[1];
		point_list = point_list->next;
	}
	free(min_max);
}

/* finds the minimal and maximal x and y values 
for the whole point list */
/* int	*ft_calculate_min_max_old(t_list *point_list)
{
	t_list	*anchor;
	int		*min_max;

	anchor = point_list;
	min_max = (int *)malloc(sizeof(int) * 4);
	min_max[0] = 0;
	min_max[1] = 0;
	min_max[2] = 0;
	min_max[3] = 0;
	while (point_list)
	{
		if (((int *)point_list->content)[0] > min_max[0])
			min_max[0] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[0] < min_max[2])
			min_max[2] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[1] > min_max[1])
			min_max[1] = ((int *)point_list->content)[1];
		if (((int *)point_list->content)[1] < min_max[3])
			min_max[3] = ((int *)point_list->content)[1];
		point_list = point_list->next;
	}
	point_list = anchor;
	return (min_max);
}
 */

// iterates through list to find min max values
// output: 
// min_max[0]: x_max, min_max[1]: y_max
// min_max[2]: x_min, min_max[3]: y_min
int	*ft_min_max(t_list *point_list)
{
	int		*min_max;

	min_max = (int *)malloc(sizeof(int) * 4);
	min_max[0] = 0;
	min_max[1] = 0;
	min_max[2] = 0;
	min_max[3] = 0;
	while (point_list)
	{
		if (((int *)point_list->content)[0] > min_max[0])
			min_max[0] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[0] < min_max[2])
			min_max[2] = ((int *)point_list->content)[0];
		if (((int *)point_list->content)[1] > min_max[1])
			min_max[1] = ((int *)point_list->content)[1];
		if (((int *)point_list->content)[1] < min_max[3])
			min_max[3] = ((int *)point_list->content)[1];
		point_list = point_list->next;
	}
	return (min_max);
}

float	ft_calculate_zoom(int *min_max, int WIN_W, int WIN_H)
{
	float	zoom;

	zoom = 1;
	printf("zoom at start: %f\n", zoom);
	while (zoom * (float)(min_max[0] - min_max[2]) < (float)WIN_W * 0.75 && \
	zoom * (float)(min_max[1] - min_max[3]) < (float)WIN_H * 0.75)
		zoom += 0.1;
	printf("zoom: %f\n", zoom);
	while (zoom * (float)(min_max[0] - min_max[2]) > (float)WIN_W * 0.75 || \
	zoom * (float)(min_max[1] - min_max[3]) > (float)WIN_H * 0.75)
		zoom -= 0.1;
	ft_printf("zoom: %d\n", (int)(zoom));
	free(min_max);
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
	double	a;
	int		pt[5];
	int		size;

	a = 30 * (M_PI / 180);
	pt[3] = ((int *)point_list->content)[3];
	pt[4] = ((int *)point_list->content)[4];
	size = 1;
	while (size * pt[4] < WINDOW_WIDTH && size * pt[3] < WINDOW_HEIGHT)
		size++;
	printf("size: %d\n", size);
	while (point_list)
	{
		pt[0] = ((int *)point_list->content)[0];
		pt[1] = ((int *)point_list->content)[1];
		pt[2] = ((int *)point_list->content)[2];
		// printf("projecting (%d,%d,%d) ", pt[0], pt[1], pt[2]);
		
		((int *)point_list->content)[0] = (size / 2) * (pt[0] * cos(a) + pt[1] * cos(a + (4 * a)) + pt[2] * cos(a - (4 * a)));
		((int *)point_list->content)[1] = (size / 2) * (pt[0] * sin(a) + pt[1] * sin(a + (4 * a)) + pt[2] * sin(a - (4 * a)));
		
		// printf("to (%d,%d)  –  ", ((int *)point_list->content)[0], ((int *)point_list->content)[1]);


		// ((int *)point_list->content)[0] = (int)(pt[0] * cos(a + 2) + pt[1] * cos(a + 2) + pt[2] * cos(a - 2)) * (size / 2);
		// ((int *)point_list->content)[1] = (int)(pt[0] * sin(a) + pt[1] * sin(a + 2) + pt[2] * sin(a - 2)) * (size / 2);

		// ((int *)point_list->content)[0] = (pt[0] - pt[1]) * cos(a);
		// ((int *)point_list->content)[1] = (int) pt[1] + ((pt[0] + pt[2]) * sin(a)) / sqrt(2);
		
		// ((int *)point_list->content)[0] = (1/sqrt(6)) * (sqrt(3) * pt[0] - sqrt(3) * pt[2]) * (size / 2);
		// ((int *)point_list->content)[1] = (1/sqrt(6)) * (pt[0] + 2 * pt[1] + pt[2]) * (size / 2);


		// ((int *)point_list->content)[0] = (1/sqrt(6)) * (sqrt(3) * pt[0] - sqrt(3) * pt[2]);
		// ((int *)point_list->content)[1] = (1/sqrt(6)) * (pt[0] + 2 * pt[1] + pt[2]);

		// https://stackoverflow.com/a/47520903
		// ((int *)point_list->content)[0] = (pt[0] - pt[2]) / sqrt(2);
		// ((int *)point_list->content)[1] = (pt[0] + 2 * pt[1] + pt[2]) / sqrt(6);

		point_list = point_list->next;
	}
}

// z_rotation (try with 45 degrees)
void	ft_z_rotation(t_list *point_list)
{
	int	pt[3];
	float	a;

	a = 45 * (M_PI / 180);
	printf("z_rotation angle in radians: %f\n", a);
	while (point_list)
	{
		pt[0] = ((int *)(point_list->content))[0];
		pt[1] = ((int *)(point_list->content))[1];
		pt[2] = ((int *)(point_list->content))[2];
		// printf("(%d,%d,%d)->", pt[0], pt[1], pt[2]);

		((int *)(point_list->content))[0] = cos(a) * pt[0] - sin(a) * pt[1];
		((int *)(point_list->content))[1] = sin(a) * pt[0] + cos(a) * pt[1];
		((int *)(point_list->content))[2] = pt[2];

		// printf("(%d,%d,%d)\n", ((int *)(point_list->content))[0], ((int *)(point_list->content))[1], ((int *)(point_list->content))[2]);
		point_list = point_list->next;
	}
}

// x_rotation (try with arctan(sqrt2))
void	ft_x_rotation(t_list *point_list)
{
	double	a;
	int		pt[5];

	a = atan(1/sqrt(2));
	printf("x rotation angle: %f\n", a);
	while (point_list)
	{
		pt[0] = ((int *)point_list->content)[0];
		pt[1] = ((int *)point_list->content)[1];
		pt[2] = ((int *)point_list->content)[2];

		((int *)point_list->content)[0] = pt[0];
		((int *)point_list->content)[1] = (cos(a) * pt[1]) - (sin(a) * pt[2]);
		((int *)point_list->content)[2] = (sin(a) * pt[1]) + (cos(a) * pt[2]);
		
		point_list = point_list->next;
	}
}

void	ft_orthographic_projection(t_list *point_list)
{
	int		pt[5];
	int		scale;

	scale = 1;
	while (point_list)
	{
		pt[0] = ((int *)point_list->content)[0];
		pt[1] = ((int *)point_list->content)[1];
		pt[2] = ((int *)point_list->content)[2];

		((int *)point_list->content)[0] = scale * (pt[0] - pt[1]);
		((int *)point_list->content)[1] = scale * (pt[2] - (pt[0] + pt[1]) / 2);
		
		point_list = point_list->next;
	}
}



// 6/5/24: changes made to rotations:
// angle x rotation: arctan(1/sqrt2)
// z rotation: + instead of - (int *)(point_list->content))[1] = sin(a) * pt[0] + cos(a) * pt[1];
//