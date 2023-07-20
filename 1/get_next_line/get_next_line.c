/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:29 by yeeunpar          #+#    #+#             */
/*   Updated: 2023/07/20 19:22:22 by yeeunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		cnt;
	char	*tmp_pointer;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (0);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp_pointer = backup;
		backup = ft_strjoin(tmp_pointer, buf);
		if (!backup)
			return (NULL);
		free(tmp_pointer);
		tmp_pointer = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_extract_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	res = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!res)
		return (NULL);
	if (res[0] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_extract_line(line);
	return (line);
}
