/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/01 23:18:04 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	backup_map(t_game *game)
{
	ft_printf("***backup_map***\n");
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

void	validate_path(t_game *game, int y, int x)
{
	ft_printf("***validate_path***\n");
	if (game->vp_map[y][x] == 'E')
		game->valid_exit++;
	if (game->vp_map[y][x] == 'V' || game->vp_map[y][x] == 'E' \
		|| game->vp_map[y][x] == '1')
		return ;
	if (game->vp_map[y][x] == 'C')
		game->valid_collect++;
	game->vp_map[y][x] = 'V';
	validate_path(game, y, x + 1);
	validate_path(game, y, x - 1);
	validate_path(game, y + 1, x);
	validate_path(game, y - 1, x);
}
