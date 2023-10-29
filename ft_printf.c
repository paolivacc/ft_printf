/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:45:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/29 22:49:26 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pritf.h"

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	size_t	bytcnt;
	size_t	i;

	i = 0;
	bytcnt = 0;
	va_start(ptr, s);
	while (ptr[i])
	{
		if (ptr[i] == %)
		{
			i++;
			bytcnt += ft_format(ptr[i], va_arg(ptr, char));
		}
		else
			bytcnt += ft_putchar(ptr[i]);
	}
	return(bytcnt);
}
