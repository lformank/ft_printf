/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:16:08 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 15:41:42 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_size(unsigned int n)
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

unsigned int	ft_negativ(int n, int fd)
{
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	return (n);
}

int	ft_int(int num, int count)
{
	char			nbr;
	unsigned int	size;
	unsigned int	positiv;

	if (num < 0)
		count++;
	positiv = ft_negativ(num, 1);
	size = ft_size(positiv);
	while (size > 0)
	{
		nbr = (positiv / size + 48);
		write(1, &nbr, 1);
		positiv = positiv % size;
		size = size / 10;
		count++;
	}
	return (count);
}
