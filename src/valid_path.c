/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/23 16:34:15 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void backup_map(t_game *game)
{
	game->vp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	game->i = 0;
	while(game->map_2d[game->i])
	{
		game->vp_map[game->i] = ft_strdup(game->map_2d[game->i]);
		game->i++;
	}
	game->vp_map[game->i] = NULL;
}

void validate_path(t_game *game, int x, int y)
{
	if (game->vp_map[x][y] == 'E')
		game->valid_exit++;
	if (game->vp_map[x][y] == '1' || game->vp_map[x][y] == 'V' \
	|| game->vp_map[x][y] == 'E')
		return ;
	if (game->vp_map[x][y] == 'C')
		game->valid_collect++;
	game->vp_map[x][y] = 'V';
	validate_path(game, x, y + 1);
	validate_path(game, x, y - 1);
	validate_path(game, x + 1, y);
	validate_path(game, x - 1, y);
}