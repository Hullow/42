/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:58:59 by francis           #+#    #+#             */
/*   Updated: 2025/01/14 17:11:13 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int main(void)
{
	// printf("int has a size of %zd bytes\n", sizeof(int));
	// printf("char has a size of %zd bytes\n", sizeof(char));
	// printf("char * has a size of %zd bytes\n", sizeof(char *));
	// printf("int * has a size of %zd bytes\n", sizeof(int *));
	printf("pthread_t has a size of %zd bytes\n", sizeof(pthread_t));
	printf("t_params has a size of %zd bytes\n", sizeof(t_params));
	printf("t_philo has a size of %zd bytes\n", sizeof(t_philo));
	printf("t_table has a size of %zd bytes\n", sizeof(t_table));
	return (0);
}