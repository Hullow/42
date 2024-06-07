/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 12:06:42 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_positions(t_stacks *full_stack)
{
	int				position;
	t_stack_list	*stack_iterator;

	position = 0;
	stack_iterator = full_stack->a_head;
	while (stack_iterator)
	{
		stack_iterator->position = position++;
		// printf("full_stack->a_head->value: %d, full_stack->a_head->position: %d\n", full_stack->a_head->value, full_stack->a_head->position);
		stack_iterator = stack_iterator->next;
	}
	position = 0;
	stack_iterator = full_stack->b_head;
	while (stack_iterator)
	{
		// printf("stack_iterator->value: %d, stack_iterator->position: %d\n", stack_iterator->value, stack_iterator->position);
		stack_iterator->position = position++;
		stack_iterator = stack_iterator->next;
	}
}

// calculates and sets the size of each stack
void	ft_calculate_sizes(t_stacks *full_stack)
{
	t_stack_list	*anchor;

	full_stack->size_a = 0;
	full_stack->size_b = 0;
	anchor = full_stack->a_head;
	if (full_stack->a_head)
	{
		while (full_stack->a_head)
		{
			full_stack->size_a++;
			full_stack->a_head = full_stack->a_head->next;
		}
	}
	full_stack->a_head = anchor;
	if (full_stack->b_head)
	{
		anchor = full_stack->b_head;
		while (full_stack->b_head)
		{
			full_stack->size_b++;
			full_stack->b_head = full_stack->b_head->next;
		} 
		full_stack->b_head = anchor;
	}
}

// returns the node that has the highest value of a stack
t_stack_list	*ft_stack_max_value(t_stack_list *stack_element)
{
	t_stack_list	*max;

	max = stack_element;
	while (stack_element)
	{
		if (stack_element->value > max->value)
			max = stack_element;
		stack_element = stack_element->next;
	}
	if (max->value == INT_MIN)
		ft_printf("ft_stack_max_value: error\n");
	// ft_printf("ft_stack_max_value: maximum found: %d\n", max->value);
	return (max);
}

// returns the node that has the smallest value of a stack
t_stack_list	*ft_stack_min_value(t_stack_list *stack_element)
{
	t_stack_list	*min;

	min = stack_element;
	while (stack_element)
	{
		if (stack_element->value < min->value)
			min = stack_element;
		stack_element = stack_element->next;
	}
	if (min->value == INT_MIN)
		ft_printf("ft_stack_min_value: error\n");
	// ft_printf("ft_stack_min_value: minimum found: %d\n", min->value);
	return (min);
}

// returns the node that has the smallest value of a stack
t_stack_list	*ft_second_smallest_value(t_stack_list *stack_element, int min)
{
	t_stack_list	*sec_min;

	sec_min = stack_element;
	while (stack_element)
	{
		if ((stack_element->value < sec_min->value) && (stack_element->value != min))
			sec_min = stack_element;
		stack_element = stack_element->next;
	}
	if (sec_min->value == INT_MIN)
		ft_printf("ft_second_smallest_value: error\n");
	// ft_printf("ft_second_smallest_value: second smallest value found: %d\n", sec_min->value);
	return (sec_min);
}

// checks if the stack a is ordered
int	ft_check_stack(t_stacks	*full_stack)
{
	t_stack_list	*anchor;

	anchor = full_stack->a_head;
	while (full_stack->a_head->next)
	{
		if (full_stack->a_head->value >= full_stack->a_head->next->value)
		{
			full_stack->a_head = anchor;
			return (-1);
		}
		full_stack->a_head = full_stack->a_head->next;
	}
	if (full_stack->b_head || full_stack->size_b)
	{
		full_stack->a_head = anchor;
		return (1);
	}
	full_stack->a_head = anchor;
	// ft_printf("OK\n");
	return (0);
}

// hardcoded sorting of small stacks (size < 6)
void	ft_sort_small_stack(t_stacks *full_stack)
{
	if (full_stack->size_a == 3 && ft_check_stack(full_stack) != 0)
		ft_sort_three_elements(full_stack);
	else if (full_stack->size_a == 4 && ft_check_stack(full_stack) != 0)
		ft_sort_four_elements(full_stack);
	else if (full_stack->size_a == 5 && ft_check_stack(full_stack) != 0)
		ft_sort_five_elements(full_stack);
}

// identifies the precise order of a three element stack
// outputs a number corresponding to the order:
// e.g. 132 : stack order is smallest, largest, in-between value
int	ft_three_stack_order(t_stack_list *a_head)
{
	// ft_print_stack(a_head);
	if (a_head->value < a_head->next->value && a_head->value < a_head->next->next->value) // if head is 1 (smallest)
    {
		if (a_head->next->value < a_head->next->next->value)
			return (123);
		else
			return (132);
    }
	else if (a_head->value > a_head->next->value && a_head->value > a_head->next->next->value) // if head is 3 (largest)
    {
    	if (a_head->next->value > a_head->next->next->value)
			return (321);
		else
			return (312);
    }
	else if (a_head->next->value > a_head->next->next->value) // if head is in-between value
		return (231);
	else
		return (213);
}


// hardcoded sort of stacks a of three elements
// stack_order must be calculated
void	ft_sort_three_elements(t_stacks *full_stack)
{
	int	stack_order;
	stack_order = ft_three_stack_order(full_stack->a_head);
	if (stack_order == 132)
	{
		ft_do_multiple_actions(RRA, full_stack, 1, 0);
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	}
	else if (stack_order == 213)
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	else if (stack_order == 231)
		ft_do_multiple_actions(RRA, full_stack, 1, 0);
	else if (stack_order == 312)
		ft_do_multiple_actions(RA, full_stack, 1, 0);
	else if (stack_order == 321)
	{
		ft_do_multiple_actions(RA, full_stack, 1, 0);
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	}
}

// hardcoded sort of four element stacks
void	ft_sort_four_elements(t_stacks *full_stack)
{
		// printf("sorting stack size == 4\n");
		t_stack_list *min = ft_stack_min_value(full_stack->a_head);
		if (min->position < 2)
		{
			ft_do_multiple_actions(RA, full_stack, min->position, 0);
			ft_do_multiple_actions(PB, full_stack, 1, 0);
		}
		else
		{
			ft_do_multiple_actions(RRA, full_stack, 4 - min->position, 0);
			ft_do_multiple_actions(PB, full_stack, 1, 0);
		}
		// ft_print_both_stacks(full_stack);
		ft_sort_three_elements(full_stack);
		// ft_print_both_stacks(full_stack);
		ft_do_multiple_actions(PA, full_stack, 1, 0);
}

// pushes the two smallest elements of a to be in an economical way
// hardcoded for stacks of five elements
void	ft_push_two_smallest_elements(t_stacks *full_stack, t_stack_list *min, t_stack_list *sec_min)
{
	int	pushed;

	pushed = 0;
	// printf("min->position: %d, sec_min->position: %d\n", min->position, sec_min->position);
	if (full_stack->a_head == min || full_stack->a_head == sec_min) // position == 0 => one move
	{
		printf("if\n");
		ft_do_multiple_actions(PB, full_stack, 1, 0);
		pushed = 1;
	}
	else
	{
		printf("else\n");
		printf("full_stack->a_head->next: %d at %p, sec_min: %d at %p\n", full_stack->a_head->next->value, full_stack->a_head->next, sec_min->value, sec_min);
		if (min->position == 4 || sec_min->position == 4)
			ft_do_multiple_actions(RRA, full_stack, 1, 0);
		else if (full_stack->a_head->next == min || full_stack->a_head->next == sec_min)
			ft_do_multiple_actions(RA, full_stack, 1, 0);
		else if ((full_stack->size_a == 4) && (min->position == 3 || sec_min->position == 3))
			ft_do_multiple_actions(RRA, full_stack, 1, 0);
		else if ((full_stack->size_a == 5) && (min->position == 3 || sec_min->position == 3))
			ft_do_multiple_actions(RRA, full_stack, 2, 0);
		else if (min->position == 2 || sec_min->position == 2)
			ft_do_multiple_actions(RA, full_stack, 2, 0);
	}
	if (pushed == 0)
		ft_do_multiple_actions(PB, full_stack, 1, 0);
	if (full_stack->size_b == 2 && (full_stack->b_head->value < full_stack->b_head->next->value)) // order two small elements on b
		ft_do_multiple_actions(SB, full_stack, 1, 0);
}


// hardcoded sort of five element stacks
void	ft_sort_five_elements(t_stacks *full_stack)
{
		// printf("sorting stack size == 5\n");
		// ft_print_both_stacks(full_stack);
			
		t_stack_list	*min;
		t_stack_list	*sec_min;

		min = ft_stack_min_value(full_stack->a_head);
		sec_min = ft_second_smallest_value(full_stack->a_head, min->value);
		ft_push_two_smallest_elements(full_stack, min, sec_min);
			// ft_print_both_stacks(full_stack);
		ft_push_two_smallest_elements(full_stack, min, sec_min);
			// ft_print_both_stacks(full_stack);
		ft_sort_three_elements(full_stack);
		ft_do_multiple_actions(PA, full_stack, 2, 0);
		// ft_print_both_stacks(full_stack);
}

/* 
	ft_calculate_sizes(full_stack);
	ft_set_positions(full_stack);
	int optimal_position = ft_optimal_position(a_element->value, full_stack->b_head);
	// printf("\nft_calculate_cost:\n");
	// printf("\t- size: a:%d, b:%d, optimal_position for \"%d\": %d\n", full_stack->size_a, full_stack->size_b, a_element->value, optimal_position);

	cost->xRA = a_element->position;
	cost->xRRA = full_stack->size_a - cost->xRA;
	if (a_element->position == 0)  // optimisation: if a_element is already at the top, don't do any reverse rotations
		cost->xRRA = 0;

	cost->xRB = optimal_position;
	cost->xRRB = full_stack->size_b - cost->xRB;
	if (optimal_position == 0 || optimal_position == full_stack->size_b)  // optimisation: if optimal_position is at the top, do 0 reverse rotations
	{
		cost->xRRB = 0;
		cost->xRB = 0;
	}
 */