/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:24:15 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 18:34:07 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adapted from ft_lstnew (libft bonus)
t_stack	*ft_new_stack_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_free(void **temp)
{
	if (*temp)
	{
		free(*temp);
		*temp = NULL;
	}
}

void	ft_free_full_stack(t_stacks **full_stack)
{
	void	*temp;
	while ((*full_stack)->b_head)
	{
		temp = (*full_stack)->b_head->next;
		free((*full_stack)->b_head);
		(*full_stack)->b_head = temp;
	}
	while ((*full_stack)->a_head)
	{
		temp = (*full_stack)->a_head->next;
		free((*full_stack)->a_head);
		(*full_stack)->a_head = temp;
	}
	free(*full_stack);
	*full_stack = NULL;
}

