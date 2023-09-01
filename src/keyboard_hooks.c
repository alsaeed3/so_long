/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:04 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/31 16:51:42 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	victory(t_game *game)
{
	if (game->player_coins <= 0 \
		&& game->map_2d[game->p_locy][game->p_locx] == 'E')
	{
		ft_printf("\n\n🏆nVictory🥇\n\n");
		exit_window(game);
	}
}

void	exit_mark(t_game *game, int x, int y)
{
	if (game->exit_mark == 1 && game->map_2d[y][x] != 'E')
	{
		draw_img(game, EXIT, game->e_locx, game->e_locy);
		game->exit_mark = 0;
	}
}

void	exit_window(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free_and_exit(game);
}

void	draw_img(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 48;
	x = x * size;
	y = y * size;
	game->mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, path, &size, &size);
	if (!game->mlx_img)
		exit(1);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->mlx_img, x, y);
	mlx_destroy_image(game->mlx_ptr, game->mlx_img);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = NULL;
	game->mlx_img = NULL;
	game->mlx_win = NULL;
}

void draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map_2d[y])
	{
		x = 0;
		while(game->map_2d[y][x])
		{
			pick_img(game, game->map_2d[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	pick_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		draw_img(game, WALL, x, y);
	else if (c == '0')
		draw_img(game, FLOOR, x, y);
	else if (c == 'C')
		draw_img(game, COLLECTABLE, x, y);
	else if (c == 'E')
		draw_img(game, EXIT, x, y);
	else if (c == 'P')
	{
		draw_img(game, PLAYER, x, y);
		game->p_locy = y;
		game->p_locx = x;
	}
}