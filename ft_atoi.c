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

#include "libft.h"

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
	int		digit_count;

	i = 0;
	sign = 1;
	res = 0;
	digit_count = 0;

	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		digit_count++;
		if (digit_count > 19)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return ((int)(res * sign));
}
