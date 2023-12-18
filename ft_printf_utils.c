/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:10 by svaccaro          #+#    #+#             */
/*   Updated: 2023/12/18 00:59:56 by svaccaro         ###   ########.fr       */
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

	if (!s)
		s = "(null)";
	bytcnt = 0;
	while (*s)
	{
		if (ft_putchar(*s) < 0)
			return (-1);
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
	{
		bytcnt += ft_putunbr(n / 10);
		if (bytcnt < 0)
			return (-1);
	}
	return (bytcnt + ft_putchar((n % 10) + '0'));
}

int	ft_putnbr(int n)
{
	char	c;
	int		bytcnt;

	bytcnt = 0;
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		bytcnt++;
		n = -n;
	}
	if (n >= 10)
	{
		bytcnt += ft_putnbr(n / 10);
		if (bytcnt < 0)
			return (-1);
	}
	c = (n % 10) + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (bytcnt + 1);
}

int	ft_putxnbr(unsigned long long n, char c)
{
	char		*base;
	int			bytcnt;
	static int	flag;

	bytcnt = 0;
	if (c == 'p' && n == 0)
		return (check_write_err(ft_putstr("0x0"), &bytcnt));
	else if (c == 'p' && n == ULONG_MAX)
		return (check_write_err(ft_putstr("0xffffffffffffffff"), &bytcnt));
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (c == 'p' && flag == 0)
	{
		flag = 1;
		check_write_err(ft_putstr("0x"), &bytcnt);
	}
	if (n >= 16 && bytcnt >= 0)
		check_write_err(ft_putxnbr(n / 16, c), &bytcnt);
	if (bytcnt >= 0 && (check_write_err(ft_putchar(base[n % 16]), &bytcnt) < 0))
		return (-1);
	flag = 0;
	return (bytcnt);
}
