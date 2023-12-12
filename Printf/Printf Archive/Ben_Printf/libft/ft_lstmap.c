/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:49:23 by bwach             #+#    #+#             */
/*   Updated: 2023/10/31 11:35:17 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;
	t_list	*temp;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		newlst = ft_lstnew(temp);
		if (!newlst)
		{
			del (temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, newlst);
		lst = lst->next;
	}
	return (new);
}
