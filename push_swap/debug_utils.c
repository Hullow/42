/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 18:34:07 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // to remove or comment out
void	ft_print_both_stacks(t_stacks *full_stack)
{
	ft_printf("\na:\n");
	ft_print_stack(full_stack->a_head);
	ft_printf("\nb:\n");
	ft_print_stack(full_stack->b_head);
	ft_printf("\n");
}

void	ft_print_stack(t_stack *list)
{
	int		i;

	i = -1;
	// ft_printf("ft_print_list: list address %p\n", list);
	if (!list)
		ft_printf("(empty)\n");
	if (list)
	{
		while (list)
		{
			if (list != NULL) // if (list->value)
				printf("%d) %d\n", ++i, list->value); // printf
			list = list->next;
		}
	}
}
