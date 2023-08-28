/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:12:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/28 16:45:58 by yeeunpar         ###   ########.fr       */
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

typedef struct s_obj
{
	void *ld;
	void *peng;
} t_obj;

typedef struct s_map
{
	int x;
	int y;
	int width;
	int height;
	int all_items;
	int c_items;
	int walk_cnt;
	char *map_line;
	void *mlx;
	void *win;
	struct s_obj *obj;
} t_map;

// check.c
void first_line_check(char *line, t_map *map);
void middle_line_check(char *line, t_map *map);
void last_line_check(char *line, t_map *map);
int map_size_check(int fd, t_map *map);
void map_init(t_map *map, char *argv);

// exit.c
int exit_game(t_map *game);
void print_error(char *msg);

// image_init.c
void obj_init(t_map *map);

// key.c
void free_all(char **split);
int press_key(int key_code, t_map *map);

// main.c
int fd_check(char *argv);
void arg_check(char *argv);
void objs(t_map *map);
int main(int argc, char **argv);

// mlx_etc.c
void put_img(t_map *map, void *obj, int w, int h);
void setting_img(t_map *map);

// move.c
void move_d(t_map *map);
void move_a(t_map *map);
void move_w(t_map *map);
void move_s(t_map *map);

#endif