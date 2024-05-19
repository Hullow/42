/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 12:37:21 by francis          ###   ########.fr       */
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

# define RR 9

# define RA_RB 10
# define RRA_RRB 11
# define RRA_RB 12
# define RA_RRB 13

# define RR_RB 14
# define RR_RA 15
# define RRR_RRB 16
# define RRR_RRA 17

# define RRR 18

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
typedef struct s_element_insertion {
	int	total_moves;
	int	moves_1;
	int	moves_2;
	int	actions;
}			t_elem_insert;

typedef	struct	s_element_insertion_set
{
	t_elem_insert	insert_RA_RB;
	t_elem_insert	insert_RRA_RRB;
	t_elem_insert	insert_RA_RRB;
	t_elem_insert	insert_RRA_RB;
}			t_elem_insert_set;

// input handling
char		*ft_check_input(char *str);
t_stacks	*ft_string_to_stack(char **argv, int i);

// list handling
t_stack_list	*ft_new_stack_node(int value);
void			ft_free_full_stack(t_stacks **full_stack);
void			ft_free(void **temp);

// stack actions
void	ft_push_a(t_stacks *full_stack);
void	ft_push_b(t_stacks *full_stack);
void	ft_rotate(t_stack_list **head, t_stack_list **tail);
void	ft_reverse_rotate(t_stack_list **head, t_stack_list **tail);

// stack utils
void	ft_set_position(t_stack_list *a_stack);
int		ft_min(int a, int b);
int		*ft_calculate_min_max(t_stack_list *input_stack);
void	ft_calculate_sizes(t_stacks *full_stack);

// insertion
// calculation

int	ft_optimal_position(int a_value, t_stack_list *b_stack, int *min_max);
t_elem_insert	*ft_optimal_insertion(t_stack_list *a_element, t_stacks *full_stack);
void	ft_minimise_moves(t_elem_insert_set *elem_insert_set);
void	ft_count_total_moves(t_elem_insert **elem_insert);
void	ft_count_total_set_moves(t_elem_insert_set *elem_insert_set);
void	ft_count_required_moves(t_stack_list *a_element, t_stacks *full_stack, int optimal_position, t_elem_insert_set *elem_insert_set);
void	ft_aggregate_moves_RA_RB(t_elem_insert **elem_insert);
void	ft_aggregate_moves_RRA_RRB(t_elem_insert **elem_insert);
t_elem_insert	*ft_select_best_insert(t_elem_insert_set *elem_insert_set);

	// moves
void	ft_do_insertion(int action, t_stacks *full_stack, t_elem_insert elem_insert);
void	ft_do_multiple_actions(int action, t_stacks *full_stack, int moves);
void	ft_do_action(int action, t_stacks *full_stack);

// debugging
void	ft_print_list(t_stack_list *list);