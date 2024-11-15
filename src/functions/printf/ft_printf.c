/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:15 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:20 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static int	ft_check(va_list *args, char t)
{
	int	i;

	i = 0;
	if (t == 'c')
		i += ft_printchar(va_arg(*args, int));
	else if (t == 's')
		i += ft_printstr(va_arg(*args, char *));
	else if (t == 'p')
		i += ft_printptr(va_arg(*args, unsigned long long));
	else if (t == 'd' || t == 'i')
		i += ft_printnbr(va_arg(*args, int));
	else if (t == 'u')
		i += ft_printunbr(va_arg(*args, unsigned int));
	else if (t == 'x')
		i += ft_printhex(va_arg(*args, unsigned int), 'a');
	else if (t == 'X')
		i += ft_printhex(va_arg(*args, unsigned int), 'A');
	else if (t == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		i;

	c = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			c += ft_printchar(str[i]);
			i++;
			continue ;
		}
		c += ft_check(&args, str[i + 1]);
		str += 2;
	}
	va_end(args);
	return (c);
}
