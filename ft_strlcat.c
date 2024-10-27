/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:43:57 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:59:27 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	i = 0;
	while (src[i] && (i + dlen) < (size - 1))
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = 0;
	return (dlen + slen);
}
