/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 02:58:02 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef INT_MAX
// #define INT_MAX __INT_MAX__

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8
# define RA_RB 9
# define RRA_RRB 10
# define RRA_RB 11
# define RA_RRB 12

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
	t_stack_list	*a_tail;
	t_stack_list	*b_head;
	t_stack_list	*b_tail;
	int				size_a;
	int				size_b;
} 	t_stacks;

// stores solutions for the sorting of each element
// from stack a in stack b. used to store:
// 1. calculation of smallest #moves to sort an element 
// 2. set of actions to sort an element (for use if chosen)
// nb: actions are a sequence "RA_RB" which is defined to
typedef struct s_element_sort {
	int	total_moves;
	int	moves_a;
	int	moves_b;
	int	actions;
}			t_element_sort;

typedef	struct	s_element_sort_set
{
	t_element_sort	sort_RA_RB;
	t_element_sort	sort_RRA_RRB;
	t_element_sort	sort_RA_RRB;
	t_element_sort	sort_RRA_RB;
}			t_element_sort_set;

// input handling
char		*ft_check_input(char *str);
t_stacks	*ft_string_to_stack(char **argv, int i);

// list evaluation
int		*ft_calculate_min_max(t_stack_list *input_stack);
void	ft_calculate_sizes(t_stacks *full_stack);
void	ft_set_position(t_stack_list *a_stack);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

// list handling
t_stack_list	*ft_new_stack_node(int value);
void			ft_free(void **temp);
void			ft_free_full_stack(t_stacks **full_stack);

// sorting calculations
int		ft_optimal_position(int a_value, t_stack_list *b_stack, int *min_max);
int		ft_calculate_cost(t_stack_list *a_element, int optimal_position, t_stacks *full_stack);

// stack actions
void	ft_do_action(int action, t_stacks *full_stack);
void	ft_do_multiple_actions(int action, t_stacks *full_stack, int moves);
void	ft_do_insertion(int action, t_stacks *full_stack, t_element_sort elem_sort);
void	ft_push_a(t_stacks *full_stack);
void	ft_push_b(t_stacks *full_stack);
void	ft_rotate(t_stack_list **head, t_stack_list **tail);
void	ft_reverse_rotate(t_stack_list **head, t_stack_list **tail);

// debugging
void	ft_print_list(t_stack_list *list);