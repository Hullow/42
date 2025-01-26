/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:57:48 by fallan            #+#    #+#             */
/*   Updated: 2024/06/17 17:37:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds the cheapest insertion and sets the corresponding moves
// in the variable cost
void	ft_calculate_cost(t_stack *a_elem, t_stacks *stacks, t_cost *cost)
{
	int	i;

	ft_calculate_sizes(stacks);
	ft_set_positions(stacks);
	ft_set_initial_costs(a_elem, stacks, cost);
	i = ft_cheapest_cost_sequence (cost);
	ft_set_cheapest_cost(cost, i);
}

// set initial costs for an insertion
// the values correspond to moves needed 
// to move a_elem to top of stack a
// and down to its optimal position in stack b
	// if() optimisation: if a_elem/b_element is 
	// already at the top, don't do any reverse rotations
// aggregates rotations into RR and RRR with ft_min
// then calculates minimal necessary rotations ("...._aggregated")
// finally, computes the total number of moves to enable a comparison
// first count of moves required for each rotation combination,
// without optimization (aggregation, done by ft_aggregate_moves)
	// RA_to_top = a_elem->position; 
		// if in position 0, 0 moves. if position 1, 1 move. etc.
	// RRA_to_top = stacks->size_a - a_elem->position;
	// RB_to_optimal = optimal_position;
		// if optimal position is 0, 0 moves. if position 1, 1 move. etc.
	// RRB_to_optimal = stacks->size_b - optimal_position;
void	ft_set_initial_costs(t_stack *a_elem, t_stacks *stacks, t_cost *cost)
{
	int		optimal_position;

	optimal_position = \
		ft_optimal_position(a_elem->value, stacks->b_head, INT_MAX);
	cost->x_ra = a_elem->position;
	cost->x_rra = stacks->size_a - cost->x_ra;
	if (a_elem->position == 0)
		cost->x_rra = 0;
	cost->x_rb = optimal_position;
	cost->x_rrb = stacks->size_b - cost->x_rb;
	if (optimal_position == 0)
	{
		cost->x_rrb = 0;
		cost->x_rb = 0;
	}
	cost->x_rr = ft_min(cost->x_ra, cost->x_rb);
	cost->x_rrr = ft_min(cost->x_rra, cost->x_rrb);
	cost->x_rb_aggregated = cost->x_rb - cost->x_rr;
	cost->x_rrb_aggregated = cost->x_rrb - cost->x_rrr;
	cost->x_ra_aggregated = cost->x_ra - cost->x_rr;
	cost->x_rra_aggregated = cost->x_rra - cost->x_rrr;
	cost->total = cost->x_ra + cost->x_rb + \
	cost->x_rra + cost->x_rrb + cost->x_rr + cost->x_rrr;
}

// computes cost of each possible sequence of rotations,
	// i.e. (RR + RA + RB, RRR + RRA + RRB, RA + RRB, RRA + RB)
// then finds and returns index of cheapest sequence
int	ft_cheapest_cost_sequence(t_cost *cost)
{
	int	cost_sequence[4];
	int	min_cost;
	int	i;

	cost_sequence[0] = cost->x_rr + \
	ft_max(cost->x_ra, cost->x_rb) - ft_min(cost->x_ra, cost->x_rb);
	cost_sequence[1] = cost->x_rrr + \
	ft_max(cost->x_rra, cost->x_rrb) - ft_min(cost->x_rra, cost->x_rrb);
	cost_sequence[2] = cost->x_ra + cost->x_rrb;
	cost_sequence[3] = cost->x_rb + cost->x_rra;
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
		cost->x_rrr = 0;
		cost->x_rra = 0;
		cost->x_rrb = 0;
		cost->x_ra = cost->x_ra_aggregated;
		cost->x_rb = cost->x_rb_aggregated;
	}
	else if (i == 1)
	{
		cost->x_rr = 0;
		cost->x_ra = 0;
		cost->x_rb = 0;
		cost->x_rra = cost->x_rra_aggregated;
		cost->x_rrb = cost->x_rrb_aggregated;
	}
	else if (i == 2)
		ft_set_cheapest_cost_annex(cost, i);
	else if (i == 3)
		ft_set_cheapest_cost_annex(cost, i);
	cost->total = cost->x_ra + cost->x_rb + \
	cost->x_rra + cost->x_rrb + cost->x_rr + cost->x_rrr;
}

// annex of ft_set_cheapest_cost
void	ft_set_cheapest_cost_annex(t_cost *cost, int i)
{
	if (i == 2)
	{
		cost->x_rr = 0;
		cost->x_rb = 0;
		cost->x_rrr = 0;
		cost->x_rra = 0;
	}
	else if (i == 3)
	{
		cost->x_rr = 0;
		cost->x_ra = 0;
		cost->x_rrr = 0;
		cost->x_rrb = 0;
	}
}
