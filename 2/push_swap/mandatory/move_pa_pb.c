/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pa_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:16:09 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 02:14:02 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_var *stacks)
{
	t_node	*tmp1;

	if (stacks->stack_b->top->right)
	{
		tmp1 = pop_top(stacks->stack_b);
		push_top(stacks->stack_a, tmp1);
		stacks->b_size--;
		stacks->a_size++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_var *stacks)
{
	t_node	*tmp1;

	if (stacks->stack_a->top->right)
	{
		tmp1 = pop_top(stacks->stack_a);
		push_top(stacks->stack_b, tmp1);
		stacks->a_size--;
		stacks->b_size++;
		write(1, "pb\n", 3);
	}
}
