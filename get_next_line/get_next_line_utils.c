/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:15:46 by fallan            #+#    #+#             */
/*   Updated: 2024/02/08 19:48:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(temp);
	temp->next = new;
}

// copies each element in the list to a string
char	*ft_list_to_string(t_list *lst)
{
	int			length;
	static char	*string; 
	static char	*anchor;

	string = malloc(((BUFFER_SIZE * ft_lstsize(lst)) + 1) * sizeof(char));
	anchor = string;
	printf("\naddress of string is %p\n", string);
	printf("address of anchor is %p\n", anchor);
	printf("ft_lstsize(lst)) is %d\n", ft_lstsize(lst));
	if (lst)
	{
		length = 0;
		if (lst->content)
		{
			length = ft_strlen(lst->content);
			string += ft_strlcpy(string, lst->content, length + 1);
		}
		printf("at this stage, lst->content is %s\n", lst->content);
		ft_list_to_string(lst->next);
	}
	return (anchor);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	if (lst)
		lstsize = 1;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		lstsize++;
	}	
	return (lstsize);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}