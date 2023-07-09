/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeun <yeeun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:58:54 by yeeun             #+#    #+#             */
/*   Updated: 2023/07/03 16:46:59 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_i(va_list ap)
{
	int				tmp;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	print = ft_putnbr(tmp);
	return (print);
}
