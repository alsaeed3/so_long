/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:20 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 13:03:11 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_2d_map(t_game *game, char *map_file)
{
	game->fd = open(map_file, O_RDONLY);
	malloc_map_2d(game);
	game->y = 0;
	while (1)
	{
		game->map_read = get_next_line(game->fd);
		if (!game->map_read)
			break ;
		game->map_2d[game->y] = ft_strdup_nonl(game->map_read);
		free(game->map_read);
		game->y++;
	}
	game->map_2d[game->y] = NULL;
	close (game->fd);
	game->y = 0;
	while (game->map_2d[game->y])
	{
		check_map_errors(game, game->y, game->x);
		game->y++;
	}
	check_pec_count(game);
	backup_map(game);
	check_ec_path(game, game->p_locy, game->p_locx);
	check_valid(game);
}

int	check_walls(t_game *game, size_t y, size_t x)
{
	if (y == 0 || y == game->map_height - 1)
	{
		x = 0;
		while (x < (game->map_width - 1))
		{
			if (game->map_2d[y][x] != '1')
				return (1);
			x++;
		}
	}
	if (game->map_2d[y][0] != '1' \
		|| game->map_2d[y][game->map_width - 1] != '1')
		return (1);
	return (0);
}

void	check_pec_count(t_game *game)
{
	if (game->map_player == 0)
	{
		write(2, "Map Error: No player in the map!!\n", 35);
		free_and_exit(game);
	}
	else if (game->map_player > 1)
	{
		write(2, "Map Error: More than one player in the map!!\n", 46);
		free_and_exit(game);
	}
	else if (game->map_exit == 0)
	{
		write(2, "Map Error: No exit in the map!!\n", 33);
		free_and_exit(game);
	}
	else if (game->map_exit > 1)
	{
		write(2, "Map Error: More than one exit in the map!!\n", 44);
		free_and_exit(game);
	}
	else if (game->map_collect == 0)
	{
		write(2, "Map Error: No collectible in the map!!\n", 40);
		free_and_exit(game);
	}
}

void	check_map_errors(t_game *game, int y, int x)
{
	if (check_walls(game, y, x) == 1)
	{
		write (2, "Map Error: Invalid map borders or it has empty lines!!\n" \
				, 56);
		free_and_exit(game);
	}
	if (check_map_characters(game, y, x) == 1)
	{
		write (2, "Map Error: Invalid character in the map!!\n", 43);
		free_and_exit(game);
	}
}
