/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:12:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/22 16:52:06 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
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
	void	*peng;
	void	*coin;
	void	*exit;
	int		peng_cnt;
}	t_game;

typedef struct s_arg
{
	int	exit;
	int	food;
	int	peng;
}	t_arg;

// key_func.c
int		exit_game(t_game *game);
int		key_pressed_w(t_game *game, t_map *info);
int		key_pressed_s(t_game *game, t_map *info);
int		key_pressed_a(t_game *game, t_map *info);
int		key_pressed_d(t_game *game, t_map *info);

// make_window.c
int		key_pressed(int command, t_game *game);
void	alloc_image(t_game	*game);
void	print_map(t_game *game, char **map);
void	turn_on_pixel(t_game *game, void *image, int x, int y);
void	start_game(t_game *game);

// moving_key.c
int		is_check_w_key(char **map, t_map *info, t_game *game);
int		is_check_s_key(char **map, t_map *info, t_game *game);
int		is_check_a_key(char **map, t_map *info, t_game *game);
int		is_check_d_key(char **map, t_map *info, t_game *game);
void	free_all_components(t_game *game);

// check_path.c
int		dfs(int x, int y, char **map, char find_words);
int		valid_road(t_map info, t_arg arg, int x, int y);
char	**allfree(char **res);
char	**multidup(char **s, int x);
void	exit_to_wall(char **s);

// check_map.c
void	find_x_y(t_map *info);
void	surrounded_wall(t_map info);
void	valid_obj(char **map, t_arg *arg, t_map *info);
void	rectangle_map(char **map, int x, size_t y);
void	no_other_arg(char **map);

// main.c
int		valid_map(t_map *info);
int		main(int argc, char **argv);
void	parsing_map(char *filename, t_map	*info);
char	*free_join(char	*s1, char *s2);

// print_errors.c
int		print_error(char *message);

#endif
