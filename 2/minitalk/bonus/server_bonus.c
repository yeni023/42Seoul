/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:44:11 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/14 17:38:50 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// signal --> 시그널 핸들러를 호출할 시그널
// info --> 시그널이 발생한 원인을 담은 siginfo_t 구조체 포인터
void	check_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static char	temp;

	(void)s;
	if (signal == SIGUSR1)
		temp |= (1 << bit);
	bit++;
	if (bit == 8)
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
	// sig 구조체를 초기화해서 모든 값을 0으로 설정
	ft_memset(&sig, 0, sizeof(sig));
	// 시그널 핸들러를 지정할 때 sa_sigaction을 사용
	sig.sa_sigaction = &check_handler;
	// getpid --> 현재 프로세스의 아이디를 리턴, 무조건 성공하기 때문에 실패한 경우에 반환 값은 없음
	print_pid(getpid());
	// SIGUSR1 을 처리하기 위한 sig 구조체 등록
	// SIGUSR1 발생하면 check_handler 호출
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
