/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:44:06 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 17:28:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strncmp - compares at most the first n bytes of s1 and s2.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of bytes to compare.
 *
 * Return: 0 if the first n bytes of s1 and s2 are identical.
 * Otherwise the difference between the first differing pair of bytes.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
