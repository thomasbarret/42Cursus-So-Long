/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:00:27 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:13:44 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	player_move_w(t_ctx *ctx)
{	
	if (ctx->map[ctx->player.y - 1][ctx->player.x] == '1'
		|| !player_event(ctx, ctx->map[ctx->player.y - 1][ctx->player.x]))
		return ;
	print_image(ctx, ctx->img.floor, ctx->player.x, ctx->player.y);
	print_image(ctx, ctx->img.player, ctx->player.x, ctx->player.y - 1);
	ctx->player.y--;
	ctx->map[ctx->player.y][ctx->player.x] = '0';
	ctx->player.move++;
	ft_printf("Move: %d\n", ctx->player.move);
}

void	player_move_s(t_ctx *ctx)
{	
	if (ctx->map[ctx->player.y + 1][ctx->player.x] == '1'
		|| !player_event(ctx, ctx->map[ctx->player.y + 1][ctx->player.x]))
		return ;
	print_image(ctx, ctx->img.floor, ctx->player.x, ctx->player.y);
	print_image(ctx, ctx->img.player, ctx->player.x, ctx->player.y + 1);
	ctx->player.y++;
	ctx->map[ctx->player.y][ctx->player.x] = '0';
	ctx->player.move++;
	ft_printf("Move: %d\n", ctx->player.move);
}

void	player_move_d(t_ctx *ctx)
{	
	if (ctx->map[ctx->player.y][ctx->player.x + 1] == '1'
		|| !player_event(ctx, ctx->map[ctx->player.y][ctx->player.x + 1]))
		return ;
	print_image(ctx, ctx->img.floor, ctx->player.x, ctx->player.y);
	print_image(ctx, ctx->img.player, ctx->player.x + 1, ctx->player.y);
	ctx->player.x++;
	ctx->map[ctx->player.y][ctx->player.x] = '0';
	ctx->player.move++;
	ft_printf("Move: %d\n", ctx->player.move);
}

void	player_move_a(t_ctx *ctx)
{	
	if (ctx->map[ctx->player.y][ctx->player.x - 1] == '1'
		|| !player_event(ctx, ctx->map[ctx->player.y][ctx->player.x - 1]))
		return ;
	print_image(ctx, ctx->img.floor, ctx->player.x, ctx->player.y);
	print_image(ctx, ctx->img.player, ctx->player.x - 1, ctx->player.y);
	ctx->player.x--;
	ctx->map[ctx->player.y][ctx->player.x] = '0';
	ctx->player.move++;
	ft_printf("Move: %d\n", ctx->player.move);
}
