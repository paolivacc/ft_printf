/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:53:57 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/30 13:49:52 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_format(char c, char param);

#endif /* FT_PRINTF_H */
