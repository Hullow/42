/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/05/27 16:16:21 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_do_optimal_insertion(t_stacks *full_stack)
{
	t_stack_list	*a_iterator = full_stack->a_head;
	t_stack_list	*best_element_to_insert;
	t_elem_insert	*insertion;
	t_elem_insert	*best_element_insertion;
	int				minimal_insertion_moves;

	ft_calculate_sizes(full_stack); // calculates the size of each stack
	ft_set_positions(full_stack); // sets the positions of each element in the stack
	insertion = ft_find_optimal_insertion(full_stack->a_head, full_stack);
	minimal_insertion_moves = insertion->total_moves_final;
	best_element_to_insert = full_stack->a_head;
	while (a_iterator->next)
	{
		a_iterator = a_iterator->next;
		insertion = ft_find_optimal_insertion(a_iterator, full_stack);
		// printf("\nthe optimised insert has actions:\n");
		// ft_print_moves(insertion);
		if (insertion->total_moves_final < minimal_insertion_moves)
		{
			best_element_to_insert = a_iterator;
			printf("new best element to insert found: %d – %d) in stack a\n", a_iterator->value, a_iterator->position);
		}
	}
	best_element_insertion = ft_find_optimal_insertion(best_element_to_insert, full_stack);
	printf("the best element to insert is \"%d\" – %d) in stack a, with moves:\n", best_element_to_insert->value, best_element_to_insert->position);
	ft_print_moves(best_element_insertion);
	ft_do_insertion(full_stack, best_element_insertion);
}

// inputs: the a_element from stack a, to insert at optimal_position in stack b
// steps:
// ft_count_required_moves: calculates the costs of various routes for inserting an element
// ft_minimise_moves: simplifies each route (by aggregating rotations or reverse rotations on both stacks where possible)
// ft_count_total_set_moves: counts the total moves for each insertion route
// output:
t_elem_insert	*ft_find_optimal_insertion(t_stack_list *a_element, t_stacks *full_stack)
{
	t_elem_insert_set	*elem_insert_set;
	int					optimal_position;

	elem_insert_set = malloc (sizeof(t_elem_insert_set));
	if (!a_element)
		return (NULL);
	if (full_stack->b_head)
		optimal_position = ft_optimal_position(a_element->value, full_stack->b_head);
	else
		optimal_position = 0;
	ft_count_required_moves(a_element, full_stack, elem_insert_set);

	ft_count_total_insertion_moves(elem_insert_set);
	ft_minimise_moves(elem_insert_set);
	return (ft_select_optimised_insert(elem_insert_set));
}

// first count of moves required for each rotation combination,
// without optimization (aggregation, done by ft_aggregate_moves)
	// RA_to_top = a_element->position; 			// if in position 0, 0 moves. if position 1, 1 move. etc.
	// RRA_to_top = full_stack->size_a - a_element->position;
	// RB_to_optimal = optimal_position; 			// if optimal position is 0, 0 moves. if position 1, 1 move. etc.
	// RRB_to_optimal = full_stack->size_b - optimal_position;
void ft_calculate_cost(t_stack_list *a_element, t_stacks *full_stack, t_cost *cost)
{
	int optimal_position = ft_optimal_position(a_element->value, full_stack->b_head);
	cost->xRB = optimal_position;
	cost->xRRB = full_stack->size_b - cost->xRB;
	cost->xRA = a_element->position;
	cost->xRRA = full_stack->size_a - cost->xRA;

	cost->xRR = ft_min(cost->xRA, cost->xRB);
	cost->xRRR = ft_min(cost->xRRA, cost->xRRB);

	cost->xRB_ = cost->xRB - cost->xRR;
	cost->xRRB_ = cost->xRRB - cost->xRRR;
	cost->xRA_ = cost->xRA - cost->xRR;
	cost->xRRA_ = cost->xRRA - cost->xRRR;

	int costt[4];
	costt[0] = cost->xRR + ft_max(cost->xRA,cost->xRB) - ft_min(cost->xRA, cost->xRB);
	costt[1] = cost->xRRR + ft_max(cost->xRRA,cost->xRRB) - ft_min(cost->xRRA, cost->xRRB);
	costt[2] = cost->xRA + cost->xRRB;
	costt[3] = cost->xRB + cost->xRRA;

	int i = -1;
	int min_cost = ft_min(ft_min(costt[0], costt[1]), ft_min(costt[2], costt[3]));
	while (++i < 4)
		if (min_cost == costt[i])
			break;
	if (i == 0)
	{
		cost->xRRR = 0;
		cost->xRRA = 0;
		cost->xRRB = 0;
		cost->xRA = cost->xRA_;
		cost->xRB = cost->xRB_;
	}
	if (i == 1)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRB = 0;
		cost->xRRA = cost->xRRA_;
		cost->xRRB = cost->xRRB_;
	}
	if (i == 2)
	{
		cost->xRR = 0;
		cost->xRB = 0;
		cost->xRRR = 0;
		cost->xRRA = 0;
	}
	if (i == 3)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRRR = 0;
		cost->xRRB = 0;
	}

}
void	ft_count_required_moves(t_stack_list *a_element, t_stacks *full_stack, t_elem_insert_set *elem_insert_set)
{
	int optimal_position = ft_optimal_position(a_element->value, full_stack->b_head);
	elem_insert_set->insert_RA_RB.actions = RA_RB;
	elem_insert_set->insert_RA_RB.moves_1 = a_element->position;
	elem_insert_set->insert_RA_RB.moves_2 = optimal_position;

	elem_insert_set->insert_RRA_RRB.actions = RRA_RRB;
	elem_insert_set->insert_RRA_RRB.moves_1 = full_stack->size_a - a_element->position;
	elem_insert_set->insert_RRA_RRB.moves_2 = full_stack->size_b - optimal_position;

	elem_insert_set->insert_RA_RRB.actions = RA_RRB;
	elem_insert_set->insert_RA_RRB.moves_1 = a_element->position;
	elem_insert_set->insert_RA_RRB.moves_2 = full_stack->size_b - optimal_position;

	elem_insert_set->insert_RRA_RB.actions = RRA_RB;
	elem_insert_set->insert_RRA_RB.moves_1 = full_stack->size_a - a_element->position;
	elem_insert_set->insert_RRA_RB.moves_2 = optimal_position;

	if (a_element->position == 0) // if a_element is at the top, don't do any reverse rotations
	{
		elem_insert_set->insert_RRA_RB.moves_1 = 0;
		elem_insert_set->insert_RRA_RRB.moves_1 = 0;
	}
	if (optimal_position && optimal_position == full_stack->size_b) // in case we have to place the a_element at the end of b, just one b rotation (RB)
	{
		elem_insert_set->insert_RA_RB.moves_2 = 0; // set to 0 because we order everything in the end
		elem_insert_set->insert_RRA_RB.moves_2 = 0; // set to 0 because we order everything in the end
		elem_insert_set->insert_RRA_RRB.moves_2 = 0;
		elem_insert_set->insert_RA_RRB.moves_2 = 0;
	}
	else if (optimal_position == 0)
	{
		elem_insert_set->insert_RRA_RRB.moves_2 = 0;
		elem_insert_set->insert_RA_RRB.moves_2 = 0;
	}

	printf("\nft_count_required_moves:\n************************\n");
	printf("a_element->value: %d, a_element->position: %d\n\n", a_element->value, a_element->position);

	printf("RA_RB actions:\n");
	printf("\tinsert_RA_RB.moves_1 == a_element->position == %d\n\
	insert_RA_RB.moves_2 == optimal_position == %d\n", elem_insert_set->insert_RA_RB.moves_1, elem_insert_set->insert_RA_RB.moves_2);
	printf("RRA_RRB actions:\n");
	printf("\tinsert_RRA_RRB.moves_1 == %d\n\
	insert_RRA_RRB.moves_2 ==  %d\n", elem_insert_set->insert_RRA_RRB.moves_1, elem_insert_set->insert_RRA_RRB.moves_2);
	printf("RA_RRB actions:\n");
	printf("\tinsert_RA_RRB.moves_1 == %d\n\
	insert_RA_RRB.moves_2 ==  %d\n", elem_insert_set->insert_RA_RRB.moves_1, elem_insert_set->insert_RA_RRB.moves_2);
	printf("RRA_RB actions:\n");
	printf("\tinsert_RRA_RB.moves_1 == %d\n\
	insert_RRA_RB.moves_2 ==  %d\n", elem_insert_set->insert_RRA_RB.moves_1, elem_insert_set->insert_RRA_RB.moves_2);
}

// simplifies each path of insertion, by looking at if both stacks
// can be rotated or reverse rotated together (RR, RRR)
// returns the set of element sorts
void	ft_minimise_moves(t_elem_insert_set *elem_insert_set)
{
	ft_aggregate_moves_RA_RB(&(elem_insert_set->insert_RA_RB));
	ft_aggregate_moves_RRA_RRB(&(elem_insert_set->insert_RRA_RRB));

	ft_print_moves(&(elem_insert_set->insert_RA_RB));
	ft_print_moves(&(elem_insert_set->insert_RRA_RRB));

}

// aggregates common rotations with RR
void	ft_aggregate_moves_RA_RB(t_elem_insert *elem_insert)
{
	// RA && RB
	// RR simplifier: if x* RA && y* RB, min(x, y)RR, max(x,y)-min(x,y) * RA or RB
	// if (elem_insert->action = RA_RB) {
	if (elem_insert->moves_1 < elem_insert->moves_2) // if #RA < #RB, we do all RR for all the RA, then RB for the rest
	{
		elem_insert->actions_aggregated = RR_RB;
		elem_insert->moves_1_aggregated = elem_insert->moves_1; // #RR moves
		elem_insert->moves_2_aggregated = elem_insert->moves_2 - elem_insert->moves_1; // #RB moves
		elem_insert->total_moves_final = elem_insert->moves_1 + elem_insert->moves_2;
	}
	else if (elem_insert->moves_1 > elem_insert->moves_2)
	{
		elem_insert->actions_aggregated = RR_RA;
		elem_insert->moves_1_aggregated = elem_insert->moves_2; // #RR moves
		elem_insert->moves_2_aggregated = elem_insert->moves_1 - elem_insert->moves_2; // #RA moves
		elem_insert->total_moves_final = elem_insert->moves_1 + elem_insert->moves_2;
	}
	else if (elem_insert->moves_1 == elem_insert->moves_2)
	{
		elem_insert->actions_aggregated = RR;
		elem_insert->moves_1_aggregated = elem_insert->moves_2; // #RR moves
		elem_insert->moves_2_aggregated = 0; // (n/a) moves
		elem_insert->total_moves_final = elem_insert->moves_1 + elem_insert->moves_2;
	}
}

// aggregates common rotations with RRR
void	ft_aggregate_moves_RRA_RRB(t_elem_insert *elem_insert)
{
	if (elem_insert->moves_1 < elem_insert->moves_2) // if #RA < #RB, we do all RR for all the RA, then RB for the rest
	{
		elem_insert->actions_aggregated = RRR_RRB;
		elem_insert->moves_1_aggregated = elem_insert->moves_1;
		elem_insert->moves_2_aggregated = elem_insert->moves_2 - elem_insert->moves_1;
		elem_insert->total_moves_final = elem_insert->moves_1_aggregated + elem_insert->moves_2_aggregated;
	}
	else if (elem_insert->moves_1 > elem_insert->moves_2)
	{
		elem_insert->actions_aggregated = RRR_RRA;
		elem_insert->moves_1_aggregated = elem_insert->moves_2;
		elem_insert->moves_2_aggregated = elem_insert->moves_1 - elem_insert->moves_2;
		elem_insert->total_moves_final = elem_insert->moves_1_aggregated + elem_insert->moves_2_aggregated;
	}
	else if (elem_insert->moves_1 == elem_insert->moves_2)
	{
		elem_insert->actions_aggregated = RRR;
		elem_insert->moves_1_aggregated = elem_insert->moves_2;
		elem_insert->moves_2_aggregated = 0;
		elem_insert->total_moves_final = elem_insert->moves_1_aggregated + elem_insert->moves_2_aggregated;
	}
}

// counts the total amount of moves for each set of insertion moves
// call this function BEFORE optimising/aggregating moves 
//(RA_RB => RR_.. , RRA_RRB => RRR_..) with ft_aggregate_moves
void	ft_count_total_insertion_moves(t_elem_insert_set *elem_insert_set)
{
	elem_insert_set->insert_RA_RB.total_moves_final = \
	elem_insert_set->insert_RA_RB.moves_1_aggregated +\
	elem_insert_set->insert_RA_RB.moves_2_aggregated;

	elem_insert_set->insert_RRA_RRB.total_moves_final = \
	elem_insert_set->insert_RRA_RRB.moves_1_aggregated +\
	elem_insert_set->insert_RRA_RRB.moves_2_aggregated;

	elem_insert_set->insert_RRA_RB.total_moves_final = \
	elem_insert_set->insert_RRA_RB.moves_1_aggregated +\
	elem_insert_set->insert_RRA_RB.moves_2_aggregated;

	elem_insert_set->insert_RA_RRB.total_moves_final = \
	elem_insert_set->insert_RA_RRB.moves_1_aggregated +\
	elem_insert_set->insert_RA_RRB.moves_2_aggregated;
}

// selects the optimal insertion for a given element,
// from the various insertions outlined by ft_outline_insertions
t_elem_insert	*ft_select_optimised_insert(t_elem_insert_set *elem_insert_set)
{
	int	RA_RB_total;
	int	RRA_RRB_total;
	int	RA_RRB_total;
	int	RRA_RB_total;
	int	minimal_moves;

	RA_RB_total = elem_insert_set->insert_RA_RB.total_moves_final;
	RRA_RRB_total = elem_insert_set->insert_RRA_RRB.total_moves_final;
	RA_RRB_total = elem_insert_set->insert_RA_RRB.total_moves_final;
	RRA_RB_total = elem_insert_set->insert_RRA_RB.total_moves_final;

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
