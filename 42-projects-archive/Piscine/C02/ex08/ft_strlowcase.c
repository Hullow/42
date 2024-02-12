/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:05:30 by fallan            #+#    #+#             */
/*   Updated: 2023/07/26 19:00:02 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strlowcase(char *str)
{
    char    *temp;

    temp = str;
    while (*str != 0)
        {
            if (*str > 64 && *str < 91)
            *str += 32;
            str++;
        }
        return(temp);
}
/* #include <stdio.h>
int main(int argc, char **argv)
{
    argc = 2;
    ft_strlowcase(argv[1]);
    printf("The updated character sequence is: %s.\n", argv[1]);
    return (0);
} */