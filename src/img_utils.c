/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:13:43 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 11:07:35 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map_images(t_game *game, int y, int x)
{
	y = 0;
	x = 0;
	while (game->map_2d[y])
	{
		x = 0;
		while (game->map_2d[y][x])
		{
			set_block_image(game, FLOOR, x, y);
			select_component_image(game, game->map_2d[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	select_component_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		set_block_image(game, WALL, x, y);
	else if (c == 'C')
		set_block_image(game, COLLECTABLE, x, y);
	else if (c == 'E')
		set_block_image(game, EXIT, x, y);
	else if (c == 'P')
	{
		set_block_image(game, PLAYER, x, y);
		game->p_locy = y;
		game->p_locx = x;
	}
}

void	set_block_image(t_game *game, char *path, int x, int y)
{
	int	length;

	length = 64;
	game->mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, path, &length, &length);
	if (!game->mlx_img)
	{
		write(2, "Error: Invalid image path, or image file is empty!!\n", 53);
		exit_window(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->mlx_img, \
		x * 64, y * 64);
	mlx_destroy_image(game->mlx_ptr, game->mlx_img);
}

void	exit_window(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free_and_exit(game);
}
