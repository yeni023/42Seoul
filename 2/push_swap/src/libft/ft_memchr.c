/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 07:57:27 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/24 16:57:45 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *find_s, int find_word, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *) find_s;
	while (i < n)
	{
		if (s[i] == (unsigned char)find_word)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
