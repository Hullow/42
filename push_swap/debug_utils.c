/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 18:46:38 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // to remove or comment out

void	ft_print_list(t_stack_list *list)
{
	int		i;

	i = -1;
	// ft_printf("ft_print_list: list address %p\n", list);
	while (list)
	{
		printf("%d) %d\n", ++i, list->value); // printf
		list = list->next;
	}
}