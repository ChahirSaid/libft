/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:21:26 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 11:03:35 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_isdigit - checks for a digit (0 through 9).
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
