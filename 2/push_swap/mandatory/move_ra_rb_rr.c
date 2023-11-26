/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ra_rb_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:16:25 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 02:16:24 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	write(1, "rb\n", 3);
}

void	rr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	write(1, "rr\n", 3);
}
