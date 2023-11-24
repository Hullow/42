/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:58:36 by fallan            #+#    #+#             */
/*   Updated: 2023/11/24 18:09:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current = *lst;
	while (current->next != NULL)
		current = current->next;
	
	current->next = (t_list *)malloc(sizeof(t_list));
	current->next->content = &new;
	current->next->next = NULL;
}