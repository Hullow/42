/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/05/30 19:40:51 by fallan           ###   ########.fr       */
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
# define RRR 10

# define RRA_RRB 11
# define RRA_RB 12
# define RA_RRB 13
# define RR_RB 14
# define RR_RA 15
# define RRR_RRB 16
# define RRR_RRA 17

# define RA_RB 18

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

typedef struct s_cost {
	int xRA;
	int xRB;
	int xRRA;
	int xRRB;
	int xRA_aggregated;
	int xRB_aggregated;
	int xRRA_aggregated;
	int xRRB_aggregated;
	int xRR;
	int xRRR;
	int	total;
}			t_cost;
typedef	struct	s_stack_list {
	int					value;
	int					position;
	struct s_stack_list	*next;
	struct s_cost cost;
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
	int	moves_1;
	int	moves_2;
	int	actions;
	int	moves_1_aggregated;
	int	moves_2_aggregated;
	int	actions_aggregated;
	int	total_moves_final;
}			t_elem_insert;

typedef	struct	s_element_insertion_set
{
	t_elem_insert	insert_RA_RB;
	t_elem_insert	insert_RRA_RRB;
	t_elem_insert	insert_RA_RRB;
	t_elem_insert	insert_RRA_RB;
	t_elem_insert	optimal_insertion;
}			t_elem_insert_set;

// input handling
char		*ft_check_input(char *str);
t_stacks	*ft_string_to_stack(char **argv, int i);
void		ft_find_duplicates(t_stacks *full_stack);

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
void			ft_set_positions(t_stacks *full_stack);
void			ft_calculate_sizes(t_stacks *full_stack);
t_stack_list	*ft_stack_max_value(t_stack_list *stack_element);

// general utils
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int number);

// insertion
void	ft_calculate_cost(t_stack_list *a_element, t_stacks *full_stack, t_cost *cost);

// calculation
void			ft_do_optimal_insertion(t_stacks *full_stack);
t_elem_insert	*ft_find_optimal_insertion(t_stack_list *a_element, t_stacks *full_stack);
int				ft_optimal_position(int a_value, t_stack_list *b_stack);
void			ft_minimise_moves(t_elem_insert_set *elem_insert_set);
void			ft_count_total_insertion_moves(t_elem_insert_set *elem_insert_set);
void			ft_count_required_moves(t_stack_list *a_element, t_stacks *full_stack, t_elem_insert_set *elem_insert_set);
void			ft_aggregate_moves_RA_RB(t_elem_insert *elem_insert);
void			ft_aggregate_moves_RRA_RRB(t_elem_insert *elem_insert);
t_elem_insert	*ft_select_optimised_insert(t_elem_insert_set *elem_insert_set);

	// moves
void	ft_do_insertion(t_stacks *full_stack, t_elem_insert *elem_insert);
void	ft_do_multiple_actions(int action, t_stacks *full_stack, int moves);
void	ft_do_action(int action, t_stacks *full_stack);

// debugging
void	ft_print_both_stacks(t_stacks *full_stack);
void	ft_print_stack(t_stack_list *list);
void	ft_print_moves(t_elem_insert *insertion);