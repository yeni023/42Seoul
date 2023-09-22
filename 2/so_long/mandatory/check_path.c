/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:45 by donghyk2          #+#    #+#             */
/*   Updated: 2023/09/22 16:49:41 by yeeunpar         ###   ########.fr       */
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

int	dfs(int x, int y, char **map, char find_words)
{
	int	cnt;

	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'V')
	{
		cnt = 0;
		if (map[x][y] == find_words)
			cnt++;
		map[x][y] = 'V';
		cnt += dfs(x - 1, y, map, find_words);
		cnt += dfs(x, y + 1, map, find_words);
		cnt += dfs(x + 1, y, map, find_words);
		cnt += dfs(x, y - 1, map, find_words);
		return (cnt);
	}
	return (0);
}

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

	visited_exit = multidup(info.map, info.x);
	visited_food = multidup(info.map, info.x);
	exit_to_wall(visited_food);
	while (info.map[++x])
	{
		y = upgrade_ft_strchr(info.map[x], 'P');
		if (y != -1)
		{
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
