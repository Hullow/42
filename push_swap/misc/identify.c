/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:26:41 by fallan            #+#    #+#             */
/*   Updated: 2024/06/05 11:34:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_identify_three_stack(int a, int b, int c)
{
	if (a < b && a < c) // if head is 1 (smallest)
    {
		if (b < c)
			return (123);
		else
			return (132);
    }
	else if (a > b && a > c) // if head is 3 (largest)
    {
    	if (b > c)
			return (321);
		else
			return (312);
    }
	else if (b > c) // if head is in-between value 
		return (231);
	else
		return (213);
}

int main()
{
    printf("1 2 3 : %d\n", ft_identify_three_stack(1, 2, 3));
    printf("1 3 2 : %d\n", ft_identify_three_stack(1, 3, 2));
    printf("3 1 2 : %d\n", ft_identify_three_stack(3, 1, 1));
    printf("3 2 1 : %d\n", ft_identify_three_stack(3, 2, 1));
    printf("2 1 3 : %d\n", ft_identify_three_stack(2, 1, 3));
    printf("2 3 1 : %d\n", ft_identify_three_stack(2, 3, 1));
    return (0);
}