/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeun <yeeun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:03:23 by yeeun             #+#    #+#             */
/*   Updated: 2023/07/03 16:47:14 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_u(va_list ap)
{
	unsigned int	tmp;
	size_t			print;

	print = 0;
	tmp = va_arg(ap, unsigned int);
	print = ft_putnbr(tmp);
	return (print);
}
