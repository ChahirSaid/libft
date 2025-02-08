/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:24:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * ft_putchar - Write a single character to standard output
 *
 * @c: Character to print
 *
 * Returns: Number of characters printed (always 1)
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * ft_putnchar - Write multiple copies of a character to standard output
 *
 * @c: Character to print
 * @n: Number of times to print the character
 *
 * Returns: Total number of characters printed
 */
int	ft_putnchar(char c, int n)
{
	int	total;

	total = 0;
	while (n-- > 0)
		total += write(1, &c, 1);
	return (total);
}

/**
 * ft_printchar - Print a character with specified formatting
 *
 * @flag: Formatting flags structure
 * @args: Variadic argument list
 *
 * Returns: Total number of characters printed
 */
int	ft_printchar(t_format flag, va_list args)
{
	char	c;
	int		total;

	total = 0;
	if (flag.specifier == 'c')
		c = va_arg(args, int);
	else
		c = '%';
	flag.precision = 1;
	if (!flag.minus && flag.zero)
		total += ft_putnchar('0', flag.wdth - flag.precision);
	else if (!flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	total += ft_putchar(c);
	if (flag.minus && flag.wdth - flag.precision > 0)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}
