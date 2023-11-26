/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:19:06 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 15:40:50 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *new_node)
{
	t_node	*tmp;
	t_node	*top;

	top = stack->top;
	tmp = top->right;
	top->right = new_node;
	tmp->left = new_node;
	new_node->left = top;
	new_node->right = tmp;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*tmp;
	t_node	*bottom;

	bottom = stack->bottom;
	tmp = bottom->left;
	bottom->left = new_node;
	tmp->right = new_node;
	new_node->right = bottom;
	new_node->left = tmp;
}
