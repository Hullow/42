/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/31 19:00:12 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_multiple_actions(int action, t_stacks *full_stack, int moves)
{
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr"};

	if (!full_stack->size_a || !full_stack->size_b)
		ft_calculate_sizes(full_stack);
	while (moves--)
	{
		ft_do_action(action, full_stack);
		ft_printf("%s\n", table[action - 1]);
	}
	ft_calculate_sizes(full_stack);
}

// using a define set in push_swap.h, calls the various actions:
// PA (push to stack A), PB (push to stack B),
// RA (rotate stack A), RB (rotate stack B),
// RRA (reverse rotate stack A), RB (reverse rotate stack B)
void	ft_do_action(int action, t_stacks *full_stack)
{
	if ((!full_stack->a_head && (action == RA || action == RRA || action == RR || action == PB))\
|| (!full_stack->b_head && (action == RB || action == RRB || action == RR || action == PA))) // checks if action can be done
		return;
	if (action == SA)
		ft_swap(&(full_stack->a_head), &(full_stack->a_tail), full_stack->size_a);
	else if (action == SB)
		ft_swap(&(full_stack->b_head), &(full_stack->b_tail), full_stack->size_b);
	else if (action == PA)
		ft_push_a(full_stack);
	else if (action == PB)
		ft_push_b(full_stack);
	else if (action == RA)
		ft_rotate(&(full_stack->a_head), &(full_stack->a_tail));
	else if (action == RB)
		ft_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	else if (action == RR)
	{
		ft_rotate(&(full_stack->a_head), &(full_stack->a_tail));
		ft_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	}
	else if (action == RRA)
		ft_reverse_rotate(&(full_stack->a_head), &(full_stack->a_tail));
	else if (action == RRB)
		ft_reverse_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	else if (action == RRR)
	{
		ft_reverse_rotate(&(full_stack->a_head), &(full_stack->a_tail));
		ft_reverse_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	}
}
