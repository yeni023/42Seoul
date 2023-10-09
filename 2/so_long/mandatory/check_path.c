/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:45 by donghyk2          #+#    #+#             */
/*   Updated: 2023/10/08 22:14:57 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allfree(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (0);
}

char	**multidup(char **s, int x)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (x + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = ft_strdup(s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// 현재 위치(x, y)에서 시작하여 특정 문자(find_words)를 찾고, 찾은 횟수를 센다
int	dfs(int x, int y, char **map, char find_words)
{
	int	cnt;

	// '1' 이라면 벽이니까 0 반환
	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'V')
	{
		cnt = 0;
		if (map[x][y] == find_words)
			cnt++;
		// 방문했다는 표식 -> 'V'
		map[x][y] = 'V';
		// 상, 하, 좌, 우로 이동하며 재귀적으로 호출하여 찾은 문자 카운트
		cnt += dfs(x - 1, y, map, find_words);
		cnt += dfs(x, y + 1, map, find_words);
		cnt += dfs(x + 1, y, map, find_words);
		cnt += dfs(x, y - 1, map, find_words);
		// 찾은 문자 반환
		return (cnt);
	}
	return (0);
}

// E 문자를 '1'로 변경해서 지도의 일부를 수정함
// 플레이어가 출구로 가는 경로 탐색 시 출구를 피하기 위해
void	exit_to_wall(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'E')
				s[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	valid_road(t_map info, t_arg arg, int x, int y)
{
	char	**visited_exit;
	char	**visited_food;

	// info.map 배열의 복제본을 만들어 가리키는 포인터
	// 지도의 출구와 음식에 대한 경로 탐색을 수행하기 위해 만들었음
	// info.x = 행의 개수
	visited_exit = multidup(info.map, info.x);
	visited_food = multidup(info.map, info.x);
	exit_to_wall(visited_food);
	while (info.map[++x])
	{
		y = upgrade_ft_strchr(info.map[x], 'P');
		// 찾지 못한 경우 y = -1
		// 찾은 경우에 if문 수행
		if (y != -1)
		{
			// 찾은 개수가 같은 경우에 arg.food 값 반환
			// dfs로 돌아다니면서 확인한 갯수와 처음에 체크한 갯수가 동일한지 확인
			if (arg.exit == dfs(x, y, visited_exit, 'E')
				&& arg.food == dfs(x, y, visited_food, 'C'))
			{
				allfree(visited_exit);
				allfree(visited_food);
				return (arg.food);
			}
			else
				break ;
		}
	}
	allfree(visited_exit);
	allfree(visited_food);
	return (print_error("invalid path!"));
}
