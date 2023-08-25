/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:20 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/25 10:27:16 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void print_2d_map(t_game *game, char *map_file)
{
	game->y = 0;
	game->fd = open(map_file, O_RDONLY);
	game->map_2d = (char **)malloc(sizeof(char *) * game->map_height);
	if (!game->map_2d)

	while(game->y < game->map_height)
	{
		game->map_2d[game->y] = (char *)malloc(sizeof(char) * game->map_width);
		if (!game->map_2d[game->y])
			free_and_exit(game->map_2d);
		game->y++;
	}
	game->y = 0;
	game->map_2d[game->y++] = get_next_line(game->fd);
	game->map_2d[game->y] = line_nonl(game->map_2d[game->y]);
	while (game->map_2d[game->y])
	{
		game->map_2d[game->y] = get_next_line(game->fd);
		game->map_2d[game->y] = line_nonl(game->map_2d[game->y]);
		game->y++;
	}
	game->map_2d[game->y] = NULL;
	close (game->fd);
}

int check_map_pec(t_game *game, int y, int x)
{
	y = 0;
	while (game->map_2d[y] && y < game->map_height)
	{
		x = 0;
		while (game->map_2d[y][x] && x < game->map_width)
		{
			if (game->map_2d[y][x] == 'P')
			{
				game->map_player++;
				game->player_locy = y;
				game->player_locx = x;
			}
			if (game->map_2d[y][x] == 'E')
			{
				game->map_exit++;
				game->player_locy = y;
				game->player_locx = x;
			}
			if (game->map_2d[y][x] == 'C')
				game->map_collect++;
			x++;
		}
		y++;
	}
	return (0);
}

int check_walls(t_game *game, int y, int x)
{
	y = 0;
    while (game->map_2d[y] && y < game->map_height)
    {
        if(y == 0 || y == game->map_height - 1)
        {
            x = 0;
            while (game->map_2d[y][x] && x < game->map_width)
            {
                if (game->map_2d[y][x] != '1')
                    return(1);
                x++;
            }
        }
        if (game->map_2d[y][0] != '1' || game->map_2d[y][x - 1] != '1')
            return(1);
        y++;
    }
    return (0);
}

int check_map_pec(t_game *game, int y, int x)
{
	y = 0;
	while (game->map_2d[y] && y < game->map_height)
	{
		x = 0;
		while (game->map_2d[y][x] && x < game->map_width)
		{
			if (game->map_2d[y][x] == 'P')
			{
				game->map_player++;
				game->player_locy = y;
				game->player_locx = x;
			}
			if (game->map_2d[y][x] == 'E')
			{
				game->map_exit++;
				game->player_locy = y;
				game->player_locx = x;
			}
			if (game->map_2d[y][x] == 'C')
				game->map_collect++;
			x++;
		}
		y++;
	}
	return (0);
}

void check_pec_count(t_game *game, int player_c, int exit_c, int collectible_c)
{
	if (player_c == 0)
	{
		write(2, "\n\nNo player in the map\n\n", 25);
		clean_exit(game);
	}
	if (player_c > 1)
	{
		write(2, "\n\nMore than one player in the map\n\n", 36);
		clean_exit(game);
	}
	if (exit_c == 0)
	{
		write(2, "\n\nNo exit in the map\n\n", 23);
		clean_exit(game);
	}
	if (exit_c > 1)
	{
		write(2, "\n\nMore than one exit in the map\n\n", 34);
		clean_exit(game);
	}
	if (collectible_c == 0)
	{
		write(2, "\n\nNo collectible in the map\n\n", 31);
		clean_exit(game);
	}
}

void check_map_errors(t_game *game, int y, int x)
{
	if (check_walls(game, y, x) == 1)
	{
		write (2, "\n\nInvalid map borders\n\n", 24);
		clean_exit(game);
	}
	if (check_map_characters(game, y, x) == 1)
	{
		write (2, "\n\nInvalid character in the map\n\n", 33);
		clean_exit(game);
	}
	check_pec_count(game, game->map_player, game->map_exit, game->map_collect);
}
