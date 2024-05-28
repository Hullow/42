/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/05/28 19:19:26 by fallan           ###   ########.fr       */
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
