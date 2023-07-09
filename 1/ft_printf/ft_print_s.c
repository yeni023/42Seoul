/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:27 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/03 16:46:24 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_s(va_list ap)
{
	char	*tmp;
	size_t	print;

	print = 0;
	tmp = (char *)va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	print = write(1, tmp, ft_strlen(tmp));
	return (print);
}
