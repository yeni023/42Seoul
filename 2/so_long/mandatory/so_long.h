/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:12:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/18 21:21:31 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "../libft/libft.h"
#include "../libgnl/get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
# define DESTROY_NOTIFY 17

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct s_game
{
	t_map	*info;
	void	*mlx;
	void	*win;
	int		coinnum;
	void	*wall;
	void	*backgroud;
	void	*point;
	void	*coin;
	void	*exit;
	int		peng_cnt;
}	t_game;

typedef struct s_arg
{
	int	exit;
	int	food;
	int	point;
}	t_arg;

// key_func.c
int	exit_game(t_game *game);
int	key_pressed_w(t_game *game, t_map *info);
int	key_pressed_s(t_game *game, t_map *info);
int	key_pressed_a(t_game *game, t_map *info);
int	key_pressed_d(t_game *game, t_map *info);

// make_display.c
void	alloc_image(t_game	*game);
void	turn_on_pixel(t_game *game, void *image, int x, int y);
void	print_map(t_game *game, char **map);
int		key_pressed(int command, t_game *game);
void	start_game(t_game *game);

// command_vaildator.c
int		is_valid_w_key(char **map, t_map *info, t_game *game);
int		is_valid_s_key(char **map, t_map *info, t_game *game);
int		is_valid_a_key(char **map, t_map *info, t_game *game);
int		is_valid_d_key(char **map, t_map *info, t_game *game);
void	free_all_struct(t_game *game);

// check_path.c
char	**multifree(char **res);
char	**multidup(char **s, int x);
int		dfs(int x, int y, char **map, char find_char);
void	exit_to_wall(char **s);
int		valid_road(t_map info, t_arg arg, int x, int y);

// check_map.c
void	find_x_y(t_map *info);
void	surrounded_wall(t_map info);
void	valid_obj(char **map, t_arg *arg, t_map *info);
void	rectangle_map(char **map, int x, size_t y);
void	no_other_arg(char **map);

// main.c
int		ft_error(char *message);
void	parse_map(char *filename, t_map	*info);
char	*free_join(char	*s1, char *s2);
int		valid_map(t_map *info);
int		main(int argc, char **argv);

#endif