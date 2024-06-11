/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:57:48 by fallan            #+#    #+#             */
/*   Updated: 2024/06/11 16:52:38 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds the cheapest insertion and sets the corresponding moves
// in the variable cost
void	ft_calculate_cost(t_stack *a_element, t_stacks *stacks, t_cost *cost)
{
	int	i;

	ft_calculate_sizes(stacks);
	ft_set_positions(stacks);
	ft_set_initial_costs(a_element, stacks, cost);
	i = ft_cheapest_cost_sequence (cost);
	ft_set_cheapest_cost(cost, i);
}

// set initial costs for an insertion
// the values correspond to moves needed 
// to move a_element to top of stack a
// and down to its optimal position in stack b
	// if() optimisation: if a_element/b_element is 
	// already at the top, don't do any reverse rotations
// aggregates rotations into RR and RRR with ft_min
// then calculates minimal necessary rotations ("...._aggregated")
// finally, computes the total number of moves to enable a comparison
// first count of moves required for each rotation combination,
// without optimization (aggregation, done by ft_aggregate_moves)
	// RA_to_top = a_element->position; 
		// if in position 0, 0 moves. if position 1, 1 move. etc.
	// RRA_to_top = stacks->size_a - a_element->position;
	// RB_to_optimal = optimal_position;
		// if optimal position is 0, 0 moves. if position 1, 1 move. etc.
	// RRB_to_optimal = stacks->size_b - optimal_position;
void	ft_set_initial_costs(t_stack *a_element, t_stacks *stacks, t_cost *cost)
{
	int		optimal_position;

	optimal_position = ft_optimal_position(a_element->value, stacks->b_head);
	cost->xRA = a_element->position;
	cost->xRRA = stacks->size_a - cost->xRA;
	if (a_element->position == 0)
		cost->xRRA = 0;
	cost->xRB = optimal_position;
	cost->xRRB = stacks->size_b - cost->xRB;
	// optimisation: if optimal_position is at the top, do 0 reverse rotations
	if (optimal_position == 0) // removed this: || optimal_position == stacks->size_b)
	{
		cost->xRRB = 0; // why not 1 ? (because we order it anyway; but try it)
		cost->xRB = 0;
	}
	cost->xRR = ft_min(cost->xRA, cost->xRB);
	cost->xRRR = ft_min(cost->xRRA, cost->xRRB);
	cost->xRB_aggregated = cost->xRB - cost->xRR;
	cost->xRRB_aggregated = cost->xRRB - cost->xRRR;
	cost->xRA_aggregated = cost->xRA - cost->xRR;
	cost->xRRA_aggregated = cost->xRRA - cost->xRRR;
	cost->total = cost->xRA + cost->xRB + \
	cost->xRRA + cost->xRRB + cost->xRR + cost->xRRR;
}

// computes cost of each possible sequence of rotations,
	// i.e. (RR + RA + RB, RRR + RRA + RRB, RA + RRB, RRA + RB)
// then finds and returns index of cheapest sequence
int	ft_cheapest_cost_sequence(t_cost *cost)
{
	int	cost_sequence[4];
	int	min_cost;
	int	i;

	cost_sequence[0] = cost->xRR + \
	ft_max(cost->xRA, cost->xRB) - ft_min(cost->xRA, cost->xRB);
	cost_sequence[1] = cost->xRRR + \
	ft_max(cost->xRRA, cost->xRRB) - ft_min(cost->xRRA, cost->xRRB);
	cost_sequence[2] = cost->xRA + cost->xRRB;
	cost_sequence[3] = cost->xRB + cost->xRRA;
	i = -1;
	min_cost = ft_min(ft_min(cost_sequence[0], cost_sequence[1]), \
	ft_min(cost_sequence[2], cost_sequence[3]));
	while (++i < 4)
		if (min_cost == cost_sequence[i])
			break ;
	return (i);
}

// changes the variable cost to only contain
// the cheapest set of moves for an insertion
void	ft_set_cheapest_cost(t_cost *cost, int i)
{
	if (i == 0)
	{
		cost->xRRR = 0;
		cost->xRRA = 0;
		cost->xRRB = 0;
		cost->xRA = cost->xRA_aggregated;
		cost->xRB = cost->xRB_aggregated;
	}
	else if (i == 1)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRB = 0;
		cost->xRRA = cost->xRRA_aggregated;
		cost->xRRB = cost->xRRB_aggregated;
	}
	else if (i == 2)
		ft_set_cheapest_cost_annex(cost, i);
	else if (i == 3)
		ft_set_cheapest_cost_annex(cost, i);
	cost->total = cost->xRA + cost->xRB + \
	cost->xRRA + cost->xRRB + cost->xRR + cost->xRRR;
}

// annex of ft_set_cheapest_cost
void	ft_set_cheapest_cost_annex(t_cost *cost, int i)
{
	if (i == 2)
	{
		cost->xRR = 0;
		cost->xRB = 0;
		cost->xRRR = 0;
		cost->xRRA = 0;
	}
	else if (i == 3)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRRR = 0;
		cost->xRRB = 0;
	}
}
