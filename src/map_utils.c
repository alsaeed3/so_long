/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:58:24 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 10:52:45 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_argc_and_ber(int argc, char *argv)
{
	int	len;

	len = 0;
	if (argc != 2)
	{
		write(2, "The given arguments are not two\n", 33);
		exit (1);
	}
	len = ft_strlen(argv);
	if (!(len > 4 && argv[len - 1] == 'r' && argv[len - 2] == 'e' \
		&& argv[len - 3] == 'b' && argv[len - 4] == '.'))
	{
		write(2, "The given map file is not a valid .ber file\n", 45);
		exit (1);
	}
}

void	parse_fd(int fd)
{
	char	*buf;

	buf = NULL;
	if (fd == -1)
	{
		write(2, "The given map file is inaccessible\n", 36);
		exit (1);
	}
	if (!(read(fd, buf, 1)))
	{
		write(2, "The given map file is empty\n", 29);
		exit (1);
	}
	if (close(fd) == -1)
	{
		write(2, "The given map file has a close failure\n", 36);
		exit (1);
	}
}

int	check_map_characters(t_game *game, int y, int x)
{
	x = 0;
	while (game->map_2d[y][x])
	{
		if (game->map_2d[y][x] == 'P')
		{
			game->map_player++;
			game->p_locy = y;
			game->p_locx = x;
		}
		else if (game->map_2d[y][x] == 'C')
			game->map_collect++;
		else if (game->map_2d[y][x] == 'E')
			game->map_exit++;
		else if (game->map_2d[y][x] != '0' && game->map_2d[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

void	init_game(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->fd = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->map_collect = 0;
	game->map_exit = 0;
	game->map_player = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->player_exist = 0;
	game->player_steps = 0;
	game->player_collect = 0;
	game->p_locx = 0;
	game->p_locy = 0;
	game->e_locx = 0;
	game->e_locy = 0;
	game->valid_collect = 0;
	game->valid_exit = 0;
	game->map_read = NULL;
	game->map_2d = NULL;
	game->vp_map = NULL;
}

void	malloc_map_2d(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	game->map_2d = ft_calloc((game->map_height + 1), sizeof(char *));
	if (!game->map_2d)
		exit (1);
	while (i < game->map_height)
	{
		j = 0;
		game->map_2d[i] = NULL;
		game->map_2d[i] = ft_calloc((game->map_width + 1), sizeof(char));
		while (j < game->map_width)
		{
			game->map_2d[i][j] = '\0';
			j++;
		}
		if (!game->map_2d[i])
			exit (1);
		i++;
	}
}
