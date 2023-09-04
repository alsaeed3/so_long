/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:13:43 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/04 14:14:18 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		check_map_characters(t_game *game, int y, int x)
{
	ft_printf("***check_map_characters***\n");
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
	ft_printf("***locate_p_e***\n");
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
	ft_printf("***move_player***\n");
	if (game->map_2d[game->p_locy + y][game->p_locx + x] == '1')
		return (0);
	else if (game->map_2d[game->p_locy + y][game->p_locx + x] == 'E' \
	&& game->map_collect > 0)
	{
		draw_img(game, FLOOR, game->p_locx, game->p_locy);
		draw_img(game, PLAYER, game->p_locx + x, game->p_locy + y);
		moves_counter(game, game->p_locy + y, game->p_locx + x);
		game->exit_mark = 1;
	}
	else
	{
		draw_img(game, FLOOR, game->p_locx, game->p_locy);
		draw_img(game, PLAYER, game->p_locx + x, game->p_locy + y);
		moves_counter(game, game->p_locy + y, game->p_locx + x);
		exit_mark(game, game->p_locx + x, game->p_locy + y);
		victory(game);
	}
	return (0);
}

int		keyboard_hook(int key_num, t_game *game)
{
	ft_printf("***keyboard_hook***\n");
	if (key_num == 119)
		move_player(game, 0, -1);
	else if (key_num == 115)
		move_player(game, 0, 1);
	else if (key_num == 100)
		move_player(game, 1, 0);
	else if (key_num == 97)
		move_player(game, -1, 0);
	else if (key_num == 65307)
		exit_window(game);
	return (0);
}

void	moves_counter(t_game *game, int y, int x)
{
	ft_printf("***moves_counter***\n");
	ft_printf("Moves: %d\n", ++game->player_moves);
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->map_collect--;
	}
	game->p_locy = y;
	game->p_locx = x;
}
