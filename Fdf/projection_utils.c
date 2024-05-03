/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/05/03 10:49:08 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center_points(t_list *point_list, int *min_max)
{
	int		centering_vector[2];

	centering_vector[0] = 0;
	centering_vector[1] = 0;
	while (centering_vector[0] + min_max[0] - ((min_max[0] - min_max[2]) / 2) < WINDOW_WIDTH / 2)
		centering_vector[0]++;
	while (centering_vector[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) < WINDOW_HEIGHT / 2)
		centering_vector[1]++;
	while (centering_vector[0] + min_max[0] - ((min_max[0] - min_max[2]) / 2) > WINDOW_WIDTH / 2)
		centering_vector[0]--; 
	while (centering_vector[1] + min_max[1] - ((min_max[1] - min_max[3]) / 2) > WINDOW_HEIGHT / 2)
		centering_vector[1]--;
	while (point_list)
	{
		((int *)point_list->content)[0] += centering_vector[0];
		((int *)point_list->content)[1] += centering_vector[1];
		point_list = point_list->next;
	}
	free(min_max);
}

int	*ft_min_max(t_list *point_list)
{
	t_list	*anchor;
	int		*min_max;

	min_max = (int *)malloc(sizeof(int) * 4);
	min_max[0] = 0;
	min_max[1] = 0;
	min_max[2] = 0;
	min_max[3] = 0;
	anchor = point_list;
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
	return(min_max);
}

void	ft_isometric_projection(t_list *point_list)
{
	int		point[5];
	int		size;
	double	angle;
	static int throttle = 0;

	angle = 30 * (M_PI / 180);
	if (!throttle)
		printf("angle: %f\n", angle);
	point[3] = ((int *)point_list->content)[3]; // #lines
	point[4] = ((int *)point_list->content)[4]; // #columns
	size = 1;
	while (size * point[4] < WINDOW_WIDTH && size * point[3] < WINDOW_HEIGHT)
		size++;
	printf("size is %d\n", size);
	while (point_list)
	{
		point[0] = ((int *)point_list->content)[0];
		point[1] = ((int *)point_list->content)[1];
		point[2] = ((int *)point_list->content)[2];
		// ((int *)point_list->content)[0] = (int)(point[0] * cos(angle + 2) + point[1] * cos(angle + 2) + point[2] * cos(angle - 2)) * (size / 2);
		// ((int *)point_list->content)[1] = (int)(point[0] * sin(angle) + point[1] * sin(angle + 2) + point[2] * sin(angle - 2)) * (size / 2);
		// ((int *)point_list->content)[0] = (1/sqrt(6)) * (sqrt(3) * point[0] - sqrt(3) * point[2]) * (size / 2);
		// ((int *)point_list->content)[1] = (1/sqrt(6)) * (point[0] + 2 * point[1] + point[2]) * (size / 2);
		// ((int *)point_list->content)[0] = (point[0] - point[1]) * cos(angle);
		// ((int *)point_list->content)[1] = (int) point[1] + ((point[0] + point[2]) * sin(angle)) / sqrt(2);
		((int *)point_list->content)[0] = (size / 2) * (point[0] * cos(angle) + point[1] * cos(angle + (4 * angle)) + point[2] * cos(angle - (4 * angle)));
		((int *)point_list->content)[1] = (size / 2) * (point[0] * sin(angle) + point[1]  * sin(angle + (4 * angle)) + point[2] * sin(angle - (4 * angle)));
	
		point_list = point_list->next;
	}

}