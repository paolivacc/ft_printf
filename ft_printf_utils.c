/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:10 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/30 19:34:00 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(c)));
}

size_t	ft_putstr(char *s)
{
	size_t	bytcnt;

	bytcnt = 0;
	while (*s)
	{
		if (ft_putchar(*s) == 1)
			bytcnt++;
		s++;
	}
	return (bytcnt);
}

size_t	ft_format(char c, va_list param)
{
	size_t	bytcnt;

	bytcnt = 0;
	if (c == 'c')
		bytcnt += ft_putchar(va_arg(param, char));
	else if (c == 's')
		bytcnt += ft_putstr(va_arg(param, char));
	else if (c == 'p')
		;
	else if (c == 'd')
		;
	else if (c == 'i')
		;
	else if (c == 'u')
		;
	else if (c == 'x')
		;
	else if (c == 'X')
		;
	else if (c == '%')
		bytcnt += ft_putchar('%');
	return (bytcnt);
}
