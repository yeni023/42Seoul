/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:09:58 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 15:43:48 by yeeunpar         ###   ########.fr       */
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
	map->obj->ld = mlx_xpm_file_to_image(map->mlx, "./textures/ld.xpm", &wd, &hg);
	// map->obj->tr = mlx_xpm_file_to_image(map->mlx, "./img/tr1.xpm", &wd, &hg);
	// map->obj->it = mlx_xpm_file_to_image(map->mlx, "./img/it.xpm", &wd, &hg);
	// map->obj->d1 = mlx_xpm_file_to_image(map->mlx, "./img/d2.xpm", &wd, &hg);
	map->obj->peng = mlx_xpm_file_to_image(map->mlx, "./textures/peng.xpm", &wd, &hg);
}
