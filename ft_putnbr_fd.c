/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:16:08 by lformank          #+#    #+#             */
/*   Updated: 2024/06/16 15:38:57 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr;
	unsigned int	size;
	unsigned int	positiv;

	positiv = ft_negativ(n, fd);
	size = ft_size(positiv);
	while (size > 0)
	{
		nbr = (positiv / size + 48);
		write(fd, &nbr, 1);
		positiv = positiv % size;
		size = size / 10;
	}
}

/*int	main(void)
{
	ft_putnbr_fd(-15060, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(15060, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, -1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(5, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-5, 1);
}*/
