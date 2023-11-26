/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:17:22 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 02:27:16 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_rotate(t_var *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	b_rotate(t_var *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	same_rotate(t_var *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	min_rotate(t_var *stack, int *a, int *b)
{
	int		i;
	int		num;
	int		location_a;
	int		location_b;
	t_node	*b_node;

	i = 0;
	b_node = stack->stack_b->top->right;
	while (i < stack->b_size)
	{
		num = b_node->val;
		location_a = find_a(num, stack);
		if (i >= (stack->b_size + 1) / 2)
			location_b = (stack->b_size - i) * -1;
		else
			location_b = i;
		if (i == 0 || find_bigger(*a, *b, location_a, location_b))
		{
			*a = location_a;
			*b = location_b;
		}	
		b_node = b_node->right;
		i++;
	}
}
