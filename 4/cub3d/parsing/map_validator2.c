/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:03:29 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/03/20 12:41:51 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	checking_str(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

static void	check_diagonal_valid(char **map, int i, int j)
{
	if (map[i - 1] && checking_str(map[i - 1][j]))
		print_error("Error invalid map\n");
	else if (map[i - 1] && checking_str(map[i - 1][j - 1]))
		print_error("Error : invalid map\n");
	else if (map[i - 1] && checking_str(map[i - 1][j + 1]))
		print_error("Error : invalid map\n");
	else if (map[i] && checking_str(map[i][j - 1]))
		print_error("Error : invalid map\n");
	else if (map[i] && checking_str(map[i][j + 1]))
		print_error("Error : invalid map\n");
	else if (map[i + 1] && checking_str(map[i + 1][j]))
		print_error("Error : invalid map\n");
	else if (map[i + 1] && checking_str(map[i + 1][j - 1]))
		print_error("Error : invalid map\n");
	else if (map[i + 1] && checking_str(map[i + 1][j + 1]))
		print_error("Error : invalid map\n");
}

// 대각선으로 이어진 빈 공간이 있는지 확인
void	checking_map2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'S' \
				|| map[i][j] == 'N' || map[i][j] == 'E' \
				|| map[i][j] == 'W')
				check_diagonal_valid(map, i, j);
			j++;
		}
		i++;
	}
}
