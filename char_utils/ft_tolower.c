/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:44:21 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 12:02:52 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_isupper - checks for an uppercase letter.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is an uppercase letter, 0 otherwise.
 */
static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

/**
 * ft_tolower - converts an uppercase letter to a lowercase letter.
 *
 * @c: The character to convert.
 *
 * Return: If the character is an uppercase letter, the function returns the
 * corresponding lowercase letter. Otherwise,
	the character is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
