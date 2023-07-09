/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:29:31 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/03 16:46:53 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d(va_list ap)
{
	int				tmp;
	size_t			print;

	print = 0;
	tmp = (int)va_arg(ap, int);
	print = ft_putnbr(tmp);
	return (print);
}
