/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:23:42 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 15:41:07 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_ptrif(unsigned long num)
{
	if (num % 16 > 0 && num % 16 <= 9)
		return (num % 16 + 48);
	else if (num == 0)
		return ('0');
	else if (num % 16 == 10)
		return ('a');
	else if (num % 16 == 11)
		return ('b');
	else if (num % 16 == 12)
		return ('c');
	else if (num % 16 == 13)
		return ('d');
	else if (num % 16 == 14)
		return ('e');
	else if (num % 16 == 15)
		return ('f');
	return (0);
}

int	ft_ptrhexdec(unsigned long num, int count)
{
	unsigned int	r;
	char			c;

	if (num == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_ptrif(r);
		count = 1 + ft_ptrhexdec(num / 16, count);
		write (1, &c, 1);
	}
	return (count);
}

int	ft_ptr(unsigned long num, int count)
{
	if (num == 0)
	{
		write(1, "(nil)", 5);
		count += 5;
		return (count);
	}
	write(1, "0x", 2);
	count += 2;
	count += ft_ptrhexdec(num, count);
	return (count);
}
