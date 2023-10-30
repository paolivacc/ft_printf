/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/30 19:32:31 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	size_t	bytcnt;
	size_t	i;

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
	return (bytcnt);
}
