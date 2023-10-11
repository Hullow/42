/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:55:51 by francis           #+#    #+#             */
/*   Updated: 2023/10/11 09:58:46 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	*ft_memset(void *b, int c, size_t len)
{
	while (size_t > 0)
	{
		*b = c;
		b++;
		size_t--;
	}
	return (b);
}


int	main(void *b, int c, size_t len)
{
	

	
	void *result_a = memset(void *b, int c, size_t len);
	void *result_b = memset(void *b, int c, size_t len);
	void *result_c = memset(void *b, int c, size_t len);
	return (0);
}