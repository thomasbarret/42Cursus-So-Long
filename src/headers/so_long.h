/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:07 by tbarret           #+#    #+#             */
/*   Updated: 2024/02/27 12:29:14 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../../libs/mlx/mlx.h"

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

typedef struct s_ply
{
	int		x;
	int		y;
	int		move;
	int		item;
}	t_ply;

typedef struct s_img
{
	int		width;
	int		height;
	void	*buffer;
}	t_img;

typedef struct s_imgs
{
	t_img		wall;
	t_img		floor;
	t_img		player;
	t_img		exit;
	t_img		item;
}	t_imgs;

typedef struct s_mlx
{
	void	*init;
	void	*win;
}	t_mlx;

typedef struct s_ctx
{
	t_mlx			mlx;
	char			**map;
	t_ply			player;
	t_imgs			img;
}	t_ctx;

void	check_file(char *file);
void	check_map(char **map);
void	clear_map(char **map, char *msg, int fd);
void	clear_game(t_ctx *ctx);
char	**get_file(char *file);
int		get_height(char **map);
int		get_item(char **map, char a);
void	item_check(char **map);

void	load_image(t_ctx *ctx);
void	render_map(t_ctx *ctx, char **map);
void	print_image(t_ctx *ctx, t_img img, int x, int y);
int		key_hook(int key, t_ctx *ctx);
int		close_hook(t_ctx *ctx);
void	player_move(int key, t_ctx *ctx);
void	player_move_w(t_ctx *ctx);
void	player_move_s(t_ctx *ctx);
void	player_move_d(t_ctx *ctx);
void	player_move_a(t_ctx *ctx);
int		player_event(t_ctx *ctx, char pos);
void	error(char *msg, int fd);
int		path_finding(t_ctx *ctx);
void	player_pos(t_ctx *ctx);

#endif