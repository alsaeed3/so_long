/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:12 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/06 10:45:04 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_game *game, char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < (game->map_height))
	{
		if (!array[i])
			return ;
		free (array[i]);
		array[i] = NULL;
		i++;
	}
	if (array)
	{
		free (array);
		array = NULL;
	}
}

void	free_and_exit(t_game *game)
{
	if (game->map_2d)
		free_map(game, game->map_2d);
	exit (1);
}
