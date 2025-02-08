/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:02:55 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:27:15 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_atoi - Converts a string to an integer.
 *
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 *         Returns -1 on overflow.
 */
int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > LONG_MAX / 10
			|| (res == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10))
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
