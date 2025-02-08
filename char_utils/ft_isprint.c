/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:26:24 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:29:44 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_isprint - checks for any printable character including space.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a printable character, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
