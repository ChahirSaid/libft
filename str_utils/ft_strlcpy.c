/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:25:13 by schahir           #+#    #+#             */
/*   Updated: 2024/10/28 20:31:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strlcpy - copies up to size
	- 1 characters from the NUL-terminated string src to dst,
 *				NUL-terminating the result.
 *
 * @dst: The destination string.
 * @src: The source string.
 * @size: The size of the destination buffer.
 *
 * Return: The total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
