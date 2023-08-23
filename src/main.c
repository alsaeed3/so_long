/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:39:44 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/23 15:01:10 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"



void	map_height_width(t_game *game, char *map_file)
{
	game->fd = open(map_file, O_RDONLY);
	game->map_height = 0;
	parse_fd(game->fd);
	game->fd = open(map_file, O_RDONLY);
	game->map_read = get_next_line(game->fd);
	game->map_height++;
	game->map_width = ft_strlen(game->map_read);
	while (1)
	{
		game->map_read = get_next_line(game->fd);
		if (!game->map_read)
			break;
		if (game->map_width != ft_strlen(game->map_read))
		{
			free (game->map_read);
			close (game->fd);
			write(2, "Error: The map is not rectangular\n", 35);
			exit (1);
		}
		game->map_height++;
		free(game->map_read);
	}
	close(game->fd);
	ft_print_map(&game, map_file);
	
}

int main(int argc, char **argv)
{
	t_game	game;

	check_ber(argc, argv[1]);
	map_height_width(&game, argv[1]);
	
	
	return(0);
}