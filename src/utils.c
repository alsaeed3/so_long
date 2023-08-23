/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:58:24 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/23 15:09:28 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void init_struct(t_game *game)
{
	game = malloc(sizeof(t_game) * 1);
	game->i = 0;
	game->j = 0;
	game->x = 0;
	game->y = 0;
	game->player_moves = 0;
	game->
}