/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:32:01 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 15:41:35 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_iflow(unsigned int num)
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

int	ft_lowhexdecz(unsigned int num, int count)
{
	unsigned int	r;
	char			c;

	if (num == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_iflow(r);
		count = 1 + ft_lowhexdecz(num / 16, count);
		write (1, &c, 1);
	}
	return (count);
}

int	ft_lowhexdec(unsigned int num, int count)
{
	if (num == 0)
	{
		write (1, "0", 1);
		count++;
		return (count);
	}
	count += ft_lowhexdecz(num, count);
	return (count);
}
