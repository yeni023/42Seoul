/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:18:10 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 02:24:13 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_last(t_var *stacks)
{
	int	min_location;

	min_location = find_a_min(stacks);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stacks);
			min_location--;
		}
		else
		{
			rra(stacks);
			min_location++;
		}
	}
}

void	devide_pivot(t_var *stack)
{
	t_node	*tmp;
	int		cnt;
	int		p1;
	int		p2;

	p1 = stack->list_size / 3;
	p2 = (stack->list_size / 3) * 2;
	cnt = 0;
	while (cnt < stack->list_size)
	{
		tmp = pop_top(stack->stack_a);
		if (tmp->val < p2)
		{
			push_top (stack->stack_a, tmp);
			pb(stack);
			if (tmp->val < p1)
				rb(stack);
		}
		else
		{
			push_top (stack->stack_a, tmp);
			ra(stack);
		}
		cnt++;
	}
}

int	find_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}
