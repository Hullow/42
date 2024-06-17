/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:24:15 by fallan            #+#    #+#             */
/*   Updated: 2024/06/17 19:12:31 by fallan           ###   ########.fr       */
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

// free each element of each stack, and then the whole stack
void	ft_free_stacks_and_exit(t_stacks **stacks)
{
	void	*temp;

	while ((*stacks)->b_head)
	{
		if ((*stacks)->b_head->next)
		{
			temp = (*stacks)->b_head->next;
			free((*stacks)->b_head);
			(*stacks)->b_head = temp;
		}
	}
	while ((*stacks)->a_head)
	{
		temp = (*stacks)->a_head->next;
		free((*stacks)->a_head);
		(*stacks)->a_head = temp;
	}
	free(*stacks);
	*stacks = NULL;
	exit (0);
}
