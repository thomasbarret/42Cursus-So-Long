/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:02:45 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 12:04:47 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	clear_map(char **map, char *msg, int fd)
{
	ft_garbage(map);
	error(msg, fd);
}

void	rectangular_map(char **map)
{
	size_t	y;
	size_t	t;

	y = 0;
	t = ft_strlen(map[0]);
	while (map[y])
	{
		if (t != ft_strlen(map[y]))
			clear_map(map, "Error\nYour map is not rectangular", 2);
		t = ft_strlen(map[y]);
		y++;
	}
}

void	closed_map(char **map)
{
	size_t	x;
	size_t	y;
	size_t	s;
	size_t	h;

	y = 0;
	x = 0;
	s = ft_strlen(map[0]);
	h = (size_t)get_height(map);
	while (map[y])
	{
		if ((map[y][0] != '1' || map[y][s - 1] != '1'))
			clear_map(map, "Error\nYour map is not closed", 2);
		while (map[y][x])
		{
			if (map[y][x] != '1' && (y == 0 || y == h - 1))
				clear_map(map, "Error\nYour map is not closed", 2);
			x++;
		}
		x = 0;
		y++;
	}
}

void	collector_map(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if ((map[y][x] != '0' && map[y][x] != '1' &&
				map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P'))
				clear_map(map,
					"Error\nYour map must contain only 1, 0, E, P, C",
					2);
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_map(char **map)
{
	rectangular_map(map);
	closed_map(map);
	collector_map(map);
	item_check(map);
}
