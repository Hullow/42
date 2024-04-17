/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_transformation_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/04/17 10:28:50 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_env	*ft_graph_transformation()
{
	if (env->point_list)
{
	while (env->point_list)
	{
		temp[0] = ((int *) env->point_list->content)[0];
		temp[1] = ((int *) env->point_list->content)[1];
		temp[2] = ((int *) env->point_list->content)[2];
		((int *) env->point_list->content)[0] = ft_isometric_transform('x', temp[0], temp[1], temp[2]);
		((int *) env->point_list->content)[1] = ft_isometric_transform('y', temp[0], temp[1], temp[2]);
}

int	ft_isometric_transform(char c, int x, int y, int z)
{
	int	projected_coordinate;

	if (c == 'x')
		projected_coordinate = (1/sqrt(6)) * (sqrt(3) * x - sqrt(3) * z);
	else if (c == 'y')
		projected_coordinate = (1/sqrt(6)) * (x + 2 * y + z);
	else
		return(-1);
	return(projected_coordinate);
}

void	ft_zoom(t_env *env, t_list *anchor, int x_max, int y_max, int x_min, int y_min, float zoom)
{
	x_max = 0;
	y_max = 0;
	x_min = 0;
	y_min = 0;

	ft_printf("zoom: %d\n", (int)zoom);
	anchor = env->point_list;
	ft_printf("before: address of env->point_list: %p\nnow, the isometric transformed points:\n", env->point_list);
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp[0] = ((int *) env->point_list->content)[0];
			temp[1] = ((int *) env->point_list->content)[1];
			temp[2] = ((int *) env->point_list->content)[2];
			((int *) env->point_list->content)[0] = ft_isometric_transform('x', temp[0], temp[1], temp[2]);
			((int *) env->point_list->content)[1] = ft_isometric_transform('y', temp[0], temp[1], temp[2]);
			// ft_printf("x : %d, y: %d\n", ((int *) env->point_list->content)[0], ((int *) env->point_list->content)[1]);
			// finding x_max, x_min, y_max, y_min
			if ((int)((int *) env->point_list->content)[0] > (int)x_max)
			{
				x_max = ((int *) env->point_list->content)[0];
				// ft_printf("x_max reset to %d\n", (int)x_max);
			}
			if ((int)((int *) env->point_list->content)[0] < (int)x_min)
			{
				x_min = ((int *) env->point_list->content)[0];
				// ft_printf("x_min reset to %d\n", (int)x_min);
			}
			if ((int)((int *) env->point_list->content)[1] > (int)y_max)
			{
				y_max = ((int *) env->point_list->content)[1];
				// ft_printf("y_max reset to %d\n", (int)y_max);
			}
			if ((int)((int *) env->point_list->content)[1] < (int)y_min)
			{
				y_min = ((int *) env->point_list->content)[1];
				// ft_printf("y_min reset to %d\n", (int)x_min);
			}
			env->point_list = env->point_list->next;
		}
	}

	ft_printf("x_min: %d ", x_min);
	ft_printf("x_max: %d ", x_max);
	ft_printf("y_max: %d ", y_max);
	ft_printf("y_min: %d\n", y_max);
	// defining zoom from maximum and minimum values
	ft_printf("zoom: %d\n", (int)(zoom));
	while  ((((x_max - x_min) * zoom) < (int)WINDOW_WIDTH) && (((y_max - y_min) * zoom) < (int)WINDOW_HEIGHT))
		zoom += 0.1;
	printf("zoom: %f\n", zoom);
	while  ((((x_max - x_min) * zoom) > (int)WINDOW_WIDTH) || (((y_max - y_min) * zoom) > (int)WINDOW_HEIGHT))
		zoom -= 0.1;
	while  (((x_max * zoom) > (int)WINDOW_WIDTH) || (((y_max) * zoom) > (int)WINDOW_HEIGHT))
		zoom -= 0.1;
	zoom -= 10.25;
	printf("zoom: %f\n", zoom);
	ft_printf("zoom: %d\n", (int)(zoom));
}