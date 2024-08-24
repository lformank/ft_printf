/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <lformank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:34:20 by lformank          #+#    #+#             */
/*   Updated: 2024/08/24 15:40:03 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(const char *format, int i, int *count)
{
	while (format[i] != '%' && format[i] != '\0')
		write(1, &format[i++], 1);
	if (format[i])
		i++;
	count -= 1;
	return (i);
}

int	ft_typevar(const char *format, int i, va_list args, int count)
{
	if (format[i] == 'c')
		count = ft_char(va_arg(args, int), count);
	else if (format[i] == 's')
		count = ft_str(va_arg(args, char *), count);
	else if (format[i] == 'p')
		count = ft_ptr(va_arg(args, unsigned long), count);
	else if (format[i] == 'd')
		count = ft_int(va_arg(args, int), count);
	else if (format[i] == 'i')
		count = ft_int(va_arg(args, int), count);
	else if (format[i] == 'u')
		count = ft_unsignedint(va_arg(args, unsigned int), count);
	else if (format[i] == 'x')
		count = ft_lowhexdec(va_arg(args, unsigned int), count);
	else if (format[i] == 'X')
		count = ft_uphexdec(va_arg(args, unsigned int), count);
	else if (format[i] == '%')
	{
		write (1, "%", 1);
		count++;
	}
	return (count - 2);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, format);
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		i = ft_write(format, i, &count);
		if (format[i])
			count = ft_typevar(format, i++, args, count);
	}
	return (count + i);
}

/*int	main(void)
{
	int	i = -100;
	int j = -100;
//	int	negativ = -2147483648;

	printf(" %d\n", ft_printf("uz tu %x minuty %s %p", 4, "magore!", &i));
	printf(" %d\n", printf("uz tu %x minuty %s %p", 4, "magore!", &i));
	printf(" %d\n", ft_printf("%% %cz tu %x minuty %s %%", 'u', 4, "magore!"));
	printf(" %d\n", printf("%% %cz tu %x minuty %s %%", 'u', 4, "magore!"));
	printf(" %d\n", ft_printf("%cz tu %x minuty ", 'u', -1));
	printf(" %d\n", printf("%cz tu %x minuty ", 'u', -1));
	printf(" %d\n", ft_printf("%coze", 'c'));
	printf(" %d\n", printf("%coze", 'c'));
	printf(" %d\n", ft_printf("%sze", "co"));
	printf(" %d\n", printf("%sze", "co"));
	printf(" %d\n", ft_printf("adresa je %p", &i));
	printf(" %d\n", printf("adresa je %p", &i));
	printf(" %d\n", ft_printf("%x minut", j));
	printf(" %d\n", printf("%x minut", j));
	printf(" %d\n", ft_printf("%X minut", j));
	printf(" %d\n", printf("%X minut", j));
	printf(" %d\n", ft_printf("%x procent", j));
	printf(" %d\n", printf("%x procent", j));
	printf(" %d\n", ft_printf("bejt %s", "ty magore!!"));
	printf(" %d\n", printf("bejt %s", "ty magore!!"));
	printf(" %d\n", ft_printf("%d procent", j));
	printf(" %d\n", printf("%d procent", j));
	printf(" %d\n", ft_printf("%i procent", j));
	printf(" %d\n", printf("%i procent", j));
	printf(" %d\n", ft_printf("%u procent", j));
	printf(" %d\n", printf("%u procent", j));
	printf(" %d\n", ft_printf(" %-1c%c %c ", '0', 0, '1'));
	printf(" %d\n", printf(" %c%c %c ", '0', 0, '1'));
	printf(" %d\n", ft_printf(" %c %c %c ", 0, '1', '2'));
	printf(" %d\n", printf(" %c %c %c ", 0, '1', '2'));
//	printf(" %d\n", ft_printf("%%%"));
//	printf(" %d\n", printf("%%%"));
	printf(" %d\n", ft_printf(" NULL %s NULL ", NULL));
//	printf(" %d\n", printf(" NULL %s NULL ", ""));
	printf(" %d\n", ft_printf(" %p %p ", NULL, NULL));
	printf(" %d\n", printf(" %p %p ", NULL, NULL));
}*/
