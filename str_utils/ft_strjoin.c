/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:17 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 14:22:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strjoin - concatenates two strings.
 *
 * @s1: The prefix string.
 * @s2: The suffix string.
 *
 * Return: The new string or NULL if the allocation fails.
 */
static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * ft_strcat - concatenates two strings.
 *
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: The destination string.
 */
static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * ft_strlen - counts the number of characters in a null-terminated string.
 *
 * @str: The string to count the characters of.
 *
 * Return: The number of characters in the string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[ft_strlen(str)] = 0;
	return (str);
}
