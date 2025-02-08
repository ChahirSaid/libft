/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:24:57 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * ft_hexlen - Calculate length of a hexadecimal representation
 *
 * @nbr: Unsigned long number to convert
 *
 * Returns: Number of hexadecimal digits
 */
int	ft_hexlen(unsigned long nbr)
{
	unsigned long	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

/**
 * ft_sharp - Get hexadecimal prefix based on specifier
 *
 * @flag: Formatting flags structure
 *
 * Returns: Hexadecimal prefix string ("0x" or "0X")
 */
static char	*ft_sharp(t_format flag)
{
	if (flag.specifier == 'x')
		return ("0x");
	return ("0X");
}

/**
 * ft_puthex - Recursively print hexadecimal representation of a number
 *
 * @flag: Formatting flags structure
 * @n: Number to convert
 * @is_recurcive: Flag to track first recursive call
 * 		prevents rechecking conditions meant only for the initial call (0,#,.)
 *
 * Returns: Total number of characters printed
 */
int	ft_puthex(t_format flag, size_t n, size_t is_recurcive)
{
	int			total;
	const char	*base;

	if (!(n > 0 || (!is_recurcive && (flag.specifier != 'p' || !flag.dot))))
		return (0);
	if (flag.specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	total = ft_puthex(flag, n / 16, 1);
	return (total + ft_putchar(base[n % 16]));
}

/**
 * ft_hex_prefix_padding - Print padding and prefix for hexadecimal conversion
 *
 * @flag: Formatting flags structure
 * @n: Number to convert
 * @len: Length of the number
 *
 * Returns: Total number of characters printed
 */
static int	ft_hex_prefix_padding(t_format *flag, unsigned int n, int len)
{
	int	total;
	int	prefix_length;

	total = 0;
	prefix_length = 0;
	if (flag->sharp && flag->zero && n != 0)
	{
		prefix_length = 2;
	}
	if (flag->sharp && n)
		flag->wdth -= 2;
	total += ft_putnstr(ft_sharp(*flag), prefix_length);
	if (!flag->minus && flag->wdth > flag->precision)
	{
		if ((!flag->dot || flag->prec_negative) && flag->zero)
			total += ft_putnchar('0', (flag->wdth - flag->precision));
		else
			total += ft_putnchar(' ', (flag->wdth - flag->precision));
	}
	if (flag->sharp && !flag->zero && n)
		total += ft_putnstr(ft_sharp(*flag), 2);
	total += ft_putnchar('0', (flag->precision - len));
	return (total);
}

/**
 * ft_printhex - Print hexadecimal conversion
 *
 * @flag: Formatting flags structure
 * @args: Variable argument list
 *
 * Returns: Total number of characters printed
 */
int	ft_printhex(t_format flag, va_list args)
{
	int				total;
	unsigned int	n;
	int				len;

	total = 0;
	n = va_arg(args, unsigned int);
	len = ft_hexlen(n);
	if (!n && !flag.precision && flag.dot)
		len = 0;
	if (flag.precision < 0 || flag.precision < len || !flag.dot)
		flag.precision = len;
	total += ft_hex_prefix_padding(&flag, n, len);
	if (len)
		total += ft_puthex(flag, n, n);
	if (flag.minus && flag.wdth > flag.precision)
		total += ft_putnchar(' ', flag.wdth - flag.precision);
	return (total);
}
