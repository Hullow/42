/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:59:32 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 22:27:31 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char *str)
{
    if (*str == 0)
        return (1);
    else
    {
        while (*str != 0)
        {
        if (*str > 47 && *str < 58)
            str++;
        else
            return (0);
        }
        return(1);
    }
}
/* #include <stdio.h>
int main(int argc, char **argv)
{
    argc = 2;
    if (ft_str_is_numeric(argv[1]))
    printf("Your argument, %s, only contains numerical characters.\n", argv[1]);
    else
    printf("Your argument, %s, contains non-numeric characters.\n", argv[1]);
    return(0);
} */