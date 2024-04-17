/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_transformation_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/04/17 12:02:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_env	*ft_graph_transformation(t_list	*point_list)
{
	t_list	*anchor;

	ft_printf("address before ft_lstiter: %p\n", point_list);
	anchor = point_list;
	if (env->point_list)
	{
		ft_lstiter((int *)(point_list->content), ft_isometric_transform);
		ft_printf("address after ft_lstiter: %p\n", point_list);
		point_list = anchor;
		ft_lstiter()
	}
}

int	ft_isometric_transform(int *content)
{
	temp[0] = content[0];
	temp[1] = content[1];
	temp[2] = content[2];

	content[0] = (1/sqrt(6)) * (sqrt(3) * temp[0] - sqrt(3) * temp[2]);
	content[1] = (1/sqrt(6)) * (temp[0] + 2 * temp[1] + temp[2]);

	return (content);
}


void	ft_zoom(t_list *point_list, int x_max, int y_max, int x_min, int y_min, float zoom)
{
	t_list	*anchor;

	x_max = 0;
	y_max = 0;
	x_min = 0;
	y_min = 0;
	anchor = env->point_list;
	ft_printf("zoom: %d\n", (int)zoom);

	if (env->point_list)
	{
		while (env->point_list)
		{
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


// int	*ft_center_in_window(int	*point)
// {
// }


// void	ft_treat_point_list(t_env *env)
// {
// 	if (env->point_list)
// 	{
// 		while (env->point_list->next)
// 		{
// 			((int *) env->point_list->content)[0] = y;
// 			ft_printf("((int *) env->point_list->content)[0] is %d\n", ((int *) env->point_list->content)[0]);
// 			env->point_list = env->point_list->next;
// 		}
// 	}
≈