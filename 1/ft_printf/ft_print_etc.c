/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:25:14 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/06 15:35:47 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cnt(long long n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	while (n >= 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_put(char *str, long long n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	str[len] = n % 10 + 48;
	return (str);
}

char	*ft_itoa(long long n)
{
	int		len;
	char	*str;

	len = ft_cnt(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	return (ft_put(str, n, len - 1));
}

static void	write_nbr(long long n, int *cnt)
{
	char	a;

	if (n >= 10)
		write_nbr(n / 10, cnt);
	a = n % 10 + 48;
	write(1, &a, 1);
	(*cnt)++;
}

int	ft_putnbr(long long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		cnt++;
	}
	write_nbr(n, &cnt);
	return (cnt);
}
