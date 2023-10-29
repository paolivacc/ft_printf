/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:10 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/29 22:49:56 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return(write(STDOUT_FILENO, &c, sizeof(c)));
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

size_t	ft_format(char c, char param)
{
	
}



