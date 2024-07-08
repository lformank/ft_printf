char	ft_upif(unsigned int num)
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

int	ft_uphexdecz(unsigned int num)
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
		ft_uphexdecz(num / 16);
		write (1, &c, 1);
	}
	return (1);
}

int	ft_uphexdec(unsigned int num)
{
	if (num == 0)
	{
		write (1, "0", 1);
		return (0);
	}
	ft_uphexdecz(num);
	return (0);
}

/*int	main()
{
	unsigned int	i = 433333333;

	ft_hexdec(i);
	printf("\n%x", i);
}*/
