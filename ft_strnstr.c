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

#include "libft.h"

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
