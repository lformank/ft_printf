/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:16:08 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 15:41:21 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_sizee(unsigned int n)
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

unsigned int	ft_negative(int n, int fd)
{
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr;
	unsigned int	size;
	unsigned int	positiv;

	positiv = ft_negative(n, fd);
	size = ft_sizee(positiv);
	while (size > 0)
	{
		nbr = (positiv / size + 48);
		write(fd, &nbr, 1);
		positiv = positiv % size;
		size = size / 10;
	}
}
