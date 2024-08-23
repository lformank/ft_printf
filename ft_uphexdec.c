/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphexdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:34:10 by lformank          #+#    #+#             */
/*   Updated: 2024/07/11 11:32:27 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_ifup(unsigned int num)
{
	if (num % 16 > 0 && num % 16 <= 9)
		return (num % 16 + 48);
	else if (num == 0)
		return ('0');
	else if (num % 16 == 10)
		return ('A');
	else if (num % 16 == 11)
		return ('B');
	else if (num % 16 == 12)
		return ('C');
	else if (num % 16 == 13)
		return ('D');
	else if (num % 16 == 14)
		return ('E');
	else if (num % 16 == 15)
		return ('F');
	return (0);
}

int	ft_uphexdecz(unsigned int number, int count)
{
	unsigned int	r;
	char			c;
	unsigned int	num;

	num = number;
	if (num == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_ifup(r);
		count = 1 + ft_uphexdecz(num / 16, count);
		write (1, &c, 1);
	}
	return (count);
}

int	ft_uphexdec(unsigned int num, int count)
{
	if (num == 0)
	{
		write (1, "0", 1);
		count++;
		return (count);
	}
	count += ft_uphexdecz(num, count);
	return (count);
}

/*int	main()
{
	ft_uphexdec(150047, 0);
	printf("\n%X", 150047);
}*/