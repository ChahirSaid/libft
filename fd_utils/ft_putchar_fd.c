/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:55:15 by schahir           #+#    #+#             */
/*   Updated: 2024/10/26 17:15:19 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putchar_fd - outputs the character c to the given file descriptor.
 *
 * @c: The character to output.
 * @fd: The file descriptor on which to write.
 *
 * Return: None.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
