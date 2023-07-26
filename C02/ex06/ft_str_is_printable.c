/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:45:32 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 16:51:37 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_printable(char *str)
{
    if (*str == 0)
        return (1);
    else
    {
        while (*str != 0)
        {
        if (*str > 31 && *str < 127)
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
    if (ft_str_is_printable(argv[1]))
    printf("Your argument, %s, only contains printable characters.\n", argv[1]);
    else
    printf("Your argument, %s, contains non-printable characters.\n", argv[1]);
    return(0);
} */