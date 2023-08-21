/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:14:02 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/03/21 21:24:25 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*save;

	tmp = *lst;
	while (tmp)
	{
		save = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = save;
	}
	*lst = NULL;
}
