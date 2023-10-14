/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:35 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/14 16:40:15 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 클라이언트가 반복적으로 보내는 시그널을 해독하기 위한 함수
// 시그널이 발생할 때마다 호출
void	check_handler(int signal)
{
	static int	bit; // 현재 비트 위치를 나타냄 (0~7)
	static char	temp; // 현재 수신된 문자 저장
	// USR2 일 때는 어차피 0 이므로 PASS
	if (signal == SIGUSR1)
		// 1을 해당 비트만큼 shift left 연산 -> or 연산
		temp |= (1 << bit);
	// SIGSUR2라면 pass해서 자동으로 0을 or 연산하는 것과 같음
	bit++;
	// 8bit 만큼의 시그널을 받았다면 해당 문자 값을 저장하기 위한 변수도 정적으로 선언
	if (bit == 8)
	{
		ft_putchar_fd(temp, 1);
		// 다 채워졌으니까 초기화
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
