/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:17:19 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:59:05 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strlen - counts the number of characters in a null-terminated string.
 *
 * @str: The string to count the characters of.
 *
 * Return: The number of characters in the string.
 */
static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * ft_strdup - duplicates a string.
 *
 * @src: The string to duplicate.
 *
 * Return: A pointer to the duplicated string
 *		or NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
