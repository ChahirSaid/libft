/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:01:35 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:27:36 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_bzero - writes n zeroed bytes to the string s.
 *
 * @s: The string to write to.
 * @n: The number of zeroed bytes to write.
 *
 * Return: None.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}
