/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:25:17 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/08 19:23:32 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		print_error("The file extension is .ber");
}

void	parsing_map(char *filename, t_map	*info)
{
	int		fd;
	char	*line_map;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("invalid fd");
	// 빈 문자열을 동적으로 할당된 메모리에 복제하고, 그 결과로 반환된 문자열의 포인터를 line_map에 저장
	// line_map -> 빈 문자열을 가리키는 포인터
	// 나중에 다른 문자열과 결합하는 용도
	line_map = ft_strdup("");
	while (1)
	{
		// map을 한 줄씩 읽어옴
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (temp[0] == '\n')
			print_error("devided map");
		// line_map 문자열과 temp 문자열을 연결함
		line_map = free_join(line_map, temp);
	}
	// line_map을 줄바꿈 기준으로 분할하고, 그 결과를 info->map에 저장함
	// 하나의 문자열로 연결한 상태가 됨
	info->map = ft_split(line_map, '\n');
	free(line_map);
	close(fd);
}

char	*free_join(char	*s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

int	valid_map(t_map *info)
{
	t_arg	arg;

	// arg 구조체 변수를 0으로 초기화하는 역할
	// &arg -> 구조체 변수 arg의 시작 주소 (= 구조체 변수를 가르키는 포인터)
	// 해당 변수의 값을 0으로 설정해서 초기 상태의 arg를 만드는 과정
	ft_memset(&arg, 0, sizeof(arg));
	// 벽으로 둘러쌓였는지 확인
	surrounded_wall(*info);
	// 맵에서 문자의 개수(E, C, P)를 세고, 유효성 검사 함수
	valid_obj(info->map, &arg, info);
	// 직사각형 형태인지 확인
	rectangle_map(info->map, info->x, info->y);
	// 다른 문자가 없는지 확인
	no_other_arg(info->map);
	return (valid_road((*info), arg, -1, -1));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("The file does not exist");
	arg_check(argv[1]);
	game.info = (t_map *)malloc(sizeof(t_map));
	parsing_map(argv[1], game.info);
	// 맵의 행과 열의 개수를 info->x, info->y에 저장해서 t_map에 저장함
	find_x_y(game.info);
	// 지도의 유효성을 검사하고, 게임에서 활용할 동전의 개수를 결정하는 역할
	game.coinnum = valid_map(game.info);
	start_game(&game);
}
