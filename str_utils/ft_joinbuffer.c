/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinbuffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:17 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 14:22:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_joinbuffer - Concatenate two strings into a newly allocated buffer.
 *
 * @str1: The first string to concatenate.
 * @str2: The second string to concatenate.
 *
 * Returns: A dynamically allocated string containing the concatenation
 *          of @str1 and @str2. If memory allocation fails, returns NULL.
 *          Frees @str1 before returning the result.
 */

char	*ft_joinbuffer(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	if (!str1)
		str1 = ft_strdup("");
	result = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	if (!result)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1[i])
		result[j++] = str1[i++];
	i = 0;
	while (str2[i])
		result[j++] = str2[i++];
	result[j] = '\0';
	free(str1);
	return (result);
}
