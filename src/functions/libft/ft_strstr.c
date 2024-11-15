/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:27:50 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:14:04 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

char	*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (h == n || !n[0])
		return ((char *)h);
	while (h[i])
	{
		x = 0;
		while (h[i + x] && h[i + x] == n[x])
		{
			if (!n[x + 1])
				return ((char *)&h[i]);
			++x;
		}
		++i;
	}
	return (0);
}
