/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:11:54 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 18:31:08 by fallan           ###   ########.fr       */
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
int	ft_three_stack_order(t_stack_list *a_head)
{
	if (a_head->value < a_head->next->value && a_head->value < a_head->next->next->value)
    {
		if (a_head->next->value < a_head->next->next->value)
			return (123);
		else
			return (132);
    }
	else if (a_head->value > a_head->next->value && a_head->value > a_head->next->next->value)
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
void	ft_sort_three_elements(t_stacks *full_stack)
{
	int	stack_order;
	stack_order = ft_three_stack_order(full_stack->a_head);
	if (stack_order == 132)
	{
		ft_do_multiple_actions(RRA, full_stack, 1, 0);
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	}
	else if (stack_order == 213)
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	else if (stack_order == 231)
		ft_do_multiple_actions(RRA, full_stack, 1, 0);
	else if (stack_order == 312)
		ft_do_multiple_actions(RA, full_stack, 1, 0);
	else if (stack_order == 321)
	{
		ft_do_multiple_actions(RA, full_stack, 1, 0);
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	}
}

// pushes the two smallest elements of a to be in an optimised way
// hardcoded for stacks of five elements
void	ft_push_two_smallest_elements(t_stacks *full_stack, t_stack_list *min, t_stack_list *sec_min)
{
	int	pushed;

	pushed = 0;
	if (full_stack->a_head == min || full_stack->a_head == sec_min)
	{
		ft_do_multiple_actions(PB, full_stack, 1, 0);
		pushed = 1;
	}
	else
	{
		if (min->position == 4 || sec_min->position == 4)
			ft_do_multiple_actions(RRA, full_stack, 1, 0);
		else if (full_stack->a_head->next == min || full_stack->a_head->next == sec_min)
			ft_do_multiple_actions(RA, full_stack, 1, 0);
		else if ((full_stack->size_a == 4) && (min->position == 3 || sec_min->position == 3))
			ft_do_multiple_actions(RRA, full_stack, 1, 0);
		else if ((full_stack->size_a == 5) && (min->position == 3 || sec_min->position == 3))
			ft_do_multiple_actions(RRA, full_stack, 2, 0);
		else if (min->position == 2 || sec_min->position == 2)
			ft_do_multiple_actions(RA, full_stack, 2, 0);
	}
	if (pushed == 0)
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	if (full_stack->size_b == 2 && (full_stack->b_head->value < full_stack->b_head->next->value))
		ft_do_multiple_actions(SB, full_stack, 1, 0);
}

// hardcoded sort of four element stacks
void	ft_sort_four_elements(t_stacks *full_stack)
{
	t_stack_list *max = ft_stack_max_value(full_stack->a_head);
	if (max->position < 2)
	{
		ft_do_multiple_actions(RA, full_stack, max->position, 0);
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	}
	else
	{
		ft_do_multiple_actions(RRA, full_stack, 4 - max->position, 0);
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	}
	ft_sort_three_elements(full_stack);
	ft_do_multiple_actions(PA, full_stack, 1, 0);
	ft_do_multiple_actions(RA, full_stack, 1, 0);
}

// hardcoded sort of five element stacks
void	ft_sort_five_elements(t_stacks *full_stack)
{
	t_stack_list *max = ft_stack_max_value(full_stack->a_head);
	if (max->position < 3)
	{
		ft_do_multiple_actions(RA, full_stack, max->position, 0);
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	}
	else
	{
		ft_do_multiple_actions(RRA, full_stack, 5 - max->position, 0);
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	}
	ft_sort_four_elements(full_stack);
	ft_do_multiple_actions(PA, full_stack, 1, 0);
	ft_do_multiple_actions(RA, full_stack, 1, 0);
}
