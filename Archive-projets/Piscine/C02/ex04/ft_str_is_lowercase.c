/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:39:19 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 16:42:24 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_lowercase(char *str)
{
    if (*str == 0)
        return (1);
    else
    {
        while (*str != 0)
        {
        if (*str > 96 && *str < 123)
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
    if (ft_str_is_lowercase(argv[1]))
    printf("Your argument, %s, only contains lower case alphabetical characters.\n", argv[1]);
    else
    printf("Your argument, %s, contains characters that aren't lower case alphabetical characters.\n", argv[1]);
    return(0);
} */