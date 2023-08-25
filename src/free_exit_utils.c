/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:12 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/25 10:57:13 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array && array[i])
	{
		free (array[i]);
		array[i] = NULL;
		i++;
	}
	if (array[i])
	{
		free (array[i]);
		array[i] = NULL;
	}
	if (array)
	{
		free (array);
		array = NULL;
	}
}

void	free_and_exit(t_game *game, int flag, int i, int j)
{
	if (game->map_2d)
		free_2d_array(game->map_2d);
	if (game->vp_map)
		free_2d_array(game->vp_map);
	if (game)
	{
		free(game);
		game = NULL;		
	}
	exit (1);
}
