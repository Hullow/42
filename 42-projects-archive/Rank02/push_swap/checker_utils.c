/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:08 by fallan            #+#    #+#             */
/*   Updated: 2024/06/20 17:15:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// reads moves from the stdin and calls ft_execute_move to execute each
// is called from main with value found = 0
// move = get_next_line(0); // we read a new line
// found = ft_find_and_execute_move(move, stacks, 1, -1);
// 		=> we try to execute a move
// if (found == 1) // if we can execute a move, we continue in the loop
// 	continue ;
// else // if (found == 0 || found == -1)
// 	break ;
int	ft_read_and_execute_sequence(int found, t_stacks *stacks)
{
	char	*move;
	char	*temp;

	move = get_next_line(0);
	temp = move;
	if (move)
	{
		found = ft_find_and_execute_move(move, stacks, 1, -1);
		while (move)
		{
			move = get_next_line(0);
			found = ft_find_and_execute_move(move, stacks, 1, -1);
			if (move)
				free(move);
			if (found == 1)
				continue ;
			else
				break ;
		}
	}
	ft_free((void **)&temp);
	return (found);
}

// initialize table of actions that will be compared
// to each char *move from input
char	**ft_initialize_table(char **table)
{
	table = (char **)malloc (sizeof(char *) * 11);
	table[0] = "sa";
	table[1] = "sb";
	table[2] = "pa";
	table[3] = "pb";
	table[4] = "ra";
	table[5] = "rb";
	table[6] = "rra";
	table[7] = "rrb";
	table[8] = "rr";
	table[9] = "rrr";
	table[10] = NULL;
	return (table);
}

// check input to find \n and replace it with \0
// this is a precondition to allow strncmp with 
// actions (sa, sb, pa, pb, ra, rra, ..)
// if no newline is found, we have a problem: return -1
int	ft_find_newline(char *move, int i)
{
	if (move[0] == '\n')
		return (0);
	while (move[++i] && i <= 3)
	{
		if (move[i] == '\n')
		{
			move[i] = '\0';
			return (1);
			break ;
		}
	}
	return (-1);
}

// matches the input (char *move) to an action on the stack
// and executes the action
// returns the value of found to indicate whether there was a match:
// found == 0 if we've arrived at the end (move == NULL)
// found == 1 if an input line was matched to an existing move from the table
// found == -1 if the input char *move cannot be an existing action (1st while),
// or we couldn't match the string with any action from the table
// nb: the first while() replaces the \n with a \0 to enable ft_strcmp
int	ft_find_and_execute_move(char *move, t_stacks *stacks, int i, int found)
{
	char	**table;

	if (!move)
		return (0);
	found = ft_find_newline(move, i);
	if (found == -1)
		return (-1);
	else if (found == 0)
		return (0);
	table = ft_initialize_table(NULL);
	i = -1;
	found = -1;
	while (table[++i])
	{
		found = ft_match_input_and_execute_move(move, table[i], stacks, i);
		if (found == 1)
			break ;
	}
	free(table);
	return (found);
}

// if we match input (char *move) to a table entry, 
// i.e. to an existing action on the stack,
// we execute the action and return 1
// if we did not match a move, return -1
int	ft_match_input_and_execute_move(char *move, char *table_entry, \
		t_stacks *stacks, int i)
{
	if (!ft_strncmp(move, table_entry, 4))
	{
		ft_do_multiple_actions(i + 1, stacks, 1, 1);
		return (1);
	}
	else
		return (-1);
}
