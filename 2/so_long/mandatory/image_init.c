/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:09:58 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 20:26:47 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void obj_init(t_map *map)
{
	int wd;
	int hg;

	map->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!map->obj)
		return;
	map->obj->backgroud = mlx_xpm_file_to_image(map->mlx, "./textures/backgroud.xpm", &wd, &hg);
	map->obj->coin = mlx_xpm_file_to_image(map->mlx, "./textures/coin.xpm", &wd, &hg);
	map->obj->tree = mlx_xpm_file_to_image(map->mlx, "./textures/tree.xpm", &wd, &hg);
	map->obj->exit = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm", &wd, &hg);
	map->obj->peng = mlx_xpm_file_to_image(map->mlx, "./textures/peng.xpm", &wd, &hg);
}
