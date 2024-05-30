/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/30 17:17:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_insertion(t_stacks *full_stack, t_elem_insert *elem_insert)
{
	int	action = elem_insert->actions_aggregated;
	int	moves_1 = elem_insert->moves_1_aggregated;
	int	moves_2 = elem_insert->moves_2_aggregated;
	if (action == RR)
		ft_do_multiple_actions(RR, full_stack, moves_1);
	if (action == RA_RB)
	{
		ft_do_multiple_actions(RA, full_stack, moves_1);
		ft_do_multiple_actions(RB, full_stack, moves_2);
	}
	else if (action == RRA_RRB)
	{
		ft_do_multiple_actions(RRA, full_stack, moves_1);
		ft_do_multiple_actions(RRB, full_stack, moves_2);
	}
	else if (action == RRA_RB)
	{
		ft_do_multiple_actions(RRA, full_stack, moves_1);
		ft_do_multiple_actions(RB, full_stack, moves_2);
	}
	else if (action == RA_RRB)
	{
		ft_do_multiple_actions(RA, full_stack, moves_1);
		ft_do_multiple_actions(RRB, full_stack, moves_2);
	}
	/// RRR
	ft_do_action(PB, full_stack);
}

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
	if (action == PA)
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
