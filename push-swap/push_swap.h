/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:26 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 15:30:14 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef INT_MAX
// #define INT_MAX __INT_MAX__

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./lib/libft/libft.h"
#include "./lib/ft_printf/ft_printf.h"

typedef struct	s_stack {
	int	first;
	int	*in_between;
	int	last;
} 	t_stack;

typedef struct	s_full_stack {
	t_stack	*a_stack;
	t_stack	*b_stack;
} 	t_full_stack;

char	*ft_check_input(char *str);
t_stack	*ft_string_to_stack(char **argv, int i);