/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:14:34 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:25 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static int	ft_sizeof(unsigned int p)
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
	return (i);
}

static void	ft_puthex(unsigned int p, char type)
{
	if (p >= 16)
	{
		ft_puthex(p / 16, type);
		ft_puthex(p % 16, type);
	}
	else
	{
		if (p < 10)
			ft_printchar(p + '0');
		else
			ft_printchar(p - 10 + type);
	}
}

int	ft_printhex(unsigned int p, char type)
{
	ft_puthex(p, type);
	return (ft_sizeof(p));
}
