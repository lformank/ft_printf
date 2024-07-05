/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:34:20 by lformank          #+#    #+#             */
/*   Updated: 2024/07/05 17:27:34 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_write(const char *format, int count)
{
	while (format[count] != '%' && format[count] != '\0')
	{
		write(1, &format[count], 1);
		count++;
	}
	if (format[count])
		count++;
	return (count);
}

void	ft_char(char args)
{
	write (1, &args, 1);
}

int	ft_typevar(const char *format, int count, va_list args)
{
	if (format[count] == 'c')
		ft_char(*va_arg(args, char *));
	else if (format[count] == 'p')
		ft_ptr(va_arg(args, long unsigned int));
	else if (format[count] == 'x')
		ft_lowhexdec(va_arg(args, unsigned int));
	else if (format[count] == 'X')
		ft_uphexdec(va_arg(args, unsigned int));
	else if (format[count] == '%')
		write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start (args, format);
	if (!format)
		return (0);
	while (format[count] != '\0')
	{
		count = ft_write(format, count);
		if (format[count])
		{
			count = ft_typevar(format, count, args);
			count++;
		}
	}
	return (count);
}

int	main(void)
{
	ft_printf("ko%cka", "c");
	ft_printf("address %p unknown", "p");
	printf("address %p unknown", "p");
}