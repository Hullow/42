/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:13 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 11:19:07 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char ***split, int *line_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (split)
	{
		while (i < line_data[0])
		{
			while (split[i][j])
			{
					// printf("freeing: split[i][j[] address: %p\n", split[i][j]);
				free(split[i][j]);
				j++;
			}
			// printf("freeing: split[i] address: %p\n", split[i]);
			free(split[i]);
			i++;
			j = 0;
		}
		free(split);
	}
	// ft_printf("\nft_free_array: end of function\n");
}

void	ft_free_list(t_list *point_list)
{
	void	*node;
	void	*content;
	int 	element = 0;
	// int 	i = 0;

	node = NULL;
	content = NULL;
	ft_printf("\n***************\nft_free_list:\n***************\n");
	while (point_list)// && i < 1) ==> this leads to more leaks, so this function does something !
	{
		// i++;
		
		// printf("list element to be freed: (x:%f,y:%f,l:%f,c:%f)\n", \
		// ((double *)(point_list->content))[0], ((double *)(point_list->content))[1], \
		// ((double *)(point_list->content))[4], ((double *)(point_list->content))[5]); 
		node = point_list;
		content = point_list->content;
		point_list = point_list->next;
		ft_free(node);
		ft_free(content);
		printf("freed list element %d - ", ++element);
	}
	printf("\n");
}
