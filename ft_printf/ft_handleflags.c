/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:27 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:23:14 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * init_flag - Initialize formatting flags structure to default values
 *
 * @format: Pointer to formatting flags structure
 */
void	init_flag(t_format *format)
{
	format->sharp = 0;
	format->space = 0;
	format->plus = 0;
	format->wdth = 0;
	format->prec_negative = 0;
	format->precision = 0;
	format->dot = 0;
	format->zero = 0;
	format->minus = 0;
	format->specifier = 0;
}

/**
 * handle_flags - Process flags in format string (like +, space, #)
 *
 * @str: Format string
 * @flag: Current formatting flags structure
 *
 * Returns: Updated formatting flags structure
 */
static t_format	handle_flags(char *str, t_format flag)
{
	while (*str != '.' && !ft_strchr(SPEC, *str))
	{
		if (*str == '+')
			flag.plus = 1;
		if (*str == ' ')
			flag.space = 1;
		if (*str == '#')
			flag.sharp = 1;
		str++;
	}
	return (flag);
}

/**
 * handle_width - Process width-related flags (-, 0, numeric width)
 *
 * @str: Format string
 * @flag: Current formatting flags structure
 *
 * Returns: Updated formatting flags structure
 */
static t_format	handle_width(char *str, t_format flag)
{
	int	is_set;

	is_set = 0;
	while (*str != '.' && !ft_strchr(SPEC, *str))
	{
		if (*str == '-')
			flag.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			flag.zero = 1;
		else if ((*str > '0' && *str <= '9') && !is_set)
		{
			flag.wdth = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
	return (flag);
}

/**
 * handle_precision - Process precision-related flags
 *
 * @str: Format string
 * @flag: Current formatting flags structure
 *
 * Returns: Updated formatting flags structure
 */
static t_format	handle_precision(char *str, t_format flag)
{
	int	is_set;

	is_set = 0;
	while (!ft_strchr(SPEC, *str))
	{
		if (ft_isdigit(*str) && !is_set)
		{
			flag.precision = ft_atoi(str);
			is_set = 1;
		}
		str++;
	}
	return (flag);
}

/**
 * process - Main processing function for format specifiers
 *
 * @str: Format string
 * @args: Variadic argument list
 *
 * Returns: Result of handling the specific format specifier
 */
int	process(char *str, va_list args)
{
	t_format	format;

	init_flag(&format);
	format = handle_width(str, format);
	format = handle_flags(str, format);
	while (!ft_strchr(SPEC, *str) && *str != '.')
		str++;
	if (*str == '.' && !format.specifier)
	{
		format.dot = 1;
		format = handle_precision(str++, format);
		while (!ft_strchr(SPEC, *str))
			str++;
	}
	if (format.wdth < 0)
	{
		format.minus = 1;
		format.wdth *= -1;
	}
	format.specifier = *str;
	format.prec_negative = format.precision < 0;
	return (handle_specifier(format, args));
}
