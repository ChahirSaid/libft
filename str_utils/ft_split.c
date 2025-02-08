/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:03:57 by schahir           #+#    #+#             */
/*   Updated: 2024/10/31 17:50:56 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_wordlen - counts the number of characters in a word.
 *
 * @str: The string to count the characters of.
 * @d: The delimiter character.
 *
 * Return: The number of characters in the word.
 */
static int	ft_wordlen(const char *str, char d)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != d)
		len++;
	return (len);
}

/**
 * ft_countwords - counts the number of words in a string.
 *
 * @str: The string to count the words of.
 * @d: The delimiter character.
 *
 * Return: The number of words in the string.
 */
static int	ft_countwords(const char *str, char d)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == d)
			str++;
		if (*str)
			count++;
		while (*str && *str != d)
			str++;
	}
	return (count);
}

/**
 * ft_worddup - duplicates a word from a string.
 *
 * @str: The string to duplicate the word from.
 * @d: The delimiter character.
 *
 * Return: The duplicated word.
 */
static char	*ft_worddup(const char *str, char d)
{
	int		len;
	char	*copy;

	if (!str)
		return (NULL);
	len = ft_wordlen(str, d);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, str, len + 1);
	return (copy);
}

/**
 * ft_free_split - frees a split string array.
 *
 * @strs: The string array to free.
 * @count: The number of strings in the array.
 *
 * Return: NULL.
 */
static char	**ft_free_split(char **strs, int count)
{
	while (count--)
		free(strs[count]);
	free(strs);
	return (NULL);
}

/**
 * ft_split
	- splits a string into an array of strings using a delimiter character.
 *
 * @s: The string to split.
 * @c: The delimiter character.
 *
 * Return: The array of new strings resulting from the split.
 */
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			strs[i] = ft_worddup(s, c);
			if (!strs[i])
				return (ft_free_split(strs, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	strs[i] = NULL;
	return (strs);
}
