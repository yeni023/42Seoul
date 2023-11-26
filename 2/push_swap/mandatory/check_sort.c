/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:11:47 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 11:24:45 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sort(t_var *stack)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (i < stack->list_size - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			cnt++;
		i++;
	}
	if (cnt == 0)
		exit(0);
}

int	find_max(t_var *stack)
{
	long	changing;
	int		i;

	changing = -2147483649;
	i = 0;
	while (i < stack->list_size)
	{
		if (changing < stack->list[i])
			changing = stack->list[i];
		i++;
	}
	i = 0;
	while (i < stack->list_size)
	{
		if (changing == stack->list[i])
		{
			stack->list[i] = -2147483649;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	indexing(t_var *stack)
{
	long	*indexing_list;
	int		i;
	int		i_max;

	indexing_list = (long *)malloc(sizeof(long) * stack->list_size);
	if (!indexing_list)
		ft_error();
	i = stack->list_size -1;
	while (i >= 0)
	{
		i_max = find_max(stack);
		indexing_list[i_max] = i;
		i--;
	}
	free (stack->list);
	stack->list = indexing_list;
}
