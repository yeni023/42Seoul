/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:53:18 by yeeunpar          #+#    #+#             */
/*   Updated: 2024/03/20 12:00:14 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	checking_line(char *line, int line_len, t_game *game)
{
	int	i;

	i = -1;
	while (++i < line_len)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ' \
			|| line[i] == '\n')
			continue ;
		else if (line[i] == 'N' || line[i] == 'S' || \
			line[i] == 'W' || line[i] == 'E')
			game->player_cnt++;
		else
			return (0);
	}
	return (1);
}

// 주어진 라인에서 방향과 RGB 값 확인
static void	check_dir_rgb(char *line, t_game *game, int *cnt)
{
	char	**tmp;

	tmp = parsing_str(line, ' '); // 공백 기준 분할
	if (tmp == (void *)0 || tmp[0] == (void *)0)
		print_error("Error: Failed to split dir or rgb string\n");
	if (line[0] == '\n' && !(line[1]))
	{
		all_free(tmp);
		return ;
	}
	// tmp[0]과 F 또는 c를 확인하고 일치하지 않다면 setting_rgb 호출
	else if (!(str_ncompare(tmp[0], "F", 1)) || \
		!(str_ncompare(tmp[0], "C", 1)))
		setting_rgb(line, game, cnt);
	// tmp[0]과 NO, SO, WE, EA를 비교하고 일치하면 check_direction 호출
	else if (!(str_ncompare(tmp[0], "NO", 2)) || \
		!(str_ncompare(tmp[0], "SO", 2)) || \
		!(str_ncompare(tmp[0], "WE", 2)) || \
		!(str_ncompare(tmp[0], "EA", 2)))
		check_direction(line, game, cnt);
	else
		print_error("Error : Invalid dir or rgb\n");
	all_free(tmp);
}

static int	checking_map(char **line, char **map_buf, t_game *game)
{
	if (checking_line(*line, counting_str_length(*line), game) == 1)
	{
		*map_buf = ft_strjoin_gnl(*map_buf, *line);
		return (0);
	}
	else
	{
		free(*map_buf);
		free(*line);
		*map_buf = NULL;
		*line = NULL;
		return (1);
	}
}

int	cnting_line_str(char *line)
{
	int	i;

	i = 0;
    if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

//지도의 데이터 확인 (유효성 검사)
void	check_map_data(t_game *game)
{
    int		cnt;
	char	*map_buf;
	char	*line;

    cnt = 0;
	map_buf = NULL;
	line = NULL;
	while (42)
	{
		line = get_next_line(game->file_fd);
		if (!line)
			break ;
		if (cnt <= 5)
		{
			check_dir_rgb(line, game, &cnt);
		}
		else
			if (checking_map(&line, &map_buf, game) == 1)
				print_error("Error : Invalid input map\n");
		free(line);
		line = NULL;
	}
	close(game->file_fd);
	game->map = map_buf;
	free(line);
}
