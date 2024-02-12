/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:43:01 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 16:44:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_uppercase(char *str)
{
    if (*str == 0)
        return (1);
    else
    {
        while (*str != 0)
        {
        if (*str > 64 && *str < 91)
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
    if (ft_str_is_uppercase(argv[1]))
    printf("Your argument, %s, only contains upper case alphabetical characters.\n", argv[1]);
    else
    printf("Your argument, %s, contains characters that aren't upper case alphabetical characters.\n", argv[1]);
    return(0);
} */