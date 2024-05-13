/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 23:09:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	ft_print_list(t_stack_list *list)
{
	int		i;

	i = 0;
	ft_printf("ft_print_list: list address %p\n", list);
	while (list)
	{
		ft_printf("ft_print_list: list element %d: %d\n", ++i, list->value);
		// printf("ft_print_list (printf): list element %d: %d\n", i, ((int *)list->content)[0]);
		list = list->next;
	}
}