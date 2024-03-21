/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_vaildator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:20:46 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/03/20 16:19:26 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	validate_end_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	validate_first_last_line(char *map)
{
	int	cnt;
	int	first_wall_idx;

    first_wall_idx = 0;
	cnt = counting_str_length(map);
	while (map[first_wall_idx])
	{
		if (map[first_wall_idx] == '1')
			break ;
		first_wall_idx++;
	}
	if (map[first_wall_idx] != '1' && map[cnt - 1] != '1')
		print_error("Error : No Wall\n");
}

int	check_all_spaces(char *map)
{
	int	i;
	int	flag_button;

	i = 0;
	flag_button = 1;
	while (map[i])
	{
		if (map[i] != ' ')
			flag_button = 0;
		i++;
	}
	return (flag_button);
}

void	checking_wall(char **map)
{
	int	i;
	int	end_line;

    i = -1;
	end_line = 0;
	while (map[end_line])
		end_line++;
	// 첫 번째 줄과 마지막 줄이 유효한 벽인지 확인
	if (validate_end_line(map[0]) || validate_end_line(map[end_line - 1]))
		print_error("Error : Invaild Wall\n");
	while (map[++i])
	{
		if (check_all_spaces(map[i]) == 1)
			continue ;
		validate_first_last_line(map[i]);
	}
}