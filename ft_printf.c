/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/12/18 00:59:21 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list param)
{
	if (c == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(param, unsigned int)));
	else if (c == 'x')
		return (ft_putxnbr(va_arg(param, unsigned int), c));
	else if (c == 'X')
		return (ft_putxnbr((va_arg(param, unsigned int)), c));
	else if (c == 'p')
		return (ft_putxnbr((va_arg(param, unsigned long long)), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	check_write_err(int temp_bytcnt, int *bytcnt)
{
	if (temp_bytcnt < 0)
		*bytcnt = temp_bytcnt;
	else
		*bytcnt += temp_bytcnt;
	return (*bytcnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		bytcnt;
	int		i;

	i = 0;
	bytcnt = 0;
	va_start(ptr, s);
	while (s[i] && bytcnt >= 0)
	{
		if (s[i] == '%')
		{
			i++;
			check_write_err(ft_format(s[i], ptr), &bytcnt);
		}
		else
			check_write_err(ft_putchar(s[i]), &bytcnt);
		i++;
	}
	va_end(ptr);
	return (bytcnt);
}
