/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:41:53 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 16:45:12 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

int	fd_check(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("open failed.\n");
	return (fd);
}

void	arg_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		print_error("not vaild extension -> <map_name>.ber\n");
}

void	objs(t_map *map)
{
	int	i;
	int	exits;
	int	p_start;

	i = 0;
	exits = 0;
	p_start = 0;
	while (map->map_line[i])
	{
		if (map->map_line[i] == 'C')
			map->all_items++;
		else if (map->map_line[i] == 'E')
			exits++;
		else if (map ->map_line[i] == 'P')
			p_start++;
		i++;
	}
	if (map->all_items < 1 || exits < 1 || p_start != 1)
		print_error("map error -> objets error");
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		print_error("argument error -> ./so_long <map_name>.ber\n");
	ft_memset(&map, 0, sizeof(t_map));
	arg_check(argv[1]);
	map_init(&map, argv[1]);
	objs(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 64, \
	map.height * 64, "so_long");
	obj_init(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}