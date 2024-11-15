/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:54:30 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:35 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static int	ft_digit(unsigned int i)
{
	int	c;

	c = 0;
	if (i == 0)
		c++;
	while (i > 0)
	{
		i /= 10;
		c++;
	}
	return (c);
}

static void	ft_putnbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_printchar(nb + 48);
	}
}

int	ft_printunbr(unsigned int nb)
{
	ft_putnbr(nb);
	return (ft_digit(nb));
}
