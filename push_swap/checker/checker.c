/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/06/18 12:04:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_execute_move(char *move, t_stacks *stacks);

void	ft_free_buffers(char **move, char **temp)
{
	free(*move);
	free(*temp);
	move = NULL;
	temp = NULL;
}

// reads moves from the stdin
int	ft_execute_sequence(int found, t_stacks *stacks)
{
	char	*move;
	
	move = malloc(sizeof(char) * 100);
	move = get_next_line(0);
	if (move)
	{
		found = ft_execute_move(move, stacks);
		while (move)
		{
			move = get_next_line(0);
			found = ft_execute_move(move, stacks);
			if (found == 1)
				continue ;
			else
				break ;
		}
	}
	return (found);
}

t_stacks *ft_input_handling(char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_check_input(argv[i]) == NULL)
		{
			write(2, "Error\n", 7);
			exit (-1);
		}
	}
	stacks = ft_string_to_stack(argv, i);
	ft_find_duplicates(stacks);
	return (stacks);
}

int main(int argc, char **argv)
{
	int			found;
	t_stacks	*stacks;

	found = 0;
	stacks = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (0);
	if (argc > 1)
	{
		stacks = ft_input_handling(argv, stacks);
		found = ft_execute_sequence(found, stacks);
		if (found == 0) // GNL arrived at the end
		{
			if (ft_check_stack(stacks) != 0)
				ft_printf("KO\n");
			else
				ft_printf("OK\n");
			ft_print_both_stacks(stacks);
			// ft_free(&move);
			ft_free_stacks_and_exit(&stacks);
		}
		else if (found != 1)
		{
			ft_printf("found != 1\n");
			write(2, "Error\n", 7);
			// read(0, temp, 19); // found is ft_strlen(move), 47 is the print we just entered to clear the buffer. temp is ...
			ft_print_both_stacks(stacks);
		}
	}
	return (0);
}

// matches the input (char *move) to an action on the stack 
// and executes the action
// returns the value of found to indicate whether there was a match
int	ft_execute_move(char *move, t_stacks *stacks)
{
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr", (char *) "", NULL};
	int	i;
	int	found;

	i = 1;
	found = -1;
	if (!move)
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
	return (found);
}
