/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:18:17 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:58:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strchr
	- locates the first occurrence of c in the string pointed to by s.
 *
 * @str: The string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the located character,
	or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}
