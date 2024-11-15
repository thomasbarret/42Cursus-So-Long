/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:38:42 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:16:15 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*b;
	size_t	m;

	m = nmemb * size;
	if ((int)m < 0 || ((int)size < 0 && (int)nmemb < 0))
		return (0);
	b = malloc(m);
	if (!b)
		return (0);
	ft_bzero(b, m);
	return (b);
}
