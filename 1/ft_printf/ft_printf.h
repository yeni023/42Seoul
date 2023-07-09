/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:32:40 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/03 20:33:00 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

ssize_t		ft_print_p(va_list ap);

int			ft_putchar(char c);
int			ft_putnbr(long long n);
int			ft_puthex(int i, char x);
int			ft_put_p(unsigned long long n);
int			char_cnt(unsigned long long n);
int			ft_printf(const char *format, ...);

char		*ft_itoa(long long n);

size_t		ft_print_c(va_list ap);
size_t		ft_print_s(va_list ap);
size_t		ft_print_d(va_list ap);
size_t		ft_print_i(va_list ap);
size_t		ft_print_u(va_list ap);
size_t		ft_strlen(const char *s);
size_t		ft_print_x(va_list ap, char a);
size_t		is_check_type(const char *format, va_list ap);

void		putnbr_base(unsigned long long n, char *base);

#endif
