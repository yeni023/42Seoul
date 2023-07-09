/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeun <yeeun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:04:50 by yeeun             #+#    #+#             */
/*   Updated: 2023/07/03 20:00:57 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	char_cnt(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	putnbr_base(unsigned long long n, char *base)
{
	if (n >= 16)
		putnbr_base((n / 16), base);
	ft_putchar(base [n % 16]);
}

int	ft_puthex(int i, char x)
{
	char			*base;
	int				print;
	unsigned int	c;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	print = 0;
	c = (unsigned int)i;
	putnbr_base(c, base);
	print += char_cnt(c);
	return (print);
}

size_t	ft_print_x(va_list ap, char a)
{
	unsigned int	tmp;
	size_t			print;

	print = 0;
	tmp = (unsigned int)va_arg(ap, unsigned int);
	if (tmp == 0)
	{
		write(1, "0", 1);
		print++;
	}
	else
		print = ft_puthex((long long)tmp, a);
	return (print);
}
