/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/06/18 11:50:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // to remove or comment out
void	ft_print_both_stacks(t_stacks *stacks)
{
	ft_printf("\nstacks:\na:  ");
	ft_print_stack(stacks->a_head);
	ft_printf("\nb:  ");
	ft_print_stack(stacks->b_head);
	ft_printf("\n");
}

void	ft_print_stack(t_stack *list)
{
	if (!list)
		ft_printf("***empty***\n");
	if (list)
	{
		while (list)
		{
			if (list != NULL)
				ft_printf("%d  ", list->value);
			list = list->next;
		}
	}
}
