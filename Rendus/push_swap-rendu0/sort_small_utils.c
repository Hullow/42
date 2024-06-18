/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:11:54 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:12:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// identifies the precise order of a three element stack
// outputs a number corresponding to the order:
// e.g. 132 : stack order is smallest, largest, in-between value
// clauses by order:
//  // if: head is 1 (smallest)
//	// else if: head is 3 (largest)
//	// else if: head is in-between value
int	ft_three_stack_order(t_stack *a_head)
{
	if (a_head->value < a_head->next->value && \
	a_head->value < a_head->next->next->value)
	{
		if (a_head->next->value < a_head->next->next->value)
			return (123);
		else
			return (132);
	}
	else if (a_head->value > a_head->next->value && \
	a_head->value > a_head->next->next->value)
	{
		if (a_head->next->value > a_head->next->next->value)
			return (321);
		else
			return (312);
	}
	else if (a_head->next->value > a_head->next->next->value)
		return (231);
	else
		return (213);
}

// hardcoded sort of stacks a of three elements
// stack_order must be calculated
void	ft_sort_three_elements(t_stacks *stacks)
{
	int	stack_order;

	stack_order = ft_three_stack_order(stacks->a_head);
	if (stack_order == 132)
	{
		ft_do_multiple_actions(RRA, stacks, 1, 0);
		ft_do_multiple_actions(SA, stacks, 1, 0);
	}
	else if (stack_order == 213)
		ft_do_multiple_actions(SA, stacks, 1, 0);
	else if (stack_order == 231)
		ft_do_multiple_actions(RRA, stacks, 1, 0);
	else if (stack_order == 312)
		ft_do_multiple_actions(RA, stacks, 1, 0);
	else if (stack_order == 321)
	{
		ft_do_multiple_actions(RA, stacks, 1, 0);
		ft_do_multiple_actions(SA, stacks, 1, 0);
	}
}

// hardcoded sort of four element stacks
void	ft_sort_four_elements(t_stacks *stacks)
{
	t_stack	*max;

	max = ft_stack_max_value(stacks->a_head);
	if (max->position < 2)
	{
		ft_do_multiple_actions(RA, stacks, max->position, 0);
		ft_do_multiple_actions(PB, stacks, 1, 0);
	}
	else
	{
		ft_do_multiple_actions(RRA, stacks, 4 - max->position, 0);
		ft_do_multiple_actions(PB, stacks, 1, 0);
	}
	ft_sort_three_elements(stacks);
	ft_do_multiple_actions(PA, stacks, 1, 0);
	ft_do_multiple_actions(RA, stacks, 1, 0);
}

// hardcoded sort of five element stacks
void	ft_sort_five_elements(t_stacks *stacks)
{
	t_stack	*max;

	max = ft_stack_max_value(stacks->a_head);
	if (max->position < 3)
	{
		ft_do_multiple_actions(RA, stacks, max->position, 0);
		ft_do_multiple_actions(PB, stacks, 1, 0);
	}
	else
	{
		ft_do_multiple_actions(RRA, stacks, 5 - max->position, 0);
		ft_do_multiple_actions(PB, stacks, 1, 0);
	}
	ft_sort_four_elements(stacks);
	ft_do_multiple_actions(PA, stacks, 1, 0);
	ft_do_multiple_actions(RA, stacks, 1, 0);
}
