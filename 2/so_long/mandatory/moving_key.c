/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:51:28 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/21 16:51:30 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

int	is_check_w_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x - 1][info->p_y] == '1')
		return (0);
	if (map[info->p_x - 1][info->p_y] == '0')
		return (1);
	if (map[info->p_x - 1][info->p_y] == 'C')
	{
		game->coinnum -= 1;
		return (1);
	}
	if (map[info->p_x - 1][info->p_y] == 'E')
	{
		if (game->coinnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_check_s_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x + 1][info->p_y] == '1')
		return (0);
	if (map[info->p_x + 1][info->p_y] == '0')
		return (1);
	if (map[info->p_x + 1][info->p_y] == 'C')
	{
		game->coinnum -= 1;
		return (1);
	}
	if (map[info->p_x + 1][info->p_y] == 'E')
	{
		if (game->coinnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_check_a_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x][info->p_y - 1] == '1')
		return (0);
	if (map[info->p_x][info->p_y - 1] == '0')
		return (1);
	if (map[info->p_x][info->p_y - 1] == 'C')
	{
		game->coinnum -= 1;
		return (1);
	}
	if (map[info->p_x][info->p_y - 1] == 'E')
	{
		if (game->coinnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_check_d_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x][info->p_y + 1] == '1')
		return (0);
	if (map[info->p_x][info->p_y + 1] == '0')
		return (1);
	if (map[info->p_x][info->p_y + 1] == 'C')
	{
		game->coinnum -= 1;
		return (1);
	}
	if (map[info->p_x][info->p_y + 1] == 'E')
	{
		if (game->coinnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

void	free_all_components(t_game *game)
{
	mlx_destroy_image(game->mlx, game->backgroud);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->peng);
	mlx_destroy_window(game->mlx, game->win);
	allfree(game->info->map);
	free(game->info);
}
