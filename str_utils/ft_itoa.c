/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:59:01 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 16:13:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_intlen - counts the number of digits in an integer.
 *
 * @n: The integer to count the digits of.
 *
 * Return: The number of digits in the integer.
 */
static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n == 0)
			return (1);
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * fill_str - fills a string with the digits of an integer.
 *
 * @str: The string to fill.
 * @n: The integer to convert to a string.
 * @len: The length of the integer.
 */
static void	fill_str(char *str, long n, size_t len)
{
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return ;
	}
	while (n > 0)
	{
		str[--len] = 48 + (n % 10);
		n /= 10;
	}
}

/**
 * ft_itoa - converts an integer to a string.
 *
 * @nb: The integer to convert.
 *
 * Return: The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int nb)
{
	long	n;
	size_t	len;
	char	*str;

	n = nb;
	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		fill_str(str + 1, n, len - 1);
	}
	else
		fill_str(str, n, len);
	return (str);
}
