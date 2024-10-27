/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:59:01 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 14:23:29 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

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
