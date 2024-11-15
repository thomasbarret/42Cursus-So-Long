/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:17:42 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/20 16:14:19 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	player_event(t_ctx *ctx, char pos)
{
	if (pos == 'E' && get_item(ctx->map, 'C') > 0)
		return (0);
	else if (pos == 'E')
	{
		clear_game(ctx);
		clear_map(ctx->map, "\033[1;32mCongratulations, you've won!\033[0m", 1);
	}
	return (1);
}
