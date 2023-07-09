/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:59:49 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/03 20:30:44 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(unsigned long long n)
{
	char	*base;
	int		print;

	base = "0123456789abcdef";
	print = 0;
	putnbr_base(n, base);
	print += char_cnt(n);
	return (print);
}

ssize_t	ft_print_p(va_list ap)
{
	unsigned long long	tmp;
	int					print;

	print = 0;
	tmp = va_arg(ap, unsigned long long);
	if (tmp == 0)
		return (write(1, "0x0", 3));
	print += write(1, "0x", 2);
	print += ft_put_p(tmp);
	return (print);
}
