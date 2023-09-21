/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:54 by donghyk2          #+#    #+#             */
/*   Updated: 2023/09/21 14:17:48 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	alloc_image(t_game	*game)
{
	int	width;
	int	height;

	game->backgroud = mlx_xpm_file_to_image(game->mlx, \
	"./textures/backgroud.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
	"./textures/tree.xpm", &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx, \
	"./textures/coin.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, \
	"./textures/exit.xpm", &width, &height);
	game->peng = mlx_xpm_file_to_image(game->mlx, \
	"./textures/peng.xpm", &width, &height);
}

void	turn_on_pixel(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, \
	game->win, image, x * 64, y * 64);
}

void	print_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->info->x)
	{
		j = -1;
		while (++j < game->info->y)
		{
			turn_on_pixel(game, game->backgroud, j, i);
			if (map[i][j] == '0')
				;
			else if (map[i][j] == '1')
				turn_on_pixel(game, game->wall, j, i);
			else if (map[i][j] == 'C')
				turn_on_pixel(game, game->coin, j, i);
			else if (map[i][j] == 'E')
				turn_on_pixel(game, game->exit, j, i);
			else if (map[i][j] == 'P')
				turn_on_pixel(game, game->peng, j, i);
		}
	}
}

int	key_pressed(int command, t_game *game)
{
	int	works;

	works = 0;
	if (command == KEY_ESC)
		exit_game(game);
	if (command == KEY_W)
		works = key_pressed_w(game, game->info);
	if (command == KEY_S)
		works = key_pressed_s(game, game->info);
	if (command == KEY_A)
		works = key_pressed_a(game, game->info);
	if (command == KEY_D)
		works = key_pressed_d(game, game->info);
	if (works)
	{
		ft_putnbr_fd(++(game->peng_cnt), 1);
		write(1, "\n", 1);
		print_map(game, game->info->map);
	}
	return (1);
}

void	start_game(t_game *game)
{
	game->peng_cnt = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->info->y * 64, \
	game->info->x * 64, "so_long");
	alloc_image(game);
	print_map(game, game->info->map);
	mlx_key_hook(game->win, &key_pressed, game);
	mlx_hook(game->win, DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
