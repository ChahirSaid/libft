/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:33:47 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 14:13:02 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_striteri - applies the function f to each character of the string passed
 *				as argument, and passing its index as first argument.
 *
 * @s: The string to iterate.
 * @f: The function to apply to each character.
 *
 * Return: None.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, (s + i));
			i++;
		}
	}
}
