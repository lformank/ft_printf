char	ft_lowif(unsigned int num)
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

int	ft_lowhexdecz(unsigned int num)
{
	unsigned int	r;
	char c;

	if (num == 0)
		write (1, 0, 1);
	if (num % 16 == 0)
		return (0);
	else
	{
		r = num % 16;
		c = ft_if(r);
		ft_lowhexdecz(num / 16);
		write (1, &c, 1);
	}
	return (1);
}

int	ft_lowhexdec(unsigned int num)
{
	if (num == 0)
	{
		write (1, "0", 1);
		return (0);
	}
	ft_lowhexdecz(num);
	return (0);
}

/*int	main()
{
	unsigned int	i = 433333333;

	ft_hexdec(i);
	printf("\n%x", i);
}*/
