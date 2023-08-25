/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:58:24 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/25 10:16:21 by alsaeed          ###   ########.fr       */
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

void check_ber(int argc, char *argv)
{
	int len;

	len = 0;
	if (argc != 2)
	{
		write(2, "The given arguments are not two\n", 33);
		exit (1);
	}
	len = ft_strlen(argv);
	if (!(len > 4 && argv[len - 1] == 'r' && argv[len - 2] == 'e' && argv[len - 3] == 'b' && argv[len - 4] == '.'))
	{
		write(2, "The given map file is not a valid .ber file\n", 45);
		exit (1);
	}
}

void parse_fd(int fd)
{
	if (fd == -1)
	{
		write(2, "The given map file is inaccessible\n", 36);
		exit (1);
	}
	if (!(read(fd, NULL, 1)))
	{
		write(2, "The given map file is empty\n", 29);
		exit (1);
	}
	close(fd);
}

void init_struct(t_game *game, int i)
{
	game = malloc(sizeof(t_game) * 1);
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
	game->player_locx = 0;
	game->player_locy = 0;
	game->player_moves = 0;
	game->player_collect = 0;
	game->player_exit = 0;
	game->valid_collect = 0;
	game->valid_exit = 0;
	game->image = NULL;
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->map_read = NULL;
	game->map_2d = NULL;
	game->vp_map = NULL;
}

void	init_2d_map(t_game *game)
{
	int	i;

	i = 0;
	game->map_2d = (char **)malloc(sizeof(char *) * game->map_height + 1);
	if (!game->map_2d)
		exit (1);
	while(i < game->map_height)
	{
		game->map_2d[i] = (char *)malloc(sizeof(char) * game->map_width + 1);
		if (!game->map_2d[i])
			exit (1);
		i++;
	}
}