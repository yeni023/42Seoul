/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 07:18:13 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/24 16:57:52 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst < src)
	{
		while (idx < n)
		{
			((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	else
	{
		idx = n;
		while (idx)
		{
			((unsigned char *)dst)[idx - 1] = ((unsigned char *)src)[idx - 1];
			idx--;
		}
	}
	return (dst);
}
