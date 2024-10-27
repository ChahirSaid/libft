/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:03:57 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 13:49:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdelimiter(char c, char d)
{
	return (c == d);
}

static int	ft_wordlen(const char *str, char d)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_isdelimiter(str[i], d))
		i++;
	return (i);
}

static int	ft_countwords(const char *str, char d)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_isdelimiter(str[i], d))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_isdelimiter(str[i], d))
			i++;
	}
	return (count);
}

static char	*ft_worddup(const char *str, char d)
{
	size_t	i;
	size_t	len;
	char	*copy;

	i = 0;
	len = ft_wordlen(str, d);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && ft_isdelimiter(*s, c))
			s++;
		if (*s)
		{
			strs[i] = ft_worddup(s, c);
			i++;
		}
		while (*s && !ft_isdelimiter(*s, c))
			s++;
	}
	strs[i] = 0;
	return (strs);
}
