/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/05/18 19:21:27 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_position(t_stack_list *a_stack)
{
	int	position;

	position = 0;
	while (a_stack)
	{
		a_stack->position = position++;
		a_stack = a_stack->next;
	}
}

// returns the minimum between two integer values
int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
