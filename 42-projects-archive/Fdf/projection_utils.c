/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/06 10:48:36 by francis          ###   ########.fr       */
=======
/*   Updated: 2024/05/07 12:36:36 by fallan           ###   ########.fr       */
>>>>>>> fixing_projection
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// z_rotation (try with 45 degrees)
void	ft_z_rotation(t_list *point_list)
{
	double	pt[3];
	float	a;

	a = -45 * (M_PI / 180);
	while (point_list)
	{
<<<<<<< HEAD
		pt[0] = ((int *)(point_list->content))[0];
		pt[1] = ((int *)(point_list->content))[1];
		pt[2] = ((int *)(point_list->content))[2];
		// printf("(%d,%d,%d)->", pt[0], pt[1], pt[2]);

		((int *)(point_list->content))[0] = cos(a) * pt[0] - sin(a) * pt[1];
		((int *)(point_list->content))[1] = sin(a) * pt[0] + cos(a) * pt[1];
		((int *)(point_list->content))[2] = pt[2];

		// printf("(%d,%d,%d)\n", ((int *)(point_list->content))[0], ((int *)(point_list->content))[1], ((int *)(point_list->content))[2]);
=======
		pt[0] = ((double *)(point_list->content))[0];
		pt[1] = ((double *)(point_list->content))[1];
		pt[2] = ((double *)(point_list->content))[2];
		((double *)(point_list->content))[0] = \
			(cos(a) * pt[0] - sin(a) * pt[1]);
		((double *)(point_list->content))[1] = \
			(sin(a) * pt[0] + cos(a) * pt[1]);
		((double *)(point_list->content))[2] = pt[2];
>>>>>>> fixing_projection
		point_list = point_list->next;
	}
}

// x_rotation (try with arctan(sqrt2))
void	ft_x_rotation(t_list *point_list)
{
	double	a;
	double	rotation[3];
	double	pt[5];

<<<<<<< HEAD
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
=======
	a = atan(1 / sqrt(2)) * 1.7;
	while (point_list)
	{
		pt[0] = ((double *)point_list->content)[0];
		pt[1] = ((double *)point_list->content)[1];
		pt[2] = ((double *)point_list->content)[2];
		rotation[0] = pt[0];
		rotation[1] = cos(a) * pt[1] - sin(a) * pt[2];
		rotation[2] = sin(a) * pt[1] + cos(a) * pt[2];
		((double *)point_list->content)[0] = rotation[0];
		((double *)point_list->content)[1] = rotation[1];
		((double *)point_list->content)[2] = rotation[2];
		point_list = point_list->next;
	}
}
>>>>>>> fixing_projection
