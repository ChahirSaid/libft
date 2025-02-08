/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:01:02 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 17:09:42 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memmove - copies n bytes from memory area src to memory area dest.
 *
 * @dest: The memory area to copy to.
 * @src: The memory area to copy from.
 * @n: The number of bytes to copy.
 *
 * Return: A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!dest && !src) || n == 0 || dest == src)
		return (dest);
	i = 0;
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
