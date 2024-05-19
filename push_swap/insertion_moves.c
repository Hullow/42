/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 11:36:24 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_insertion(int action, t_stacks *full_stack, t_elem_insert elem_insert)
{
	if (action == RA_RB)
	{
		ft_do_multiple_actions(RA, full_stack, elem_insert.moves_1);
		ft_do_multiple_actions(RB, full_stack, elem_insert.moves_2);
	}
	else if (action == RRA_RRB)
	{
		ft_do_multiple_actions(RRA, full_stack, elem_insert.moves_1);
		ft_do_multiple_actions(RRB, full_stack, elem_insert.moves_2);
	}
	else if (action == RRA_RB)
	{
		ft_do_multiple_actions(RRA, full_stack, elem_insert.moves_1);
		ft_do_multiple_actions(RB, full_stack, elem_insert.moves_2);
	}
	else if (action == RA_RRB)
	{
		ft_do_multiple_actions(RA, full_stack, elem_insert.moves_1);
		ft_do_multiple_actions(RRB, full_stack, elem_insert.moves_2);
	}
}

void	ft_do_multiple_actions(int action, t_stacks *full_stack, int moves)
{
	while (moves--)
		ft_do_action(action, full_stack);
}

// using a define set in push_swap.h, calls the various actions:
// PA (push to stack A), PB (push to stack B),
// RA (rotate stack A), RB (rotate stack B),
// RRA (reverse rotate stack A), RB (reverse rotate stack B)
void	ft_do_action(int action, t_stacks *full_stack)
{
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
		ft_reverse_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	}
	else if (action == RRA)
		ft_reverse_rotate(&(full_stack->a_head), &(full_stack->a_tail));
	else if (action == RRB)
		ft_reverse_rotate(&(full_stack->b_head), &(full_stack->b_tail));
}
