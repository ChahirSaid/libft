/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:27:53 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 13:26:25 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == 0)
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && (i + j) < n)
		{
			j++;
			if (to_find[j] == 0)
				return ((char *)(str + i));
		}
		i++;
	}
	return (0);
}
