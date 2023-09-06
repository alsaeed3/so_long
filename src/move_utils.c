/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:04 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 11:08:43 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keyboard_hook(int key_num, t_game *game)
{
	if (key_num == W)
		move_player(game, 0, -1);
	else if (key_num == S)
		move_player(game, 0, 1);
	else if (key_num == A)
		move_player(game, -1, 0);
	else if (key_num == D)
		move_player(game, 1, 0);
	else if (key_num == ESC)
		exit_window(game);
	return (0);
}

int	move_player(t_game *game, int x, int y)
{
	if (game->map_2d[game->p_locy + y][game->p_locx + x] == '1' \
	|| (game->map_2d[game->p_locy + y][game->p_locx + x] == 'E' \
	&& game->player_collect < game->map_collect))
		return (0);
	set_block_image(game, FLOOR, game->p_locx, game->p_locy);
	set_block_image(game, PLAYER, game->p_locx + x, game->p_locy + y);
	reach_collectible(game, game->p_locy + y, game->p_locx + x);
	victory(game);
	return (0);
}

void	reach_collectible(t_game *game, int y, int x)
{
	ft_printf("Steps: %d\n", ++game->player_steps);
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		set_block_image(game, FLOOR, x, y);
		set_block_image(game, PLAYER, x, y);
		game->player_collect++;
	}
	game->p_locy = y;
	game->p_locx = x;
}

void	victory(t_game *game)
{
	if (game->player_collect >= game->map_collect \
		&& game->map_2d[game->p_locy][game->p_locx] == 'E')
	{
		ft_printf("🏆Victory🥇\n");
		exit_window(game);
	}
}
