/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:45:56 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/20 21:35:04 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	len;
	char	c;

	if (fd < 0)
		return ;
	len = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		len *= -1;
	}
	if (len < 10)
	{
		c = len + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(len / 10, fd);
		c = len % 10 + '0';
		write(fd, &c, 1);
	}	
}
