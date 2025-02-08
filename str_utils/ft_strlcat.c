/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:43:57 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 16:43:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strlcat - appends the NUL-terminated string src to the end of dst.
 *
 * @dst: The destination string.
 * @src: The source string.
 * @size: The size of the destination buffer.
 *
 * Return: The total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!dst && !size)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dst);
	k = j;
	if (size <= j)
		return (ft_strlen(src) + size);
	while (src[i] && i < size - k - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (k + ft_strlen(src));
}
