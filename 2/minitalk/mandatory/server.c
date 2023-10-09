/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:35 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/09 14:33:21 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_handler(int signal)
{
	static int	bit;
	static char	temp;

	if (signal == SIGUSR1)
		temp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(temp, 1);
		bit = 0;
		temp = 0;
	}
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a Message..~\n", 1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error -> Wrong Format.\n", 1);
		ft_putstr_fd("Input Format : ./server\n", 1);
		return (0);
	}
	print_pid(getpid());
	signal(SIGUSR1, check_handler);
	signal(SIGUSR2, check_handler);
	while (ac == 1)
		pause();
	return (0);
}
