/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:39:44 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/01 19:23:28 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_parsing(t_game *game, char *map_file)
{
	ft_printf("map_parsing\n");
	init_game(game);
	game->fd = open(map_file, O_RDONLY);
	game->map_height = 0;
	parse_fd(game->fd);
	game->fd = open(map_file, O_RDONLY);
	game->map_read = get_next_line(game->fd);
	game->map_height++;
	game->map_width = ft_strlen(game->map_read) - 1;
	ft_printf("%d\n", (int)game->map_width);
	while (1)
	{
		game->map_read = get_next_line(game->fd);
		if (!game->map_read)
			break;
		if (game->map_width != (ft_strlen(game->map_read) - 1))
		{
			free (game->map_read);
			close (game->fd);
			write(2, "Error: The map is not rectangular\n", 35);
			exit (1);
		}
		game->map_height++;
		free(game->map_read);
	}
	ft_printf("map_parsing: game->map_height = %d\n", game->map_height);
	close(game->fd);
	print_2d_map(game, map_file);
}

void	open_window(t_game *game)
{
	ft_printf("open_window\n");
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_height * 48, \
			game->map_width * 48, "so_long");
	// if (!game->mlx_win)
	// {
	// 	free(game->mlx_ptr);
	// 	game->mlx_ptr = NULL;
	// }
}

int		mouse_hook(t_game *game)
{
	ft_printf("mouse_hook\n");
	exit_window(game);
	return (0);
}

int		main(int argc, char **argv)
{
	t_game	game;
	
	check_argc_and_ber(argc, argv[1]);
	init_mlx(&game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr)
	{
		map_parsing(&game, argv[1]);
		open_window(&game);
		draw_map(&game);
		mlx_hook(game.mlx_win, 2, 1L << 0, keyboard_hook, &game);
		mlx_hook(game.mlx_win, 17, 0, mouse_hook, &game);
		mlx_loop(game.mlx_ptr);
		return (0);
	}
	return (1);
}
