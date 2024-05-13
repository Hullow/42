/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/05/14 00:10:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef INT_MAX
// #define INT_MAX __INT_MAX__

# define PA 1
# define PB 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

typedef	struct	s_stack_list {
	int					value;
	int					position;
	struct s_stack_list	*next;
}	t_stack_list;

typedef	struct	s_stacks {
	t_stack_list	*a_head;
	t_stack_list	*a_penultimate;
	t_stack_list	*a_tail;
	t_stack_list	*b_head;
	t_stack_list	*b_penultimate;
	t_stack_list	*b_tail;
} 	t_stacks;

// input handling
char		*ft_check_input(char *str);
t_stacks	*ft_string_to_stack(char **argv, int i);

// list handling
t_stack_list	*ft_new_stack_node(int value);
void			ft_free(void **temp);
void			ft_free_full_stack(t_stacks **full_stack);

// stack actions
void	ft_do_action(int action, t_stacks *full_stack);
void	ft_push_a(t_stacks *full_stack);
void	ft_push_b(t_stacks *full_stack);
void	ft_rotate(t_stack_list **head, t_stack_list **tail);
void	ft_reverse_rotate(t_stack_list **head, t_stack_list **tail);

// debugging
void	ft_print_list(t_stack_list *list);