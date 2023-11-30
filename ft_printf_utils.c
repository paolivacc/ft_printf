/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:10 by svaccaro          #+#    #+#             */
/*   Updated: 2023/11/30 23:49:07 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(char *s)
{
	int	bytcnt;
	int	err;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	bytcnt = 0;
	while (*s)
	{
		err = ft_putchar(*s);
		if (err == -1)
			return (-1);
		else if (err == 1)
			bytcnt++;
		s++;
	}
	return (bytcnt);
}

int	ft_putunbr(unsigned int n)
{
	int	bytcnt;

	bytcnt = 0;
	if (n >= 10)
		bytcnt += ft_putunbr(n / 10);
	return (bytcnt + ft_putchar((n % 10) + '0'));
}

int	ft_putnbr(int n)
{
	char	c;
	int		bytcnt;

	bytcnt = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		bytcnt++;
		n = -n;
	}
	if (n >= 10)
		bytcnt += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	ft_putchar(c);
	return (bytcnt + 1);
}

int	ft_putxnbr(unsigned long long n, char c)
{
	char		*base;
	int			bytcnt;
	static int	flag = 0;

	bytcnt = 0;
	if (c == 'p' && n == 0)
		return (bytcnt += ft_putstr("0x0"));
	else if (c == 'p' && n == ULONG_MAX)
		return (bytcnt += ft_putstr("0xffffffffffffffff"));
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (c == 'p' && flag == 0)
	{
		flag = 1;
		bytcnt += ft_putstr("0x");
	}
	if (n >= 16)
		bytcnt += ft_putxnbr(n / 16, c);
	ft_putchar(base[n % 16]);
	flag = 0;
	return (bytcnt + 1);
}
