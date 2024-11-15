/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:34:12 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/02 12:26:57 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	player_pos(t_ctx *ctx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (ctx->map[y])
	{
		while (ctx->map[y][x])
		{
			if (ctx->map[y][x] == 'P')
			{
				ctx->player.x = x;
				ctx->player.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	fill(map, y, x - 1);
	fill(map, y, x + 1);
	fill(map, y - 1, x);
	fill(map, y + 1, x);
}

static char	**copy_map(char **map)
{
	char	**r;
	int		i;
	int		h;

	i = 0;
	h = get_height(map);
	r = (char **)malloc((sizeof(char *) * (h + 1)));
	while (i < h)
	{
		r[i] = ft_strdup(map[i]);
		i++;
	}
	r[i] = 0;
	return (r);
}

int	path_finding(t_ctx *ctx)
{
	char	**copy;
	int		y;
	int		x;

	y = 0;
	copy = copy_map(ctx->map);
	fill(copy, ctx->player.y, ctx->player.x);
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] != 'X' && copy[y][x] != '1' && copy[y][x] != '0')
			{
				ft_garbage(copy);
				return (0);
			}
			x++;
		}
		y++;
	}
	ft_garbage(copy);
	return (1);
}
