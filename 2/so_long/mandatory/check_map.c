/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:35:25 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/10/08 19:24:15 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// x : 행(row), y : 열(col) 값을 계산하는 역할
void	find_x_y(t_map *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
			j++;
		i++;
	}
	info->x = i;
	info->y = j;
}

void	surrounded_wall(t_map info)
{
	int	i;
	int	j;

	i = 0;
	// info.map 배열의 각 행(row)를 순회
	while (info.map[i])
	{
		j = 0;
		// info.map 배열의 각 열(col)을 순회
		while (info.map[i][j])
		{
			// info.x 는 지도의 행(row)수를 나타내는데 인덱스는 0부터 시작하니까 -1
			// i == 0 || i == info.x - 1은 현재 위치가 지도의 가장자리 행에 있는지 검사
			if ((i == 0 || i == info.x - 1) && info.map[i][j] != '1')
				print_error("Not surrounded by walls");
			// i == 0 || i == info.x - 1은 현재 위치가 지도의 가장자리 열에 있는지 검사
			if ((j == 0 || j == info.y - 1) && info.map[i][j] != '1')
				print_error("Not surrounded by walls");
			j++;
		}
		i++;
	}
}

// 지도 : map
// E, C, P 개수 : arg
// 플레이어 위치 : info
void	valid_obj(char **map, t_arg *arg, t_map *info)
{
	int	i;
	int	j;

	i = -1;
	// 행이 존재하는 동안 반복
	while (map[++i])
	{
		// 열이 존재하는 동안 반복
		j = -1;
		while (map[i][++j])
		{
			// if 문을 사용해서 현재 위치의 문자 검사
			if (map[i][j] == 'E')
				(arg->exit)++;
			if (map[i][j] == 'C')
				(arg->food)++;
			if (map[i][j] == 'P')
			{
				(arg->peng)++;
				// 현재 위치(i, j)를 저장
				info->p_x = i;
				info->p_y = j;
			}
		}
	}
	// E가 한 개, F가 한 개 이상, P가 한 개인 경우에만 유효하다고 판단 (유효하면 종료)
	if (arg->exit == 1 && arg->food >= 1 && arg->peng == 1)
		return ;
	print_error("invalid argument(E, P, C)");
}

// 직사각형 = 모든 행의 길이가 동일하며 모든 행의 개수가 같아야 함
// x : 지도의 행 수, y : 지도의 열 수(각 행의 길이)
void	rectangle_map(char **map, int x, size_t y)
{
	int	i;

	i = 0;
	// 행이 존재하는 동안
	while (map[i])
	{
		// 현재 행의 길이와 다른 행의 길이를 비교해서 모든 행이 동일한 길이인지
		if (y != ft_strlen(map[i]))
			print_error("It is not a rectangle");
		i++;
	}
	// 행의 개수가 동일한 지 확인
	if (i != x)
		print_error("It is not a rectangle");
}

void	no_other_arg(char **map)
{
	int	i;
	int	j;

	i = 0;
	// 행이 존재하는 동안 반복
	while (map[i])
	{
		j = 0;
		// 열이 존재하는 동안 반복
		while (map[i][j])
		{
			// 다른 문자 있는지 확인
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'C' && map[i][j] != 'E' &&
				map[i][j] != 'P')
				print_error("other arg");
			j++;
		}
		i++;
	}
}
