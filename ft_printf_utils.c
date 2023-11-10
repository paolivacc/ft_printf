/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:10 by svaccaro          #+#    #+#             */
/*   Updated: 2023/11/09 20:36:50 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(c)));
}

int	ft_putstr(char *s)
{
	int	bytcnt;

	bytcnt = 0;
	while (*s)
	{
		if (ft_putchar(*s) == -1)
			return (-1);
		else if (ft_putchar(*s) == 1)
			bytcnt++;
		s++;
	}
	return (bytcnt);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;

	nlen = ft_intlen(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	*(str + nlen) = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--nlen] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

/*char	*ft_xtoa(int n)
{
	char	*str;
	int		nlen;

	nlen = ft_intlen(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	*(str + nlen) = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--nlen] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
*/

int	ft_format(char c, va_list param)
{
	int	bytcnt;

	bytcnt = 0;
	if (c == 'c')
		bytcnt += ft_putchar(va_arg(param, int));
	else if (c == 's')
		bytcnt += ft_putstr(va_arg(param, char *));
	//else if (c == 'p')
	//	bytcnt += ft_putstr((unsigned long)va_arg(param, void *));
	else if (c == 'd' || c == 'i')
		bytcnt += ft_putstr(ft_itoa(va_arg(param, int)));
	else if (c == 'u')
		bytcnt += ft_putstr(ft_itoa(va_arg(param, unsigned int)i));
	//else if (c == 'x')
	//	bytcnt += ft_putstr(ft_itoa(va_arg(param, unsigned int));
	//else if (c == 'X')
	//	bytcnt += ft_putstr(ft_itoa(va_arg(param, unsigned int));
	else if (c == '%')
		bytcnt += ft_putchar('%');
	return (bytcnt);
}
