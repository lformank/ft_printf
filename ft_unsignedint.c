/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:50:54 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 10:04:32 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsize(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i = i * 10;
	}
	return (i);
}

int	ft_unsignedint(unsigned int num, int count)
{
	char			nbr;
	unsigned int	size;

	size = ft_unsize(num);
	while (size > 0)
	{
		nbr = (num / size + 48);
		write(1, &nbr, 1);
		num = num % size;
		size = size / 10;
		count++;
	}
	return (count);
}
