/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/11/30 23:49:25 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list param)
{
	int	bytcnt;

	bytcnt = 0;
	if (c == 'c')
		bytcnt += ft_putchar(va_arg(param, int));
	else if (c == 's')
		bytcnt += ft_putstr(va_arg(param, char *));
	else if (c == 'd' || c == 'i')
		bytcnt += ft_putnbr(va_arg(param, int));
	else if (c == 'u')
		bytcnt += ft_putunbr(va_arg(param, unsigned int));
	else if (c == 'x')
		bytcnt += ft_putxnbr(va_arg(param, unsigned int), c);
	else if (c == 'X')
		bytcnt += ft_putxnbr((va_arg(param, unsigned int)), c);
	else if (c == 'p')
		bytcnt += ft_putxnbr((va_arg(param, unsigned long long)), c);
	else if (c == '%')
		bytcnt += ft_putchar('%');
	return (bytcnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		bytcnt;
	int		i;

	i = 0;
	bytcnt = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			bytcnt += ft_format(s[i], ptr);
		}
		else
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			else
				bytcnt++;
		}
		i++;
	}
	va_end(ptr);
	return (bytcnt);
}
