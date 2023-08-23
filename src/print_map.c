/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:20 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/23 14:54:12 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char *line_nonl(char *line)
{
	char *temp;
	
	temp = line;
	line = ft_strtrim(line, '\n');
	free (temp);
	return (line);
}

void print_map(t_game *game, char *map_file)
{
	game->i = 0;
	game->fd = open(map_file, O_RDONLY);
	game->map_2d = (char **)malloc(sizeof(char *) * game->map_height);
	if (!game->map_2d)
		exit(1);
	while(game->i < game->map_height)
	{
		game->map_2d[game->i] = (char *)malloc(sizeof(char) * game->map_width);
		if (!game->map_2d[game->i])
			exit(1);
		game->i++;
	}
	game->i = 0;
	game->map_2d[game->i++] = get_next_line(game->fd);
	while (!game->map_2d[game->i])
		game->map_2d[game->i++] = get_next_line(game->fd);
	game->map_2d[game->i] = NULL;
	close (game->fd);
	check_wall(game, game->i, game->j);
	
}

void check_wall(t_game *game, int x, int y)
{
	x = 0;
	while (game->map_2d[x])
	{
		if(x == 0 || x == game->map_height - 1)
		{
			game->j = 0;
			while (game->map_2d[x][y] && y < game->map_width)
			{
				if (game->map_2d[x][y] != '1')
				{
					free_2d_array(game->map_2d);
					write (2, "Error: Map is not bordered by walls\n", 37);
					exit (1);
				}
				y++;
			}
		}
		if (game->map_2d[x][0] != '1' || game->map_2d[x][y - 1] != '1')
		{
			free_2d_array(game->map_2d);
			write (2, "Error: Map is not bordered by walls\n", 37);
			exit (1);
		}
		x++;
	}
}
