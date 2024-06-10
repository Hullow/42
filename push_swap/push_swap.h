/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:41:14 by fallan           ###   ########.fr       */
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
}	t_stack;

typedef	struct	s_stacks {
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;
	t_stack	*b_tail;
	int				size_a;
	int				size_b;
} 	t_stacks;

// input handling
char		*ft_check_input(char *str);
t_stacks	*ft_string_to_stack(char **argv, int i);
void		ft_find_duplicates(t_stacks *stacks);

// list handling
t_stack	*ft_new_stack_node(int value);
void	ft_free_stacks(t_stacks **stacks);
void	ft_free(void **temp);

// stack utils
int		ft_check_stack(t_stacks	*stacks);
void	ft_set_positions(t_stacks *stacks);
void	ft_calculate_sizes(t_stacks *stacks);
t_stack	*ft_stack_max_value(t_stack *stack_element);
t_stack	*ft_stack_min_value(t_stack *stack_element);

// sorting
void	ft_sort(t_stacks *stacks);
void	ft_sort_small_stack(t_stacks *stacks);
void	ft_sort_large_stack(t_stacks *stacks);
void	ft_sort_and_empty_stack_b(t_stacks *stacks);

// sorting small stacks
int		ft_three_stack_order(t_stack *a_head);
void	ft_sort_three_elements(t_stacks *stacks);
void	ft_sort_four_elements(t_stacks *stacks);
void	ft_sort_five_elements(t_stacks *stacks);

// general utils
int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	ft_abs(int number);

// cost
void	ft_calculate_cost(t_stack *a_element, t_stacks *stacks, t_cost *cost);
void	ft_set_min_cost(t_cost *cost, t_cost *min_cost_insert);

// stack actions
void	ft_swap(t_stack **head, t_stack **tail, int stack_size);
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);
void	ft_rotate(t_stack **head, t_stack **tail);
void	ft_reverse_rotate(t_stack **head, t_stack **tail);
void	ft_rotate_both_stacks(int action, t_stacks *stacks);

// moves
void	ft_do_multiple_actions(int action, t_stacks *stacks, int moves, int checker);
void	ft_do_action(int action, t_stacks *stacks);

// insertion
void	ft_do_cheapest_insertion(t_stacks *stacks, t_cost *min_cost_insert);
int		ft_optimal_position(int a_value, t_stack *b_stack);

// debugging
// void	ft_print_both_stacks(t_stacks *stacks);
// void	ft_print_stack(t_stack *list);