/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:16:53 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/17 16:06:46 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		index;

	dst = (char *)malloc(ft_strlen(s) + 1);
	index = 0;
	if (dst == NULL)
		return (NULL);
	while (s[index])
	{
		dst[index] = s[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
