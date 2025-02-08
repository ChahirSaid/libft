/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:27:53 by schahir           #+#    #+#             */
/*   Updated: 2024/10/29 11:31:49 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strnstr
	- locates the first occurrence of the null-terminated string target
 *				in the string str,
					where not more than len characters are searched.
 *
 * @str: The string to search.
 * @target: The string to search for.
 * @len: The number of characters to search.
 *
 * Return: A pointer to the located string, or NULL if the string is not found.
 */
char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t	target_len;

	target_len = ft_strlen(target);
	if (!str && len == 0)
		return (NULL);
	if (target_len == 0)
		return ((char *)str);
	while (*str && len >= target_len)
	{
		if (ft_strncmp(str, target, target_len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
