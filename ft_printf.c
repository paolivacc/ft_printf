/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/11/06 16:28:24 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			bytcnt += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (bytcnt);
}
