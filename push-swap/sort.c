/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 03:09:40 by fallan           ###   ########.fr       */
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

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

// selects the optimal insertion for a given element,
// from the various insertions outlined by ft_outline_insertions
//	ft_optimal_insertion()

// simplifies each path of insertion, by looking at if both stacks
// can be rotated or reverse rotated together (RR, RRR)
// if they can, ?
//t_element_sort_set	*ft_reduce_insertions(t_element_sort_set *elem_sort_set)

// calculates the costs of various routes for inserting an element
// of stack a at its appropriate place in stack b
t_element_sort_set	*ft_outline_insertions(t_stack_list *a_element, int optimal_position, t_stacks *full_stack)
{
	t_element_sort_set	*elem_sort_set;

	elem_sort_set = malloc (sizeof(t_element_sort_set));

	// RA_to_top = a_element->position;
	// RRA_to_top = full_stack->size_a - RA_to_top;

	// RB_to_optimal = optimal_position;
	// RRB_to_optimal = full_stack->size_b - optimal_position;

	elem_sort_set->sort_RA_RB.actions = RA_RB;
	elem_sort_set->sort_RA_RB.moves_a = a_element->position;
	elem_sort_set->sort_RA_RB.moves_b = optimal_position;

	elem_sort_set->sort_RRA_RRB.actions = RRA_RRB;
	elem_sort_set->sort_RRA_RRB.moves_a = full_stack->size_a - a_element->position;
	elem_sort_set->sort_RRA_RRB.moves_b = full_stack->size_b - optimal_position;

	elem_sort_set->sort_RA_RRB.actions = RA_RRB;
	elem_sort_set->sort_RA_RRB.moves_a = a_element->position;
	elem_sort_set->sort_RA_RRB.moves_b = full_stack->size_b - optimal_position;

	elem_sort_set->sort_RRA_RB.actions = RRA_RB;
	elem_sort_set->sort_RRA_RB.moves_a = full_stack->size_a - a_element->position;
	elem_sort_set->sort_RRA_RB.moves_b = optimal_position;

	ft_best

	RA && RB
	RR simplifier: if x* RA && y* RB, min(x, y)RR, max(x,y)-min(x-y) * RA or RB

	RRA && RRB
	RR simplifier: if x* RRA && y* RRB, min(x, y)RRR, max(x,y)-min(x-y) * RRA or RRB

	RRA && RB
	RR simplifier: n/a ?

	RRB && RA
	RR simplifier: n/a ?

	t_element_solution.total_moves = ft_min(ft_min(RA && RB, RRA && RRB), ft_min(RRA && RB, RRB && RA)); // the minimum number of moves


	return (solution);
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
