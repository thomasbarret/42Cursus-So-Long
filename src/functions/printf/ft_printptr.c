/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:09:21 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:30 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static int	ft_sizeof(uintptr_t p)
{
	int	i;

	i = 0;
	if (!p)
		i++;
	while (p > 0)
	{
		i++;
		p = p / 16;
	}
	return (i + 2);
}

static void	ft_puthex(uintptr_t p)
{
	if (p >= 16)
	{
		ft_puthex(p / 16);
		ft_puthex(p % 16);
	}
	else if (p < 10)
		ft_printchar(p + '0');
	else
		ft_printchar(p - 10 + 'a');
}

int	ft_printptr(uintptr_t p)
{
	if (!p)
		return (ft_printstr("(nil)"));
	ft_printstr("0x");
	ft_puthex(p);
	return (ft_sizeof(p));
}
