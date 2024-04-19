/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:22:54 by fallan            #+#    #+#             */
/*   Updated: 2024/04/19 12:08:33 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	int	fd;
	int	*line_data = NULL;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s opened\n", argv[1]);
			line_data = ft_examine_lines(fd);
			close(fd);
			fd = open(argv[1], O_RDONLY);
			t_list *point_list;
			t_list *temp;
			point_list = ft_file_to_point_list(fd, -1, line_data);
			temp = point_list;
			launch_window_and_draw(temp);
		}
	}
	else
	{
		line_data[0] = 0;
		line_data[1] = 0;
		ft_printf("missing arguments\n");
	}
 	return (0);
}