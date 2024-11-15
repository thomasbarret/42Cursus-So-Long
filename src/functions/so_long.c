/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:51:14 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/01 11:52:25 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error(char *msg, int fd)
{
	int		i;

	i = 0;
	while (msg[i])
	{
		write(fd, &msg[i], 1);
		i++;
	}
	exit(1);
}

static	void	init(t_ctx *ctx)
{
	ctx->mlx.init = mlx_init();
	if (!ctx->mlx.init)
		clear_map(ctx->map,
			"Error\nAn error occurred when init mlx", 2);
	ctx->mlx.win = mlx_new_window(ctx->mlx.init, ft_strlen(ctx->map[0]) * 32,
			get_height(ctx->map) * 32, "so_long");
	if (!ctx->mlx.win)
	{
		free(ctx->mlx.init);
		clear_map(ctx->map,
			"Error\nAn error occurred when creating the window", 2);
	}
	load_image(ctx);
	render_map(ctx, ctx->map);
	mlx_key_hook(ctx->mlx.win, key_hook, ctx);
	mlx_hook(ctx->mlx.win, 17, 0, close_hook, ctx);
	mlx_loop(ctx->mlx.init);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc <= 1)
		error("Error\nYou have not specified a map.", 2);
	check_file(argv[1]);
	ctx.map = get_file(argv[1]);
	if (!ctx.map)
		error("Error\nThe indicated map is invalid.", 2);
	check_map(ctx.map);
	player_pos(&ctx);
	if (!path_finding(&ctx))
		clear_map(ctx.map,
			"Error\nThe map does not contain a valid path.",
			2);
	init(&ctx);
}
