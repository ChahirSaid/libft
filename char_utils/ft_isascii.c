/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:26:29 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:28:53 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_isascii - checks for an ASCII character, which is any character
 *				between 0 and octal 0177 inclusive.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
