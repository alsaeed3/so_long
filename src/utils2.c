/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:13:43 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/01 15:58:17 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		check_map_characters(t_game *game, int y, int x)
{
	x = 0;
	while (game->map_2d[y][x])
	{
		if (game->map_2d[y][x] == 'P')
			game->map_player++;
		else if (game->map_2d[y][x] == 'C')
			game->map_collect++;
		else if (game->map_2d[y][x] == 'E')
			game->map_exit++;
		else if (game->map_2d[y][x] != '0' && game->map_2d[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

void	locate_p_e(t_game *game, int y, int x, char p_e)
{
	y = 0;
	while (game->map_2d[y])
	{
		x = 0;
		while (game->map_2d[y][x])
		{
			if (game->map_2d[y][x] == p_e)
			{
				if (p_e == 'P')
				{
					game->p_locx = x;
					game->p_locy = y;
				}
				else if (p_e == 'E')
				{
					game->e_locx = x;
					game->e_locy = y;
				}
			}
			x++;
		}
		y++;
	}
}

int		move_player(t_game *game, int x, int y)
{
	if (game->map_2d[game->p_locy + y][game->p_locy + x] == '1')
		return (0);
	else if (game->map_2d[game->p_locy + y][game->p_locx + x] == 'E' \
	&& game->map_collect > 0)
	{
		draw_img(game, FLOOR, game->p_locx, game->p_locy);
		draw_img(game, PLAYER, game->p_locx + x, game->p_locy + y);
		moves_counter(game, game->p_locy, game->p_locx);
		game->exit_mark = 1;
	}
	else if (game->map_2d[game->p_locy + y][game->p_locx + x] == 'E' \
	&& game->map_collect <= 0)
	{
		draw_img(game, FLOOR, game->p_locx, game->p_locy);
		draw_img(game, PLAYER, game->p_locx + x, game->p_locy + y);
		moves_counter(game, game->p_locy, game->p_locx);
		exit_mark(game, game->p_locx + x, game->p_locy + y);
		victory(game);
	}
	return (0);
}

int		keyboard_hook(int key_num, t_game *game)
{
	if (key_num == 13)
		move_player(game, 0, -1);
	else if (key_num == 1)
		move_player(game, 0, 1);
	else if (key_num == 2)
		move_player(game, 0, 1);
	else if (key_num == 0)
		move_player(game, 0, -1);
	else if (key_num == 53)
		exit_window(game);
	return (0);
}

void	moves_counter(t_game *game, int y, int x)
{
	ft_printf("Moves: %d\n", ++game->player_moves);
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->map_collect--;
	}
	game->p_locx = x;
	game->p_locy = y;
}
