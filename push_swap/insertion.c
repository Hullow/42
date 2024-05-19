/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 18:43:24 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// inputs: the a_element from stack a, to insert at optimal_position in stack b
// steps:
// ft_count_required_moves: calculates the costs of various routes for inserting an element
// ft_minimise_moves: simplifies each route (by aggregating rotations or reverse rotations on both stacks where possible)
// ft_count_total_set_moves: counts the total moves for each insertion route
// output:
t_elem_insert	*ft_optimal_insertion(t_stack_list *a_element, t_stacks *full_stack)
{
	t_elem_insert_set	*elem_insert_set;
	int					optimal_position;

	elem_insert_set = malloc (sizeof(t_elem_insert_set));
	optimal_position = ft_optimal_position(full_stack->a_head->value, full_stack->b_head, ft_calculate_min_max(full_stack->b_head));
	(void)optimal_position;
	(void)a_element;
	// ft_count_required_moves(a_element, full_stack, optimal_position, elem_insert_set);

	// ft_minimise_moves(elem_insert_set);
	// ft_aggregate_moves_RA_RB(&(elem_insert_set->insert_RA_RB));
	// ft_count_total_set_moves(elem_insert_set);
	// t_elem_insert	*best_insert;
	// best_insert = ft_select_best_insert(elem_insert_set);
	// printf("the best insert has actions: %d, with (%d, %d) moves\n", best_insert->actions, best_insert->moves_1, best_insert->moves_2);
	return (ft_select_best_insert(elem_insert_set));

}

// first count of moves required for each rotation combination,
// without optimization (aggregation, done by ft_aggregate_moves)
// RA_to_top = a_element->position;
// RRA_to_top = full_stack->size_a - RA_to_top;
// RB_to_optimal = optimal_position;
// RRB_to_optimal = full_stack->size_b - optimal_position;
void	ft_count_required_moves(t_stack_list *a_element, t_stacks *full_stack, int optimal_position, t_elem_insert_set *elem_insert_set)
{
	printf("\nft_count_required_moves:\n");
	printf("RA_RB actions:\n");
	elem_insert_set->insert_RA_RB.actions = RA_RB;
	elem_insert_set->insert_RA_RB.moves_1 = a_element->position; // if in position 0, 0 moves. if position 1, 1 move. etc.
	elem_insert_set->insert_RA_RB.moves_2 = optimal_position; // if optimal position is 0, 0 moves. if position 1, 1 move. etc.
	printf("insert_RA_RB.moves_1 == a_element->position == %d; insert_RA_RB.moves_2 == optimal_position == %d\n", elem_insert_set->insert_RA_RB.moves_1, elem_insert_set->insert_RA_RB.moves_2);
	
	elem_insert_set->insert_RRA_RRB.actions = RRA_RRB;
	elem_insert_set->insert_RRA_RRB.moves_1 = full_stack->size_a - a_element->position;
	elem_insert_set->insert_RRA_RRB.moves_2 = full_stack->size_b - optimal_position;

	elem_insert_set->insert_RA_RRB.actions = RA_RRB;
	elem_insert_set->insert_RA_RRB.moves_1 = a_element->position;
	elem_insert_set->insert_RA_RRB.moves_2 = full_stack->size_b - optimal_position;

	elem_insert_set->insert_RRA_RB.actions = RRA_RB;
	elem_insert_set->insert_RRA_RB.moves_1 = full_stack->size_a - a_element->position;
	elem_insert_set->insert_RRA_RB.moves_2 = optimal_position;
}

/*
// calculates the total moves required for a given insertion
// returns the set of element sorts
void	ft_count_total_set_moves(t_elem_insert_set *elem_insert_set)
{
	ft_count_total_moves(&(elem_insert_set->insert_RA_RB));
	ft_count_total_moves(&(elem_insert_set->insert_RRA_RRB));
	ft_count_total_moves(&(elem_insert_set->insert_RA_RRB));
	ft_count_total_moves(&(elem_insert_set->insert_RRA_RB));
}
 */

/* 
void	ft_count_total_moves(t_elem_insert **elem_insert)
{
	(*elem_insert)->total_moves = (*elem_insert)->moves_1 + (*elem_insert)->moves_2;
}
 */

/*
// simplifies each path of insertion, by looking at if both stacks
// can be rotated or reverse rotated together (RR, RRR)
// returns the set of element sorts
void	ft_minimise_moves(t_elem_insert_set *elem_insert_set)
{
	ft_aggregate_moves_RA_RB(&(elem_insert_set->insert_RA_RB));
	// ft_aggregate_moves_RRA_RRB(elem_insert_set->insert_RRA_RRB);

	// RRA && RB – simplifier: n/a
	// RRB && RA – simplifier: n/a
}
*/

/* 
// aggregates common rotations with RR
void	ft_aggregate_moves_RA_RB(t_elem_insert **elem_insert)
{
	int	temp_1;
	int	temp_2;

	temp_1 = (*elem_insert)->moves_1;
	temp_2 = (*elem_insert)->moves_2;
	// RA && RB
	// RR simplifier: if x* RA && y* RB, min(x, y)RR, max(x,y)-min(x,y) * RA or RB
	// if (elem_insert->action = RA_RB) {
	if ((*elem_insert)->moves_1 < (*elem_insert)->moves_2) // if #RA < #RB, we do all RR for all the RA, then RB for the rest
	{
		(*elem_insert)->actions = RR_RB;
		(*elem_insert)->moves_1 = temp_1; // #RR moves
		(*elem_insert)->moves_2 = temp_2 - temp_1; // #RB moves
	}
	else if ((*elem_insert)->moves_1 > (*elem_insert)->moves_2)
	{
		(*elem_insert)->actions = RR_RA;
		(*elem_insert)->moves_1 = temp_2; // #RR moves
		(*elem_insert)->moves_2 = temp_1 - temp_2; // #RA moves
	}
	else if ((*elem_insert)->moves_1 == (*elem_insert)->moves_2)
	{
		(*elem_insert)->actions = RR;
		(*elem_insert)->moves_1 = temp_2; // #RR moves
		(*elem_insert)->moves_2 = 0; // (n/a) moves
	}
	ft_count_total_moves(elem_insert);
}
 */

/*
// aggregates common reverse rotations with RRR 
t_elem_insert	*ft_aggregate_moves_RRA_RRB(t_elem_insert *elem_insert)
{
	t_elem_insert	*aggregated_element_sort;
	// RRA && RRB
	// RRR simplifier: if x* RRA && y* RRB, min(x, y)RRR, max(x,y)-min(x,y) * RRA or RRB
	aggregated_element_sort = malloc(sizeof(t_elem_insert));
	if (elem_insert->action = RRA_RRB)
	{	
		if (elem_insert->moves_1 < elem_insert->moves_2) // if #RRA < #RRB, we do all RR for all the RRA, then RRB for the rest
		{
			aggregated_element_sort->actions == RRR_RRB;
			aggregated_element_sort->moves_1 == elem_insert->moves_1; // #RR moves
			aggregated_element_sort->moves_2 == elem_insert->moves_2 - elem_insert->moves_1; // #RRB moves
		}
		else if (elem_insert->moves_1 > elem_insert->moves_2)
		{
			aggregated_element_sort->actions == RRR_RRA;
			aggregated_element_sort->moves_1 == elem_insert->moves_2; // #RR moves
			aggregated_element_sort->moves_2 == elem_insert->moves_1 - elem_insert->moves_2; // #RRA moves
		}
		else if (elem_insert->moves_1 == elem_insert->moves_2)
		{
			aggregated_element_sort->actions == RRR;
			aggregated_element_sort->moves_1 == elem_insert->moves_2; // #RR moves
			aggregated_element_sort->moves_2 == 0; // (n/a) moves
		}
		ft_count_total_moves(aggregated_element_sort);
	}
	return (aggregated_element_sort);	
}
 */

// selects the optimal insertion for a given element,
// from the various insertions outlined by ft_outline_insertions
t_elem_insert	*ft_select_best_insert(t_elem_insert_set *elem_insert_set)
{
	int	RA_RB_total;
	int	RRA_RRB_total;
	int	RA_RRB_total;
	int	RRA_RB_total;
	int	minimal_moves;

	RA_RB_total = elem_insert_set->insert_RA_RB.total_moves;
	RRA_RRB_total = elem_insert_set->insert_RRA_RRB.total_moves;
	RA_RRB_total = elem_insert_set->insert_RA_RRB.total_moves;
	RRA_RB_total = elem_insert_set->insert_RRA_RB.total_moves;

	minimal_moves = ft_min(ft_min(RA_RB_total, RRA_RRB_total), ft_min(RA_RRB_total, RRA_RB_total));

	if (minimal_moves == RA_RB_total)
		return (&(elem_insert_set->insert_RA_RB));
	else if (minimal_moves == RRA_RRB_total)
		return (&(elem_insert_set->insert_RRA_RRB));
	else if (minimal_moves == RA_RRB_total)
		return (&(elem_insert_set->insert_RA_RRB));
	else if (minimal_moves == RRA_RB_total)
		return (&(elem_insert_set->insert_RRA_RB));
	else
		return (NULL);
}
