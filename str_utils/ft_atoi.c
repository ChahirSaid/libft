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
 * ft_isspace - checks for a white-space character.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a white-space character, 0 otherwise.
 */
static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/**
 * ft_isdigit - checks for a digit (0 through 9).
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
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
