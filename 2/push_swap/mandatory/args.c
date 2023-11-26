/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:09:50 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 13:38:05 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_size(char const *str, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char	*join_args(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	i = 0;
	k = 0;
	len = 0;
	while (++i < ac)
		len += ft_strlen(av[i]) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
			str[k++] = av[i][j++];
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

void	check_overlap(t_var *stack, int check)
{
	int		i;
	long	*tmp;

	i = 0;
	while (i < stack->list_size)
	{
		if (stack->list[i] == check)
			ft_error();
		i++;
	}
	stack->list_size++;
	tmp = (long *)malloc(sizeof(long) * stack->list_size);
	if (!tmp)
		ft_error();
	if (stack->list_size == 1)
		tmp[0] = check;
	else
	{
		i = -1;
		while (++i < stack->list_size -1)
			tmp[i] = stack->list[i];
		tmp[i] = check;
	}
	free(stack->list);
	stack->list = tmp;
}

void	check_validate_args(int ac, char **av, t_var *stack)
{
	char	*args;
	char	**tmp;
	int		i;
	int		tmp_size;
	t_node	*new_node;

	i = 0;
	args = join_args(ac, av);
	tmp = ft_split(args, ' ');
	tmp_size = check_size(args, ' ');
	free (args);
	while (i < tmp_size)
	{
		if (!is_number(tmp[i]))
			ft_error();
		new_node = add_new_node(ft_atoi(tmp[i]));
		free(tmp[i]);
		check_overlap(stack, new_node->val);
		i++;
		free(new_node);
	}
	free(tmp);
}
