/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:21:24 by donghyk2          #+#    #+#             */
/*   Updated: 2023/09/18 21:35:42 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	free_all_struct(game);
	exit(0);
	return (0);
}

int	key_pressed_w(t_game *game, t_map *info)
{
	if (is_valid_w_key(info->map, info, game))
	{
		info->map[info->p_x][info->p_y] = '0';
		info->p_x -= 1;
		info->map[info->p_x][info->p_y] = 'P';
		return (1);
	}
	return (0);
}

int	key_pressed_s(t_game *game, t_map *info)
{
	if (is_valid_s_key(info->map, info, game))
	{
		info->map[info->p_x][info->p_y] = '0';
		info->p_x += 1;
		info->map[info->p_x][info->p_y] = 'P';
		return (1);
	}
	return (0);
}

int	key_pressed_a(t_game *game, t_map *info)
{
	if (is_valid_a_key(info->map, info, game))
	{
		info->map[info->p_x][info->p_y] = '0';
		info->p_y -= 1;
		info->map[info->p_x][info->p_y] = 'P';
		return (1);
	}
	return (0);
}

int	key_pressed_d(t_game *game, t_map *info)
{
	if (is_valid_d_key(info->map, info, game))
	{
		info->map[info->p_x][info->p_y] = '0';
		info->p_y += 1;
		info->map[info->p_x][info->p_y] = 'P';
		return (1);
	}
	return (0);
}
