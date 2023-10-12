/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:48 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/12 17:16:34 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_error_message(void)
{
	ft_putstr_fd("ERROR -> Wrong Format.\n", 1);
	exit(0);
}

void	send_bit(pid_t pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		// 가장 오른쪽 비트부터 왼쪽으로 가면서 전송
		// 1을 bit만큼 left shift 연산한 값을 input과 &연산
		if ((input & 1 << bit) != 0)
		// 해당 값이 1일 경우 SIGUSR1 신호 전송
			kill(pid, SIGUSR1);
		else
		// 해당 값이 0일 경우 SIGUSR2 신호 전송
			kill(pid, SIGUSR2);
		// 마이크로초만큼 스레드를 일시정지
		usleep(150);
		bit++;
	}
}

void	send_string(pid_t pid, char *input)
{
	int	i;

	i = -1;
	// 한 문자씩 출력하도록 while문 실행
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
	// 클라이언트 실행 시  2개의 인자(server pid)(send message)를 입력하지 않았을 경우 예외처리
	if (ac == 3 && av[2][0])
	{
		s_pid = ft_minitalk_atoi(av[1]); // 입력한 pid 받아오기
		if (s_pid < 100 || s_pid > 99999) // pid 처리 범위
			send_error_message();
		send_string(s_pid, send_message); // 문자열을 한 번에 받아옴
	}
	else // 에러 처리
	{
		ft_putstr_fd("Error -> Wrong Format.\n", 1);
		ft_putstr_fd("Input Format -> ./client [PID] [Message]\n", 1);
	}
	return (0);
}
