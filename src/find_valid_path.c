/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 10:52:31 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	backup_map(t_game *game)
{
	game->vp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->vp_map)
		return ;
	game->y = 0;
	while(game->map_2d[game->y])
	{
		game->vp_map[game->y] = ft_strdup(game->map_2d[game->y]);
		game->y++;
	}
	game->vp_map[game->y] = NULL;
}

void	check_valid(t_game *game)
{
	free_map(game, game->vp_map);
	if (game->valid_exit >= 1 && game->map_collect == game->valid_collect)
		return ;
	else
	{
		if (game->valid_exit < 1)
			write(2, "Map Error: Exit has no valid path\n", 35);
		if (game->map_collect != game->valid_collect)
			write(2, "Map Error: Collectible has no valid path\n", 42);
		free_and_exit(game);
	}
}

void	check_ec_path(t_game *game, int y, int x)
{
	if (game->vp_map[y][x] == 'C')
		game->valid_collect++;
	if (game->vp_map[y][x] == 'E')
		game->valid_exit++;
	if (game->vp_map[y][x] != 'P' && (game->vp_map[y][x] == 'V' \
		|| game->vp_map[y][x] == 'E' || game->vp_map[y][x] == '1'))
		return ;
	game->vp_map[y][x] = 'V';
	check_ec_path(game, y, x + 1);
	check_ec_path(game, y, x - 1);
	check_ec_path(game, y - 1, x);
	check_ec_path(game, y + 1, x);
}