/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:05:20 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/04 13:58:41 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>

void	print_2d_map(t_game *game, char *map_file)
{
	ft_printf("***print_2d_map***\n");
	game->fd = open(map_file, O_RDONLY);
	malloc_map_2d(game);
	game->y = 0;
	while (1)
	{
		game->map_read = get_next_line(game->fd);
		if (!game->map_read)
			break;
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
}

int		check_walls(t_game *game, size_t y, size_t x)
{
	ft_printf("***check_walls***\n");
    if (y == 0 || y == game->map_height - 1)
    {
        x = 0;
        while (x < (game->map_width - 1))
        {
            if (game->map_2d[y][x] != '1')
                return(1);
            x++;
        }
    }
    if (game->map_2d[y][0] != '1' || game->map_2d[y][game->map_width - 1] != '1')
    	return(1);
    return (0);
}

void	check_pec_count(t_game *game)
{
	ft_printf("***check_pec_count***\n");
	if (game->map_player == 0)
	{
		write(2, "\n\nNo player in the map\n\n", 25);
		free_and_exit(game);
	}
	else if (game->map_player > 1)
	{
		write(2, "\n\nMore than one player in the map\n\n", 36);
		free_and_exit(game);
	}
	else if (game->map_exit == 0)
	{
		write(2, "\n\nNo exit in the map\n\n", 23);
		free_and_exit(game);
	}
	else if (game->map_exit > 1)
	{
		write(2, "\n\nMore than one exit in the map\n\n", 34);
		free_and_exit(game);
	}
	else if (game->map_collect == 0)
	{
		write(2, "\n\nNo collectible in the map\n\n", 30);
		free_and_exit(game);
	}
}

void	check_map_errors(t_game *game, int y, int x)
{
	ft_printf("***check_map_errors***\n");	
	if (check_walls(game, y, x) == 1)
	{
		write (2, "\n\nInvalid map borders\n\n", 24);
		free_and_exit(game);
	}
	if (check_map_characters(game, y, x) == 1)
	{
		write (2, "\n\nInvalid character in the map\n\n", 33);
		free_and_exit(game);
	}
}
