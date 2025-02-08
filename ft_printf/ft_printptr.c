/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:05 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * printptr_helper - Helper function to print pointer address
 *
 * @flag: Formatting flags structure
 * @n: Pointer address to print
 *
 * Returns: Total number of characters printed
 */
static int	printptr_helper(t_format flag, size_t n)
{
	int	total;
	int	len;

	total = 0;
	if (n == 0)
	{
		if (flag.wdth > 5 && !flag.minus)
			total += ft_putnchar(' ', flag.wdth - 5);
		total += write(1, "(nil)", 5);
		if (flag.wdth > 5 && flag.minus)
			total += ft_putnchar(' ', flag.wdth - 5);
		return (total);
	}
	len = ft_hexlen(n);
	if (flag.precision < len || !flag.dot)
		flag.precision = len;
	flag.wdth -= 2;
	if (!flag.minus && flag.wdth > flag.precision && !flag.zero)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	total += write(1, "0x", 2);
	total += ft_putnchar('0', flag.precision - len);
	total += ft_puthex(flag, n, n);
	if (flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}

/**
 * ft_printptr - Print pointer address with specified formatting
 *
 * @flag: Formatting flags structure
 * @args: Variadic argument list
 *
 * Returns: Total number of characters printed
 */
int	ft_printptr(t_format flag, va_list args)
{
	size_t	n;

	n = va_arg(args, size_t);
	return (printptr_helper(flag, n));
}
