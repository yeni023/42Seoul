/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:19:46 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:53 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size_check(char const *str, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static int	ft_str_check(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	free_arr(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static char	**ft_too_many_lines(char **arr, char const *str, char c, int i)
{
	int	len;
	int	j;

	len = ft_str_check(str, c);
	arr[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr[i])
	{
		free_arr(arr, i);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		arr[i][j] = str[j];
		j++;
	}
	arr[i][j] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;

	if (!s)
		return (0);
	i = 0;
	size = ft_size_check(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split = ft_too_many_lines(split, s, c, i);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = 0;
	return (split);
}