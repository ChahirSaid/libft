/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:06:13 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:56:58 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_memset
	- writes len bytes of value c to the string b.
 *
 * @s: The string to write to.
 * @c: The character to write.
 * @n: The number of bytes to write.
 *
 * Return: A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = c;
	return (s);
}
