/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:59:22 by schahir           #+#    #+#             */
/*   Updated: 2024/10/26 14:14:23 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (!s)
		return (0);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (0);
	if (start + len >= slen)
		len = slen - start;
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
