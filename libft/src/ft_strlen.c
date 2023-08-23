/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:23:16 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/15 09:26:49 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

size_t	ft_strlen(char *buf)
{
	size_t	count;

	count = 0;
	if (!buf)
		return (0);
	while (*buf++)
		count++;
	buf = buf - count;
	return (count);
}
