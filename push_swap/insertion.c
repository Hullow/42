/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 18:02:48 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// performs the optimal insertion the selected element of a into b
void	ft_do_optimal_insertion(t_stacks *full_stack, t_cost *min_cost_insert)
{
	ft_do_multiple_actions(RA, full_stack, min_cost_insert->xRA, 0);
	ft_do_multiple_actions(RB, full_stack, min_cost_insert->xRB, 0);
	ft_do_multiple_actions(RR, full_stack, min_cost_insert->xRR, 0);
	ft_do_multiple_actions(RRA, full_stack, min_cost_insert->xRRA, 0);
	ft_do_multiple_actions(RRB, full_stack, min_cost_insert->xRRB, 0);
	ft_do_multiple_actions(RRR, full_stack, min_cost_insert->xRRR, 0);
	ft_do_multiple_actions(PB, full_stack, 1, 0);
}