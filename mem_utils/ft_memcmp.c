/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:10:09 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 21:04:46 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memcmp - compares the first n bytes of the memory areas s1 and s2.
 *
 * @s1: The first memory area to compare.
 * @s2: The second memory area to compare.
 * @n: The number of bytes to compare.
 *
 * Return: 0 if the first n bytes of the memory areas are the same,
 * otherwise the difference between the first differing pair of bytes
 * (treated as unsigned char values).
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
