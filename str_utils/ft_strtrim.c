/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:34:07 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 20:02:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_totrim - checks if a character is in the set.
 *
 * @c: The character to check.
 * @set: The set of characters to check against.
 *
 * Return: 1 if the character is in the set, 0 otherwise.
 */
static int	ft_totrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * ft_strtrim - allocates (with malloc(3)) and returns a copy of s1 with the
 *				characters specified in set removed from the beginning and the
 *				end of the string.
 *
 * @s1: The string to be trimmed.
 * @set: The set of characters to trim from the beginning and end of s1.
 *
 * Return: The trimmed string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_totrim(s1[start], set))
		start++;
	while (end > start && ft_totrim(s1[end], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
