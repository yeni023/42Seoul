/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:44:11 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/09 14:49:52 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static char	temp;

	(void)s;
	if (signal == SIGUSR1)
		temp |= (1 << bit);
	bit++;
	if (bit == 16)
	{
		if (temp)
			ft_putchar_fd(temp, 1);
		else
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		temp = 0;
	}
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a message...~\n", 1);
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error -> Wrong Format.\n", 1);
		ft_putstr_fd("Input Format : ./server\n", 1);
		return (0);
	}
	ft_memset(&sig, 0, sizeof(sig));
	sig.sa_sigaction = &check_handler;
	print_pid(getpid());
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
