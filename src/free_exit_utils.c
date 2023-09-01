/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:12 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/01 18:22:04 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>
void	free_2d_array(t_game *game, char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	printf("i---> %d\n", (int)game->map_height);	
	while (i < game->map_height)
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

void	free_and_exit(t_game *game)
{
	if (game->map_2d)
		free_2d_array(game, game->map_2d);
	if (game->vp_map)
		free_2d_array(game, game->vp_map);
	exit (1);
}

char	*ft_strdup_nonl(char *s1)
{
	char	*dup;
	int		count;

	count = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (*s1 && *s1 != '\n')
	{
		*dup++ = *s1++;
		count++;
	}
	*dup = '\0';
	dup = dup - count;
	s1 = s1 - count;
	return (dup);
}
