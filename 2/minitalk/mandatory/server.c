/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:35 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/12 15:41:40 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_handler(int signal)
{
	static int	bit; // 비트를 얼마나 받았는지 확인하는 정적 변수
	static char	temp; // 문자값을 저장하는 정적 변수
	// USR2 일 때는 어차피 0 이므로 PASS
	if (signal == SIGUSR1)
		// |= --> or 연산 수행
		// 가장 오른쪽 비트부터 추가
		temp |= (1 << bit);
	bit++;
	// 8bit 만큼의 시그널을 받았다면 해당 문자 값을 저장하기 위한 변수도 정적으로 선언
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

// 유니코드 -> UTF-8로 인코딩을 실행하므로 자동으로 유니코드를 변환 -> 따로 작성할 필요X
int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error -> Wrong Format.\n", 1);
		ft_putstr_fd("Input Format : ./server\n", 1);
		return (0);
	}
	// pid 받아와서 출력
	print_pid(getpid());
	signal(SIGUSR1, check_handler);
	signal(SIGUSR2, check_handler);
	// 시그널을 수신할 때까지 대기 상태로 전환한다.
	while (ac == 1)
		pause();
	return (0);
}
