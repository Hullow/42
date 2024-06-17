/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:54 by fallan            #+#    #+#             */
/*   Updated: 2024/06/17 17:37:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// run an action on our stacks multiple times (#moves)
// checker: if != 0, stops printing out the action
// (set to 1 when called from the checker, 0 otherwise)
void	ft_do_multiple_actions(int action, t_stacks *stacks, \
int moves, int checker)
{
	char	*table[10];

	table[0] = "sa";
	table[1] = "sb";
	table[2] = "pa";
	table[3] = "pb";
	table[4] = "ra";
	table[5] = "rb";
	table[6] = "rra";
	table[7] = "rrb";
	table[8] = "rr";
	table[9] = "rrr";
	ft_calculate_sizes(stacks);
	while (moves--)
	{
		ft_do_action(action, stacks);
		if (!checker)
			ft_printf("%s\n", table[action - 1]);
	}
	ft_calculate_sizes(stacks);
	ft_set_positions(stacks);
}

// does a move (swap, push, rotate, reverse rotate) on the stack
// first checks if the action can be done
// using a define set in push_swap.h, calls the various actions:
// PA (push to stack A), PB (push to stack B),
// RA (rotate stack A), RB (rotate stack B),
// RRA (reverse rotate stack A), RB (reverse rotate stack B)
void	ft_do_action(int action, t_stacks *stacks)
{
	if ((!stacks->a_head && (action == RA || action == RRA || action == PB)) \
	|| (!stacks->b_head && (action == RB || action == RRB || action == PA)))
		return ;
	if (action == SA)
		ft_swap(&(stacks->a_head), &(stacks->a_tail), stacks->size_a);
	else if (action == SB)
		ft_swap(&(stacks->b_head), &(stacks->b_tail), stacks->size_b);
	else if (action == PA)
		ft_push_a(stacks);
	else if (action == PB)
		ft_push_b(stacks);
	else if (action == RA)
		ft_rotate(&(stacks->a_head), &(stacks->a_tail));
	else if (action == RB)
		ft_rotate(&(stacks->b_head), &(stacks->b_tail));
	else if (action == RR || action == RRR)
		ft_rotate_both_stacks(action, stacks);
	else if (action == RRA)
		ft_reverse_rotate(&(stacks->a_head), &(stacks->a_tail));
	else if (action == RRB)
		ft_reverse_rotate(&(stacks->b_head), &(stacks->b_tail));
}

// finds where an element from a stack a must be placed in stack b
// returns the position it must be in (i-th element of b)
	// inputs: the value of the element in a, the stack b, the min_max for b
	// first while(): "difference" if a is bigger 
	// than the value pointed to in b, a can take its place in the stack
	// second while(): 
		// set i to point to the element of b with the smallest difference
int	ft_optimal_position(int value, t_stack *stack, int smallest_difference)
{
	t_stack	*anchor;
	int		optimal_position;
	int		difference;

	if (!stack)
		return (0);
	optimal_position = 0;
	anchor = stack;
	while (stack)
	{
		difference = value - stack->value;
		if (ft_abs(difference) < smallest_difference)
			smallest_difference = ft_abs(difference);
		stack = stack->next;
	}
	stack = anchor;
	while (stack && smallest_difference != ft_abs(value - stack->value))
	{
		optimal_position++;
		stack = stack->next;
	}
	if (value < stack->value)
		optimal_position++;
	return (optimal_position);
}

// sets minimum cost values to cost values
// called from a loop to find minimal costs
void	ft_set_min_cost(t_cost *cost, t_cost *min_cost_insert)
{
	min_cost_insert->x_ra = cost->x_ra;
	min_cost_insert->x_rb = cost->x_rb;
	min_cost_insert->x_rr = cost->x_rr;
	min_cost_insert->x_rra = cost->x_rra;
	min_cost_insert->x_rrb = cost->x_rrb;
	min_cost_insert->x_rrr = cost->x_rrr;
	min_cost_insert->total = cost->total;
}

// performs the optimal insertion the selected element of a into b
void	ft_do_cheapest_insertion(t_stacks *stacks, t_cost *min_cost_insert)
{
	ft_do_multiple_actions(RA, stacks, min_cost_insert->x_ra, 0);
	ft_do_multiple_actions(RB, stacks, min_cost_insert->x_rb, 0);
	ft_do_multiple_actions(RR, stacks, min_cost_insert->x_rr, 0);
	ft_do_multiple_actions(RRA, stacks, min_cost_insert->x_rra, 0);
	ft_do_multiple_actions(RRB, stacks, min_cost_insert->x_rrb, 0);
	ft_do_multiple_actions(RRR, stacks, min_cost_insert->x_rrr, 0);
	ft_do_multiple_actions(PB, stacks, 1, 0);
}
