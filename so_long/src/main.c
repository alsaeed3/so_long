/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:39:44 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 12:56:19 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_map(t_game *game)
{
	while (1)
	{
		game->map_read = get_next_line(game->fd);
		if (!game->map_read)
		{
			free (game->map_read);
			break ;
		}
		game->map_height++;
		if (game->map_width != (ft_strlen(game->map_read) - 1))
		{
			if (game->map_read[game->map_width - 1] != '\n')
			{
				free(game->map_read);
				return ;
			}
			free (game->map_read);
			close (game->fd);
			write(2, "Error: The map is not rectangular or has empty lines\n" \
				, 54);
			exit (1);
		}
		free(game->map_read);
	}
}

void	map_parsing(t_game *game, char *map_file)
{
	init_game(game);
	game->fd = open(map_file, O_RDONLY);
	game->map_height = 0;
	parse_fd(game->fd);
	game->fd = open(map_file, O_RDONLY);
	game->map_read = get_next_line(game->fd);
	game->map_height++;
	game->map_width = ft_strlen(game->map_read) - 1;
	read_map(game);
	close(game->fd);
	print_2d_map(game, map_file);
}

void	open_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx_ptr, (int)game->map_width * 64, \
			(int)game->map_height * 64, "so_long");
	if (!game->mlx_win)
	{
		game->mlx_win = NULL;
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}

int	mouse_hook(t_game *game)
{
	exit_window(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_argc_and_ber(argc, argv[1]);
	game.mlx_ptr = NULL;
	game.mlx_img = NULL;
	game.mlx_win = NULL;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
	{
		write(2, "mlx pointer memory allocation has failed\n", 42);
		free (game.mlx_ptr);
		return (1);
	}
	map_parsing(&game, argv[1]);
	open_window(&game);
	set_map_images(&game, game.y, game.x);
	write(1, "Collect all burgers then go to Bill Gates\n", 43);
	mlx_key_hook(game.mlx_win, keyboard_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, mouse_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
