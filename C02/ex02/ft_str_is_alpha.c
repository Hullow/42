/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:58:13 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 15:58:14 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_str_is_alpha(char *str)
{
    while (*str != '\0')
    {
    if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))) // alphabetical characters: 65 ('A') to 122 ('z')
//    i = 0;
        return (0);
    else
        str++;
    }
    return (1);
}

/*
int main(void)
{
    if (ft_str_is_alpha("") == 1)
    {
        write(1, "The string contains only alphabetical characters", 48);
    }
    else
        write(1, "The string contains non-alphabetical characters", 47);
    return(0);
}
*/