/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:35:53 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 23:46:20 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* uses the minimal and maximal values of x and y
to calculate a centering vector which is used to
center the points */
double	*ft_calculate_center(double *min_max, double *translation_vector)
{
	translation_vector[0] = 0;
	translation_vector[1] = 0;
	while (translation_vector[0] + min_max[0] - \
	((min_max[0] - min_max[2]) / 2) < WINDOW_WIDTH / 2)
		translation_vector[0]++;
	while (translation_vector[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) \
	< WINDOW_HEIGHT / 2)
		translation_vector[1]++;
	while (translation_vector[0] + min_max[0] - ((min_max[0] - min_max[2]) / 2) \
	> WINDOW_WIDTH / 2)
		translation_vector[0]--;
	while (translation_vector[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) \
	> WINDOW_HEIGHT / 2)
		translation_vector[1]--;
	translation_vector[0] *= 0.4;
	translation_vector[1] *= 1.5;
	return (translation_vector);
}

void	ft_translation(t_list *point_list, double *translation_vector)
{
	while (point_list)
	{
		((double *)point_list->content)[0] += translation_vector[0];
		((double *)point_list->content)[1] += translation_vector[1];
		point_list = point_list->next;
	}
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
