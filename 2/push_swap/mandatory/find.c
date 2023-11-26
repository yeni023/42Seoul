/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:12:32 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 02:04:33 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_max(t_var *stacks)
{
	int		res;
	int		tmp;
	int		i;
	t_node	*stack_a;

	res = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	i = get_stack_max(stacks);
	while (res < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == i)
			break ;
		res++;
		stack_a = stack_a->right;
	}
	res++;
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return (res);
}

int	find_a_mid(int n, t_var *stacks)
{
	int		res;
	int		i;
	t_node	*stack_a;

	res = 1;
	i = 0;
	stack_a = stacks->stack_a->top->right;
	while (res < stacks->a_size)
	{
		if (stack_a->right->val == 0)
			return (0);
		if (n > stack_a->val && n < stack_a->right->val)
			break ;
		res++;
		stack_a = stack_a->right;
		i++;
	}
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return (res);
}

int	find_a_min(t_var *stacks)
{
	int		res;
	int		tmp;
	int		i;
	t_node	*stack_a;

	res = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	i = get_stack_min(stacks);
	while (res < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == i)
			break ;
		res++;
		stack_a = stack_a->right;
	}
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return (res);
}

int	find_a(int n, t_var *stack)
{
	int	res;

	if (n < get_stack_min(stack))
		res = find_a_min(stack);
	else if (n > get_stack_max(stack))
		res = find_a_max(stack);
	else
		res = find_a_mid(n, stack);
	return (res);
}
