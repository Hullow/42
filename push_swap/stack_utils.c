/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/06/05 11:58:09 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_positions(t_stacks *full_stack)
{
	int				position;
	t_stack_list	*stack_iterator;

	position = 0;
	stack_iterator = full_stack->a_head;
	while (stack_iterator)
	{
		stack_iterator->position = position++;
		// printf("full_stack->a_head->value: %d, full_stack->a_head->position: %d\n", full_stack->a_head->value, full_stack->a_head->position);
		stack_iterator = stack_iterator->next;
	}
	position = 0;
	stack_iterator = full_stack->b_head;
	while (stack_iterator)
	{
		// printf("stack_iterator->value: %d, stack_iterator->position: %d\n", stack_iterator->value, stack_iterator->position);
		stack_iterator->position = position++;
		stack_iterator = stack_iterator->next;
	}
}

// calculates and sets the size of each stack
void	ft_calculate_sizes(t_stacks *full_stack)
{
	t_stack_list	*anchor;

	full_stack->size_a = 0;
	full_stack->size_b = 0;
	anchor = full_stack->a_head;
	if (full_stack->a_head)
	{
		while (full_stack->a_head)
		{
			full_stack->size_a++;
			full_stack->a_head = full_stack->a_head->next;
		}
	}
	full_stack->a_head = anchor;
	if (full_stack->b_head)
	{
		anchor = full_stack->b_head;
		while (full_stack->b_head)
		{
			full_stack->size_b++;
			full_stack->b_head = full_stack->b_head->next;
		} 
		full_stack->b_head = anchor;
	}
}

t_stack_list	*ft_stack_max_value(t_stack_list *stack_element)
{
	t_stack_list	*max;

	max = stack_element;
	while (stack_element)
	{
		if (stack_element->value > max->value)
			max = stack_element;
		stack_element = stack_element->next;
	}
	if (max->value == INT_MIN)
		ft_printf("ft_stack_max_value: error\n");
	// ft_printf("ft_stack_max_value: maximum found: %d\n", max->value);
	return (max);
}

// checks if the stack a is ordered
int	ft_check_stack(t_stacks	*full_stack)
{
	t_stack_list	*anchor;

	anchor = full_stack->a_head;
	while (full_stack->a_head->next)
	{
		if (full_stack->a_head->value >= full_stack->a_head->next->value)
		{
			full_stack->a_head = anchor;
			return (-1);
		}
		full_stack->a_head = full_stack->a_head->next;
	}
	if (full_stack->b_head || full_stack->size_b)
	{
		full_stack->a_head = anchor;
		return (1);
	}
	full_stack->a_head = anchor;
	// ft_printf("OK\n");
	return (0);
}

// hardcoded sorting of small stacks (size < 6)
void	ft_sort_small_stack(t_stacks *full_stack)
{
	if (full_stack->size_a == 3 && ft_check_stack(full_stack) != 0)
		ft_sort_three_elements(full_stack);
	else if (full_stack->size_a == 4 && ft_check_stack(full_stack) != 0)
		ft_sort_four_elements(full_stack);
}

void	ft_sort_four_elements(t_stacks *full_stack)
{
		// printf("sorting stack size == 4\n");
		t_stack_list *max = ft_stack_max_value(full_stack->a_head);
		if (max->position < 2)
		{
			ft_do_multiple_actions(RA, full_stack, max->position);
			ft_do_multiple_actions(PB, full_stack, 1);
		}
		else
		{
			ft_do_multiple_actions(RRA, full_stack, 4 - max->position);
			ft_do_multiple_actions(PB, full_stack, 1);
		}
		// ft_print_both_stacks(full_stack);
		ft_sort_three_elements(full_stack);
		// ft_print_both_stacks(full_stack);
		ft_do_multiple_actions(PA, full_stack, 1);
		ft_do_multiple_actions(RA, full_stack, 1);
}

// identifies the precise order of a three element stack
// outputs a number corresponding to the order:
// e.g. 132 : stack order is smallest, largest, in-between value
int	ft_three_stack_order(t_stack_list *a_head)
{
	// ft_print_stack(a_head);
	if (a_head->value < a_head->next->value && a_head->value < a_head->next->next->value) // if head is 1 (smallest)
    {
		if (a_head->next->value < a_head->next->next->value)
			return (123);
		else
			return (132);
    }
	else if (a_head->value > a_head->next->value && a_head->value > a_head->next->next->value) // if head is 3 (largest)
    {
    	if (a_head->next->value > a_head->next->next->value)
			return (321);
		else
			return (312);
    }
	else if (a_head->next->value > a_head->next->next->value) // if head is in-between value
		return (231);
	else
		return (213);
}

// hardcoded sort of stacks of three elements
// stack_order must be calculated
void	ft_sort_three_elements(t_stacks *full_stack)
{
	int	stack_order;
	stack_order = ft_three_stack_order(full_stack->a_head);
	if (stack_order == 132)
	{
		ft_do_multiple_actions(RRA, full_stack, 1);
		ft_do_multiple_actions(SA, full_stack, 1);
	}
	else if (stack_order == 213)
		ft_do_multiple_actions(SA, full_stack, 1);
	else if (stack_order == 231)
		ft_do_multiple_actions(RRA, full_stack, 1);
	else if (stack_order == 312)
		ft_do_multiple_actions(RA, full_stack, 1);
	else if (stack_order == 321)
	{
		ft_do_multiple_actions(RA, full_stack, 1);
		ft_do_multiple_actions(SA, full_stack, 1);
	}
}
