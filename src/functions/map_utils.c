/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:31:52 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:07:41 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_item(char **map, char a)
{
	size_t	x;
	size_t	y;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == a)
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (i);
}

void	item_check(char **map)
{
	if (!(get_item(map, 'E') == 1
			&& get_item(map, 'P') == 1 && get_item(map, 'C') >= 1))
		clear_map(map,
			"Error\nYour map doesn't have the required number of items.", 2);
}
