/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:54:33 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/20 21:30:22 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_cnt(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	return (ft_put(str, n, len - 1));
}
