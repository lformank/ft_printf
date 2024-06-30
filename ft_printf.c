/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:34:20 by lformank          #+#    #+#             */
/*   Updated: 2024/06/30 17:50:25 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write(const char *format, size_t count)
{
	while (format[count] != '%')
	{
		write(1, &format[count], 1);
		count++;
	}
	return (count);
}

int ft_char(va_list args)
{
	char result;

	result = va_arg(args, int);
	write (1, &result, 1);
	count++;
	return (count);
}

int	ft_typevar(const char *format, int count, va_list args)
{
	if (format[count] == 'c')
		ft_char(va_arg(args, int));
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
	while (format)
	{
		count = ft_write(format, count);
		count = ft_typevar(format, count, args);
		count++;
	}
	return (count);
}

int	main(void)
{
	ft_printf("regmk%ct", "s");
	printf("%d", ft_printf("regmk%c\n", "s"));
}