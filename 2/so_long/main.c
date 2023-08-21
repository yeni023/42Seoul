/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:04:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/08/20 21:49:35 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdio.h>

// typedef struct s_data
// {
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
// } t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// int main()
// {
//     void *mlx;
//     void *mlx_win;
//     t_data img;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
// }

// typedef struct s_vars {
//     void *mlx;
//     void *win;
// } t_vars;

// int key_hook(int keycode, t_vars *vars)
// {
//     printf("hello from key_hook!\n");
//     return (0);
// }

// int main()
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 640, 480, "so_long");
//     mlx_key_hook(vars.win, key_hook, &vars);
//     mlx_loop(vars.mlx);
// }

// int main()
// {
//     void *mlx;
//     void *img;
//     char *relative_path = "./image/peng.xpm";
//     int img_width;
//     int img_height;

//     mlx = mlx_init();
//     img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// }

typedef struct s_vars
{
    void *mlx;
    void *win;
} t_vars;

int close(int keycode, t_vars *vars)
{
    int i;
    
    i = keycode;
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
    mlx_hook(vars.win, 2, 1L << 0, close, &vars);
    mlx_loop(vars.mlx);
}