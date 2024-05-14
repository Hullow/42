/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/05/14 21:38:25 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_calculate_sizes(t_stacks *full_stack)
{
	full_stack->size_a = 0;
	full_stack->size_b = 0;
	while (full_stack->a_head && ++full_stack->size_a)
		full_stack->a_head = full_stack->a_head->next;
	while (full_stack->b_head && ++full_stack->size_b)
		full_stack->b_head = full_stack->b_head->next;
	ft_printf("size_a: %d, size_b: %d\n", full_stack->size_a, full_stack->size_b);
}

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_position(t_stack_list *a_stack)
{
	int	position;

	position = 0;
	while (a_stack)
	{
		a_stack->position = position++;
		a_stack = a_stack->next;
	}
}

int	ft_calculate_cost(t_stack_list *a_element, int optimal_position, t_stacks *full_stack)
{
	int	RA_to_top;
	int	RRA_to_top;

	int	RB_to_optimal;
	int	RRB_to_optimal;
	// int minimum_moves;

	RA_to_top = a_element->position;
	RRA_to_top = full_stack->size_a - RA_to_top;

	RB_to_optimal = optimal_position;
	RRB_to_optimal = full_stack->size_b - optimal_position;

	// minimum_moves = 
	return (RA_to_top);
}

// finds where an element from stack a must be placed in stack b
// return the position it must be in (i-th element of b)
int	ft_optimal_position(int a_value, t_stack_list *b_stack, int *min_max)
{
	t_stack_list *anchor;
	int	i;
	int	smallest_difference;
	int	difference;

	anchor = b_stack;
	i = 0;
	difference = 0;
	smallest_difference = min_max[1] - min_max[0];
	if (!b_stack)
	{
		ft_printf("the optimal position for \"%d\" in stack b is %d)\n", a_value, i);
		return (i);
	}
	while (b_stack)
	{
		difference = a_value - b_stack->value; // if a is bigger than the value pointed to in b, a can take its place in the stack
		if (difference > 0 && difference < smallest_difference)
			smallest_difference = difference;
		b_stack = b_stack->next;
	}
	b_stack = anchor;
	while (b_stack && smallest_difference != a_value - b_stack->value && i++)
		b_stack = b_stack->next;
	ft_printf("the optimal position for \"%d\" in stack b is %d), before \"%d\"\n", a_value, i, b_stack->value);
	return (i);
}
