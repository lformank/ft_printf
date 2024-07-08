#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	ft_ptrif(unsigned long num)
{
	if (num % 16 >= 0 && num % 16 <= 9)
		return (num % 16 + 48);
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

int	ft_ptrhexdecz(unsigned long num, int i)
{
	unsigned int	r;
	char	c;

	if (num == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_ptrif(r);
		i = 1 + ft_ptrhexdecz(num / 16, i);
		write (1, &c, 1);
	}
	return (i);
}

int	ft_ptrhexdec(unsigned long num)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		i++;
		return (i);
	}
	write(1, "0x", 2);
	i += 3;
	i += ft_ptrhexdecz(num, i);
	return (i);
}

/*int	main()
{
	unsigned long int	i = 1000;
	
	printf("\n%d\n", ft_ptrhexdec((unsigned long)&i));
	printf("%d\n", printf("%p\n", &i));
}*/