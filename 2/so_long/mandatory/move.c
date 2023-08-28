/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:55:05 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 15:32:04 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void move_d(t_map *map)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break;
		i++;
	}
	if (map->map_line[i + 1] == '1')
		return;
	if (map->map_line[i + 1] == 'C')
		map->c_items++;
	if (map->map_line[i + 1] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i + 1] == 'E' && map->all_items != map->c_items)
		return;
	else if (map->map_line[i + 1] != '1' || map->map_line[i + 1] != 'E')
	{
		map->map_line[i + 1] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void move_a(t_map *map)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map->map_line[i] == 'P')
			break;
		i++;
	}
	if (map->map_line[i - 1] == '1')
		return;
	if (map->map_line[i - 1] == 'C')
		map->c_items++;
	if (map->map_line[i - 1] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i - 1] == 'E' && map->all_items != map->c_items)
		return;
	else if (map->map_line[i - 1] != '1' || map->map_line[i + 1] != 'E')
	{
		map->map_line[i - 1] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void move_w(t_map *map)
{
	size_t i;

	i = -1;
	while (++i < ft_strlen(map->map_line))
		if (map->map_line[i] == 'P')
			break;
	if (map->map_line[i - map->width] == '1')
		return;
	if (map->map_line[i - map->width] == 'C')
		map->c_items++;
	if (map->map_line[i - map->width] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i - map->width] == 'E' && map->all_items != map->c_items)
		return;
	else if (map->map_line[i - map->width] != '1' ||
			 map->map_line[i + 1] != 'E')
	{
		map->map_line[i - map->width] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}

void move_s(t_map *map)
{
	size_t i;

	i = -1;
	while (++i < ft_strlen(map->map_line))
		if (map->map_line[i] == 'P')
			break;
	if (map->map_line[i + map->width] == '1')
		return;
	if (map->map_line[i + map->width] == 'C')
		map->c_items++;
	if (map->map_line[i + map->width] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i + map->width] == 'E' && map->all_items != map->c_items)
		return;
	else if (map->map_line[i + map->width] != '1' ||
			 map->map_line[i + 1] != 'E')
	{
		map->map_line[i + map->width] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		printf("%d\n", map->walk_cnt);
		setting_img(map);
	}
}