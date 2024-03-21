/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:37:41 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/03/20 12:09:26 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_color(char **tmp_split, int *arr)
{
	int	tmp_str;

	tmp_str = 0;
	while (tmp_split[tmp_str])
		tmp_str++;
	if (tmp_str != 3)
		print_error("Error\nrgb_color\n");
	tmp_str = 0;
	while (tmp_split[tmp_str])
	{
		arr[tmp_str] = set_atoi(tmp_split[tmp_str]);
		tmp_str++;
	}
}

static void	checking_rgb_invalid(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (!(tmp[i] == ',' || (tmp[i] >= '0' && tmp[i] <= '9') || \
			tmp[i] == '\n'))
			print_error("Error : Invaild rgb\n");
		i++;
	}
}

static void	input_rgb(char *tmp, int *cnt, int *arr, int *check)
{
    int		i;
    int		comma_num;
	char	**comma_split;

	i = 0;
	comma_num = 0;
    comma_split = parsing_str(tmp, ',');
	while (tmp[i])
	{
		if (tmp[i] == ',')
			comma_num++;
		i++;
	}
	if (comma_num >= 3)
		print_error("Error : comma\n");
	checking_rgb_invalid(tmp);
	if (!comma_split)
		print_error("Error : Invaild rgb\n");
	check_color(comma_split, arr);
	(*cnt)++;
	all_free(comma_split);
	*check = 1;
}

void	init_rgb(t_game *game)
{
	game->color->c_bit_rgb = (game->color->c_rgb[0] << 16) | \
		(game->color->c_rgb[1] << 8) | game->color->c_rgb[2];
	game->color->f_bit_rgb = (game->color->f_rgb[0] << 16) | \
		(game->color->f_rgb[1] << 8) | game->color->f_rgb[2];
}

void	setting_rgb(char *line, t_game *game, int *cnt)
{
    int		tmp_str;
	char	**tmp;
	char	*new_line;

	new_line = NULL;
	// 공백 기준으로 분할하여 tmp에 저장
	tmp = parsing_str(line, ' ');
	if (!tmp)
		print_error("Error : Invaild rgb\n");
	tmp_str = 0;
	// 분할된 문자열의 개수 확인
	while (tmp[tmp_str])
		tmp_str++;
	// 만약 분할된 문자열의 개수가 2이면, 2번째 문자열에서 줄바꿈 제거
	if (tmp_str == 2)
		new_line = remove_new_line(tmp[1]);
	if (!(str_ncompare(tmp[0], "F", counting_str_length(tmp[0]))) \
		&& tmp_str == 2 && game->color->f_valid == 0)
		input_rgb(new_line, cnt, game->color->f_rgb, \
		&(game->color->f_valid));
	else if (!(str_ncompare(tmp[0], "C", counting_str_length(tmp[0]))) \
		&& tmp_str == 2 && game->color->c_valid == 0)
		input_rgb(new_line, cnt, game->color->c_rgb, \
		&(game->color->c_valid));
	else
		print_error("Error : Invalid rgb\n");
	all_free(tmp);
	free(new_line);
}
