/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
/*   Updated: 2023/08/14 10:57:26 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	val(char *va, int n, int sgn)
{
	unsigned long long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
			n++;
		if ((res > 9223372036854775807 && sgn == 1)
			|| (ft_strlen(va) - n >= 19 && sgn == 1))
			exit(0);
		else if ((res > 9223372036854775807 && sgn == -1)
			|| (ft_strlen(va) - n >= 19 && sgn == -1))
			exit(0);
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sgn;
	unsigned long long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] == '-')
			i++;
		else if (str[i] == '-')
			sgn = -1;
		i++;
	}
	res = val (str, i, sgn);
	return (res * sgn);
}

// static int	ft_isspace(int c)
// {
// 	if (c == ' ' || (c >= '\t' && c <= '\r'))
// 		return (1);
// 	return (0);
// }

// int	ft_atoi(char *str)
// {
// 	long	res;
// 	int		sign;

// 	res = 0;
// 	sign = 1;
// 	while (ft_isspace(*str))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (ft_isdigit(*str))
// 	{
// 		res = res * 10 + (*str - 48);
// 		str++;
// 		if (res < 0)
// 			return (-1);
// 		if (res > 2147483648 && sign == -1)
// 			return (-1);
// 		else if (res > 2147483647 && sign == 1)
// 			return (-1);
// 	}
// 	return (res * sign);
// }

// int	ft_atoi(char *str)
// {
// 	int				count;
// 	unsigned int	sum;

// 	count = 1;
// 	sum = 0;
// 	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			count = -count;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		sum = sum * 10 + (*str - '0');
// 		str++;
// 	}
// 	if (sum > 2147483648 && count == -1)
// 		return (0);
// 	else if (sum > 2147483647 && count == 1)
// 		return (-1);
// 	return (sum * count);
// }