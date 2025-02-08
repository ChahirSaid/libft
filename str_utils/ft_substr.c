/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:59:22 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 20:00:37 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_substr - allocates a new string, which is a substring of the string s.
 *
 * @s: The string from which to create the substring.
 * @start: The start index of the substring in the string s.
 * @len: The maximum length of the substring.
 *
 * Return: The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
