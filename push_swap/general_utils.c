/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:28:08 by fallan            #+#    #+#             */
/*   Updated: 2024/06/11 16:30:19 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// call rotate for RR and RRR
// created to make ft_do_action shorter
void	ft_rotate_both_stacks(int action, t_stacks *stacks)
{
	if (action == RR)
	{
		ft_rotate(&(stacks->a_head), &(stacks->a_tail));
		ft_rotate(&(stacks->b_head), &(stacks->b_tail));
	}
	else if (action == RRR)
	{
		ft_reverse_rotate(&(stacks->a_head), &(stacks->a_tail));
		ft_reverse_rotate(&(stacks->b_head), &(stacks->b_tail));
	}
}

// returns the absolute value of an int
int	ft_abs(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

// returns the minimum between two integer values
int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

// returns the maximum between two integer values
int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
