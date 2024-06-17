/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/06/17 19:34:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_execute_move(char *move, t_stacks *stacks);

void	ft_free_and_exit(char **move, char **temporary, t_stacks **stacks)
{
	void	*temp;

	free(*move);
	free(*temporary);
	while ((*stacks)->b_head)
	{
		if ((*stacks)->b_head->next)
		{
			temp = (*stacks)->b_head->next;
			free((*stacks)->b_head);
			(*stacks)->b_head = temp;
		}
	}
	while ((*stacks)->a_head)
	{
		temp = (*stacks)->a_head->next;
		free((*stacks)->a_head);
		(*stacks)->a_head = temp;
	}
	free(*stacks);
	*stacks = NULL;
	exit(0);
}

int main(int argc, char **argv)
{
	int			i;
	int			found;
	t_stacks	*stacks;

	if (argc == 1)
		return (-1);
	if (argc > 1)
	{
		// takes in stack input and checks it
		i = 0;
		while (argv[++i])
		{
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		stacks = ft_string_to_stack(argv, i);
		ft_find_duplicates(stacks);

		// reads moves from the stdin
		char	*move = malloc(sizeof(char) * 4);
		char	*temp = malloc(sizeof(char) * 40);
		while (read(0, move, 4) > 0)
		{
			found = ft_execute_move(move, stacks);
			// else
			// 	ft_free_and_exit(&move, &temp, &stacks);
			// if (found == 1)
			// 	ft_print_both_stacks(stacks);
			if (found == 0) // typed '\n'
			{
				if (ft_check_stack(stacks) != 0)
					ft_printf("KO\n");
				else
					ft_printf("OK\n");
				ft_free_and_exit(&move, &temp, &stacks);
				ft_free_stacks_and_exit(&stacks);
			}				
			else if (found != 1)
			{
				write(2, "Error\n", 7);
				read(0, temp, found + 47); // found is ft_strlen(move), 47 is the print we just entered to clear the buffer
				// ft_print_both_stacks(stacks);
			}
		}
	}
	return (0);
}

// matches the input (char *move) to an action on the stack 
// and executes the action
// returns the value of found to indicate whether there was a match
int	ft_execute_move(char *move, t_stacks *stacks)
{
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr", "", NULL};
	int	i;
	int	found;

	printf("ft_execute_move\n");
	i = 1;
	found = -1;
	if (move[0] == '\n')
		return (0);
	while (move[++i] && i <= 3)
	{
		if (move[i] == '\n')
		{
			move[i] = '\0';
			found = 1;
			break;
		}
	}
	if (found == -1)
		return (found);
	i = -1;
	found = -1;
	while (table[++i])
	{
		if (!ft_strncmp(move, table[i], 4))
		{
			if (i == 10)
				return (0);
			ft_do_multiple_actions(i + 1, stacks, 1, 1);
			found = 1;
			break;
		}
	}
	if (found == -1)
		found = ft_strlen(move);
	// ft_print_both_stacks(stacks);
	return (found);
}
