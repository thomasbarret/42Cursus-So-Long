/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:14:02 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:14:53 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_hook(int key, t_ctx *ctx)
{
	if (key == 65307)
	{
		clear_game(ctx);
		clear_map(ctx->map, "Meuhhhhhhhhhhhhhhhh 🐮", 1);
	}
	player_move(key, ctx);
	return (0);
}

int	close_hook(t_ctx *ctx)
{
	clear_game(ctx);
	clear_map(ctx->map, "Meuhhhhhhhhhhhhhhhh 🐮", 1);
	return (0);
}

void	player_move(int key, t_ctx *ctx)
{
	if (key == 119)
		player_move_w(ctx);
	if (key == 115)
		player_move_s(ctx);
	if (key == 100)
		player_move_d(ctx);
	if (key == 97)
		player_move_a(ctx);
}
