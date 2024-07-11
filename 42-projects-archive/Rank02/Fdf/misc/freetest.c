/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:30:22 by francis           #+#    #+#             */
/*   Updated: 2024/05/07 12:07:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *ptr = malloc (sizeof(char *));
	printf("ptr address: %p\n", ptr);
	ft_free((void **)&ptr);
	printf("ptr address: %p\n", ptr);
}