/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:59 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/12 15:42:29 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_error_message(void)
{
	ft_putstr_fd("Error -> Wrong Format.\n", 1);
	exit(0);
}

void	check_message(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Success -> Server received message!\n", 1);
	exit(0);
}

void	send_bit(pid_t pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((input & 1 << bit) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(550);
		bit++;
	}
}

void	send_string(pid_t pid, char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		send_bit(pid, input[i]);
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

int	main(int ac, char **av)
{
	char	*send_message;
	pid_t	s_pid;

	send_message = av[2];
	if (ac == 3 && av[2][0])
	{
		signal(SIGUSR1, check_message);
		s_pid = ft_minitalk_atoi(av[1]);
		if (s_pid < 100 || s_pid >= 99999)
			send_error_message();
		send_string(s_pid, send_message);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("Error -> Wrong Format.\n", 1);
		ft_putstr_fd("Input Format -> ./client [PID] [Message]\n", 1);
	}
	return (0);
}
