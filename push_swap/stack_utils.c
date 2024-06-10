/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:12:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the stack a is ordered
// returns -1 if stack a unordered
// returns 1 if a stack b is found
// returns 0 otherwise
int	ft_check_stack(t_stacks	*stacks)
{
	t_stack	*anchor;

	anchor = stacks->a_head;
	while (stacks->a_head->next)
	{
		if (stacks->a_head->value >= stacks->a_head->next->value)
		{
			stacks->a_head = anchor;
			return (-1);
		}
		stacks->a_head = stacks->a_head->next;
	}
	if (stacks->b_head || stacks->size_b)
	{
		stacks->a_head = anchor;
		return (1);
	}
	stacks->a_head = anchor;
	return (0);
}

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_positions(t_stacks *stacks)
{
	int		position;
	t_stack	*stack_iterator;

	position = 0;
	if (stacks->a_head)
	{
		stack_iterator = stacks->a_head;
		while (stack_iterator)
		{
			stack_iterator->position = position++;
			stack_iterator = stack_iterator->next;
		}
	}
	position = 0;
	if (stacks->b_head)
	{
		stack_iterator = stacks->b_head;
		while (stack_iterator)
		{
			stack_iterator->position = position++;
			stack_iterator = stack_iterator->next;
		}
	}
}

// calculates and sets the size of each stack
void	ft_calculate_sizes(t_stacks *stacks)
{
	t_stack	*anchor;

	stacks->size_a = 0;
	stacks->size_b = 0;
	anchor = stacks->a_head;
	if (stacks->a_head)
	{
		while (stacks->a_head)
		{
			stacks->size_a++;
			stacks->a_head = stacks->a_head->next;
		}
	}
	stacks->a_head = anchor;
	if (stacks->b_head)
	{
		anchor = stacks->b_head;
		while (stacks->b_head)
		{
			stacks->size_b++;
			stacks->b_head = stacks->b_head->next;
		}
		stacks->b_head = anchor;
	}
}

// returns the node that has the highest value of a stack
t_stack	*ft_stack_max_value(t_stack *stack_element)
{
	t_stack	*max;

	max = stack_element;
	while (stack_element)
	{
		if (stack_element->value > max->value)
			max = stack_element;
		stack_element = stack_element->next;
	}
	return (max);
}

// returns the node that has the smallest value of a stack
t_stack	*ft_stack_min_value(t_stack *stack_element)
{
	t_stack	*min;

	min = stack_element;
	while (stack_element)
	{
		if (stack_element->value < min->value)
			min = stack_element;
		stack_element = stack_element->next;
	}
	return (min);
}
