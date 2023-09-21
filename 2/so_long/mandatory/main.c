/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:25:17 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/09/21 17:21:12 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		print_error("Error, The file extension is .ber\n");
}

void	parsing_map(char *filename, t_map	*info)
{
	int		fd;
	char	*line_map;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error, invalid fd");
	line_map = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (temp[0] == '\n')
			print_error("Error, devided map");
		line_map = free_join(line_map, temp);
	}
	info->map = ft_split(line_map, '\n');
	free(line_map);
	close(fd);
}

char	*free_join(char	*s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

int	valid_map(t_map *info)
{
	t_arg	arg;

	ft_memset(&arg, 0, sizeof(arg));
	surrounded_wall(*info);
	valid_obj(info->map, &arg, info);
	rectangle_map(info->map, info->x, info->y);
	no_other_arg(info->map);
	return (valid_road((*info), arg, -1, -1));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("Error, The file does not exist");
	arg_check(argv[1]);
	game.info = (t_map *)malloc(sizeof(t_map));
	parsing_map(argv[1], game.info);
	find_x_y(game.info);
	game.coinnum = valid_map(game.info);
	start_game(&game);
}
