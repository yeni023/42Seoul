/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_etc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:42:35 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 20:46:15 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void put_img(t_map *map, void *obj, int w, int h)
{
	mlx_put_image_to_window(map->mlx, map->win, obj, w, h);
}

void setting_img(t_map *map)
{
	int hei;
	int wid;
	int h64;
	int w64;

	hei = -1;
	while (++hei < map->height)
	{
		wid = -1;
		while (++wid < map->width)
		{
			w64 = wid * 64;
			h64 = hei * 64;
			put_img(map, map->obj->backgroud, w64, h64);
			if (map->map_line[hei * map->width + wid] == '1')
				put_img(map, map->obj->tree, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'C')
				put_img(map, map->obj->coin, w64, h64);
			if (map->map_line[hei * map->width + wid] == 'P')
				put_img(map, map->obj->peng, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'E')
				put_img(map, map->obj->exit, w64, h64);
		}
	}
}