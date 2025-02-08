/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:26:09 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 12:03:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_islower - checks for a lowercase letter.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a lowercase letter, 0 otherwise.
 */
static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

/**
 * ft_toupper - converts a lowercase letter to an uppercase letter.
 *
 * @c: The character to convert.
 *
 * Return: If the character is a lowercase letter, the function returns the
 * corresponding uppercase letter. Otherwise,
	the character is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
