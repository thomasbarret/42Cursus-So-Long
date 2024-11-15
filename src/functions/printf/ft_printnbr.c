/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:11:06 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:28 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static int	ft_digit(long int i)
{
	int	c;

	c = 0;
	if (i <= 0)
	{
		i *= -1;
		c++;
	}
	while (i > 0)
	{
		i /= 10;
		c++;
	}
	return (c);
}

static void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
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

int	ft_printnbr(int nb)
{
	ft_putnbr((long int)nb);
	return (ft_digit((long int)nb));
}
