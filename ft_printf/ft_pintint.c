/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pintint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:25:58 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * plus - Determine sign character based on flags
 *
 * @flag: Formatting flags structure
 *
 * Returns: '+' or '-' sign character
 */
static char	plus(t_format flag)
{
	if (flag.plus)
		return ('+');
	return ('-');
}

/**
 * ft_printnbr - Print formatted number with various flags
 *
 * @flag: Formatting flags structure
 * @nb: Number string to print
 * @len: Length of number string
 * @is_neg: Flag indicating if number is negative
 *
 * Returns: Total number of characters printed
 */
static int	ft_printnbr(t_format flag, char *nb, int len, int is_neg)
{
	int	t;

	t = 0;
	flag.wdth -= (flag.space && !is_neg && !flag.plus && flag.wdth);
	if (is_neg || flag.plus)
		t += ft_putnchar(plus(flag), flag.zero && (!flag.dot
					|| flag.prec_negative));
	else if (flag.space)
		t += ft_putnchar(' ', flag.zero && !flag.dot);
	if (!flag.minus && flag.wdth > flag.precision && (!flag.dot
			|| flag.prec_negative) && flag.zero)
		t += ft_putnchar('0', flag.wdth - flag.precision - is_neg - flag.plus);
	else if (!flag.minus && flag.wdth > flag.precision)
		t += ft_putnchar(' ', flag.wdth - flag.precision - is_neg - flag.plus);
	if ((is_neg || flag.plus) && ft_strncmp(nb, "-2147483648", 12))
		t += ft_putnchar(plus(flag), !flag.zero || (flag.dot
					&& !flag.prec_negative));
	else if (flag.space && ft_strncmp(nb, "-2147483648", 12))
		t += ft_putnchar(' ', !flag.zero || flag.dot);
	t += ft_putnchar('0', flag.precision - len);
	t += write(1, nb, len);
	if (flag.minus && flag.wdth > flag.precision)
		t += ft_putnchar(' ', flag.wdth - flag.precision - is_neg - flag.plus);
	return (t);
}

/**
 * ft_printint - Print integer with specified formatting
 *
 * @flag: Formatting flags structure
 * @args: Variadic argument list
 *
 * Returns: Total number of characters printed
 */
int	ft_printint(t_format flag, va_list args)
{
	char	*nb;
	int		n;
	int		t;
	int		len;
	int		is_neg;

	t = 0;
	n = va_arg(args, int);
	is_neg = (n < 0 && n != INT_MIN && flag.specifier != 'u');
	if (is_neg)
		flag.plus = 0;
	if (n < 0 && flag.specifier != 'u')
		n *= -1;
	if (n < 0 && flag.specifier == 'u')
		nb = ft_uitoa((unsigned)n);
	else
		nb = ft_itoa(n);
	len = ft_strlen(nb);
	if (*nb == '0' && !flag.precision && flag.dot)
		len = 0;
	if (flag.precision < len || !flag.dot)
		flag.precision = len;
	t += ft_printnbr(flag, nb, len, is_neg);
	free(nb);
	return (t);
}
