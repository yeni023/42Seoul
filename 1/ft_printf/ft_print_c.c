/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:25:04 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/06 15:48:16 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_c(va_list ap)
{
	unsigned char	tmp;
	size_t			res;

	res = 0;
	tmp = (unsigned char)va_arg(ap, int);
	res = write(1, &tmp, 1);
	return (res);
}
