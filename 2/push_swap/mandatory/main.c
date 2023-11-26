/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:12:44 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 16:02:24 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_var	stack;

	if (ac >= 2)
	{
		init_stack(&stack);
		check_validate_args(ac, av, &stack);
		is_sort(&stack);
		indexing(&stack);
		stacking(&stack);
		swaping(&stack);
		exit(0);
	}
	return (0);
}
