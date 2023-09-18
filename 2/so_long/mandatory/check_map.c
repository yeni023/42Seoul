/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:35:25 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/18 21:35:29 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (info.map[i])
	{
		j = 0;
		while (info.map[i][j])
		{
			if ((i == 0 || i == info.x - 1) && info.map[i][j] != '1')
				ft_error("not surrounded!");
			if ((j == 0 || j == info.y - 1) && info.map[i][j] != '1')
				ft_error("not surrounded!");
			j++;
		}
		i++;
	}
}

void	valid_obj(char **map, t_arg *arg, t_map *info)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				(arg->exit)++;
			if (map[i][j] == 'C')
				(arg->food)++;
			if (map[i][j] == 'P')
			{
				(arg->point)++;
				info->p_x = i;
				info->p_y = j;
			}
		}
	}
	if (arg->exit == 1 && arg->food >= 1 && arg->point == 1)
		return ;
	ft_error("invalid argument!");
}

void	rectangle_map(char **map, int x, size_t y)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (y != ft_strlen(map[i]))
			ft_error("no rectangle!");
		i++;
	}
	if (i != x)
		ft_error("no rectangle!");
}

void	no_other_arg(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'C' && map[i][j] != 'E' &&
				map[i][j] != 'P')
				ft_error("other arg!");
			j++;
		}
		i++;
	}
}
