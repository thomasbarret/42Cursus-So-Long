/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:18:25 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 12:00:57 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_image(t_ctx *ctx)
{
	ctx->img.wall.buffer
		= mlx_xpm_file_to_image(ctx->mlx.init,
			"assets/wall.xpm", &(ctx->img.wall.width), &(ctx->img.wall.height));
	ctx->img.floor.buffer
		= mlx_xpm_file_to_image(ctx->mlx.init,
			"assets/floor.xpm", &(ctx->img.floor.width),
			&(ctx->img.floor.height));
	ctx->img.player.buffer
		= mlx_xpm_file_to_image(ctx->mlx.init,
			"assets/player.xpm", &(ctx->img.player.width),
			&(ctx->img.player.height));
	ctx->img.exit.buffer
		= mlx_xpm_file_to_image(ctx->mlx.init,
			"assets/exit.xpm", &(ctx->img.exit.width), &(ctx->img.exit.height));
	ctx->img.item.buffer
		= mlx_xpm_file_to_image(ctx->mlx.init,
			"assets/item.xpm", &(ctx->img.item.width), &(ctx->img.item.height));
	if (!ctx->img.wall.buffer || !ctx->img.floor.buffer
		|| !ctx->img.player.buffer || !ctx->img.exit.buffer
		|| !ctx->img.item.buffer)
	{
		clear_game(ctx);
		clear_map(ctx->map,
			"Error\nAn error occurred while loading the images", 2);
	}
}

void	image_type(t_ctx *ctx, char t, int x, int y)
{
	if (t == '1')
		print_image(ctx, ctx->img.wall, x, y);
	if (t == '0')
		print_image(ctx, ctx->img.floor, x, y);
	if (t == 'E')
		print_image(ctx, ctx->img.exit, x, y);
	if (t == 'C')
		print_image(ctx, ctx->img.item, x, y);
	if (t == 'P')
	{
		print_image(ctx, ctx->img.player, x, y);
		ctx->player.x = x;
		ctx->player.y = y;
		ctx->player.move = 0;
		ctx->player.item = 0;
	}
}

void	render_map(t_ctx *ctx, char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			image_type(ctx, map[y][x], x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_image(t_ctx *ctx, t_img img, int x, int y)
{
	mlx_put_image_to_window(ctx->mlx.init,
		ctx->mlx.win, img.buffer, img.width * x, img.width * y);
}

void	clear_game(t_ctx *ctx)
{
	if (ctx->img.wall.buffer)
		mlx_destroy_image(ctx->mlx.init, ctx->img.wall.buffer);
	if (ctx->img.floor.buffer)
		mlx_destroy_image(ctx->mlx.init, ctx->img.floor.buffer);
	if (ctx->img.player.buffer)
		mlx_destroy_image(ctx->mlx.init, ctx->img.player.buffer);
	if (ctx->img.exit.buffer)
		mlx_destroy_image(ctx->mlx.init, ctx->img.exit.buffer);
	if (ctx->img.item.buffer)
		mlx_destroy_image(ctx->mlx.init, ctx->img.item.buffer);
	mlx_destroy_window(ctx->mlx.init, ctx->mlx.win);
	mlx_destroy_display(ctx->mlx.init);
	free(ctx->mlx.init);
}
