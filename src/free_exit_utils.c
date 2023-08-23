/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:12 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/23 14:19:33 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free (array[i++]);
	free (array[i]);
	free (array);
}