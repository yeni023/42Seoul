/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:47:45 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 22:08:49 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	do_echo(char **argv, int idx)
{
	while (argv[++idx])
	{
		if (argv[idx][0] == '\0')
			continue ;
		ft_putstr_fd(argv[idx], STDOUT_FILENO);
		if (argv[idx + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
}

int	ms_echo(char **argv)
{
	int	idx;
	int	n_idx;
	int	newline;

	newline = 1;
	idx = 0;
	if (argv[1] && ft_strncmp(argv[1], "-n", 2) == 0)
	{
		n_idx = 1;
		while (argv[1][n_idx] == 'n')
			n_idx++;
		if (argv[1][n_idx] == '\0')
			newline = 0;
		if (argv[1][n_idx] == '\0')
			idx++;
	}
	do_echo(argv, idx);
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
