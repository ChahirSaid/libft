/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:28:33 by schahir           #+#    #+#             */
/*   Updated: 2025/02/08 15:03:06 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SPEC "csdiupxX%"

typedef struct s_format
{
	int		sharp;
	int		space;
	int		plus;
	int		wdth;
	int		prec_negative;
	int		precision;
	int		dot;
	int		zero;
	int		minus;
	char	specifier;
}			t_format;

int			ft_printf(const char *str, ...);

int			process(char *str, va_list args);
void		init_flag(t_format *format);
int			handle_specifier(t_format flag, va_list args);

int			ft_printchar(t_format flag, va_list args);
int			ft_printstr(t_format flag, va_list args);
int			ft_printint(t_format flag, va_list args);
int			ft_printhex(t_format flag, va_list args);
int			ft_printptr(t_format flag, va_list args);

size_t		ft_strlen(const char *str);
int			ft_putchar(char c);
int			ft_putnchar(char c, int n);
int			ft_putnstr(char *s, int n);
int			ft_isdigit(int ch);
char		*ft_strchr(const char *str, int ch);
int			ft_atoi(const char *str);
char		*ft_itoa(int nb);
char		*ft_uitoa(unsigned int n);
int			ft_hexlen(unsigned long nbr);
int			ft_puthex(t_format flag, size_t n, size_t iteration);

#endif
