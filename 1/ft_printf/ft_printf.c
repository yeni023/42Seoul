/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:17:49 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/06 15:44:25 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

size_t	is_check_type(const char *format, va_list ap)
{
	size_t	print;

	print = 0;
	if (*format == 'c')
		print = ft_print_c(ap);
	else if (*format == 's')
		print = ft_print_s(ap);
	else if (*format == 'p')
		print = ft_print_p(ap);
	else if (*format == 'd')
		print = ft_print_d(ap);
	else if (*format == 'i')
		print = ft_print_i(ap);
	else if (*format == 'u')
		print = ft_print_u(ap);
	else if (*format == 'x')
		print = ft_print_x(ap, 'x');
	else if (*format == 'X')
		print = ft_print_x(ap, 'X');
	else if (*format == '%')
		print = write(1, "%%", 1);
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	size_t		print;

	i = 0;
	print = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			print += is_check_type(&format[i], ap);
		}
		else
			print += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (print);
}
