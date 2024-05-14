/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/05/14 20:39:31 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // to remove or comment out

void	ft_print_list(t_stack_list *list)
{
	int		i;

	i = 0;
	// ft_printf("ft_print_list: list address %p\n", list);
	while (list)
	{
		ft_printf("%d) %d\n", ++i, list->value);
		list = list->next;
	}
}