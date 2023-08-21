/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:52:03 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/17 21:07:08 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(s1);
	dst_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (src_len + dst_len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, src_len + 1);
	ft_strlcat(str + (src_len), s2, dst_len + 1);
	return (str);
}
