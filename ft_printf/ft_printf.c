/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:29 by schahir           #+#    #+#             */
/*   Updated: 2024/12/10 18:24:48 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/**
 * handle_specifier - Process different format specifiers
 *
 * @flag: Formatting flags structure
 * @args: Variadic argument list
 *
 * Returns: Total number of characters printed
 */
int	handle_specifier(t_format flag, va_list args)
{
	int	total;

	total = 0;
	if (flag.specifier == 'c')
		total = ft_printchar(flag, args);
	if (flag.specifier == 's')
		total = ft_printstr(flag, args);
	if (flag.specifier == 'd' || flag.specifier == 'i' || flag.specifier == 'u')
		total = ft_printint(flag, args);
	if (flag.specifier == 'x' || flag.specifier == 'X')
		total = ft_printhex(flag, args);
	if (flag.specifier == 'p')
		total = ft_printptr(flag, args);
	if (flag.specifier == '%')
		return (ft_putchar('%'));
	return (total);
}

/**
 * validate_format - Validate the format string for correct specifier
 *
 * @format: Format string to validate
 *
 * Returns: 1 if format is valid, 0 otherwise
 */
int	validate_format(const char *format)
{
	int	i;

	i = 0;
	if (format[i] != '%')
		return (0);
	i++;
	while (format[i] && ft_strchr("-+ #0", format[i]))
		i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		while (format[i] && ft_isdigit(format[i]))
			i++;
	}
	if (!ft_strchr(SPEC, format[i]))
		return (0);
	return (1);
}

/**
 * process_format - Process a single format specifier
 *
 * @str: Pointer to format string
 * @args: Variadic argument list
 *
 * Returns: Total number of characters printed
 */
static int	process_format(const char **str, va_list args)
{
	int			total;
	const char	*start = *str;

	total = 0;
	if (!validate_format(start))
	{
		total += write(1, start, 1);
		(*str)++;
		return (total);
	}
	(*str)++;
	if (**str == '\0' || (!ft_strchr(SPEC, **str) && !ft_isdigit(**str)
			&& !ft_strchr("-+ #0.", **str)))
	{
		va_end(args);
		return (-1);
	}
	total += process((char *)*str, args);
	while (**str && !ft_strchr(SPEC, **str))
		(*str)++;
	if (**str)
		(*str)++;
	return (total);
}

/**
 * ft_printf - Custom printf-like function with variadic arguments
 *
 * @str: Format string
 * @...: Variable number of arguments
 *
 * Returns: Total number of characters printed
 */
int	ft_printf(const char *str, ...)
{
	int		total;
	int		result;
	va_list	args;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			result = process_format(&str, args);
			if (result == -1)
				return (-1);
			total += result;
		}
		else
			total += ft_putchar(*str++);
	}
	va_end(args);
	return (total);
}
