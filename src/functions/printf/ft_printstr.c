/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:03:35 by tbarret           #+#    #+#             */
/*   Updated: 2024/01/26 02:10:32 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_printchar(str[i]);
	return (i);
}

int	ft_printstr(char *str)
{
	if (!str)
		return (ft_printstr("(null)"));
	return (ft_putstr(str));
}
