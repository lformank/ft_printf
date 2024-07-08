#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_write(const char *format, int i)
{
	while (format[i] != '%' && format[i] != '\0')
	{
		write(1, &format[i], 1);
		i++;
	}
	if (format[i])
		i++;
	return (i);
}

int ft_char(char ch, int count)
{
	write (1, &ch, 1);
	count++;
	return (count);
}

int ft_str(char *str, int count)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write (1, &str[i], 1);
		i++;
		count++;
    }
	return (count);
}

char	ft_iflow(unsigned int num)
{
	if (num % 16 > 0 && num % 16 <= 9)
		return (num % 16 + 48);
	else if (num % 16 == 10)
		return('a');
	else if (num % 16 == 11)
		return('b');
	else if (num % 16 == 12)
		return('c');
	else if (num % 16 == 13)
		return('d');
	else if (num % 16 == 14)
		return('e');
	else if (num % 16 == 15)
		return('f');
	return (0);
}

int	ft_hexdeczlow(unsigned int num, int count)
{
	unsigned int	r;
	char c;

	if (num % 16 == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_iflow(r);
		ft_hexdeczlow(num / 16, count);
		write (1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_hexdeclow(unsigned int num, int count)
{
	if (num == 0)
	{
		write (1, "0", 1);
		count++;
		return (count);
	}
	ft_hexdeczlow(num, count);
	return (count);
}

char	ft_ifup(unsigned int num)
{
	if (num % 16 > 0 && num % 16 <= 9)
		return (num % 16 + 48);
	else if (num % 16 == 10)
		return('A');
	else if (num % 16 == 11)
		return('B');
	else if (num % 16 == 12)
		return('C');
	else if (num % 16 == 13)
		return('D');
	else if (num % 16 == 14)
		return('E');
	else if (num % 16 == 15)
		return('F');
	return (0);
}

int	ft_hexdeczup(unsigned int number, int count)
{
	unsigned int	r;
	char c;
	unsigned int num;

	num = number;
	if (num % 16 == 0)
		return (count);
	else
	{
		r = num % 16;
		c = ft_ifup(r);
		ft_hexdeczup(num / 16, count);
		write (1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_hexdecup(unsigned int num, int count)
{
	if (num == 0)
	{
		write (1, "0", 1);
		count++;
		return (count);
	}
	ft_hexdeczup(num, count);
	return (count);
}

int ft_ptr(unsigned long pointer, int count)
{
	write(1, "0", 1);
	write(1, "x", 1);
	count = count + 2 + ft_hexdecptr(pointer, count);
	return (count);
}

int	ft_typevar(const char *format, int i, va_list args, int count)
{
    if (format[i] == 'c')
		count = ft_char(va_arg(args, int), count);
    else if (format[i] == 's')
		count = ft_str(va_arg(args, char *), count);
	else if (format[i] == 'p')
		count = ft_ptr(va_arg(args, unsigned long int), count);
/*	else if (format[i] == 'd')
	else if (format[i] == 'i')
	else if (format[i] == 'u')*/
	else if (format[i] == 'x')
		count = ft_hexdeclow(va_arg(args, unsigned int), count);
	else if (format[i] == 'X')
		count = ft_hexdecup(va_arg(args, unsigned int), count);
	else if (format[i] == '%')
	{
		write (1, "%", 1);
		count++;
	}
	i++;
	count++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, format);
	if (!format)
		return (0);
	while (format[i] != '\0')
	{
		i = ft_write(format, i);
		if (format[i])
        {
		    ft_typevar(format, i, args, count);
			i++;
			count++;
		}
	}
	count = count + i;
	return (count);
}

int	main(void)
{
	ft_printf("%cz si tu mel byt %x minuty %s %%\n", 'u', 1000,"ty magore!!");
	printf("%d\n", ft_printf("%cz si tu mel byt %x minuty %s %%", 'u', 1000, "ty magore!!"));
	printf("%d\n", printf("%cz si tu mel byt %x minuty %s %%", 'u', 1000, "ty magore!!"));
	ft_printf("%p\n", "bla");
	printf("%p\n", "bla");
}