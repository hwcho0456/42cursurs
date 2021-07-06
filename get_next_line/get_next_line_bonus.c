/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:49:13 by hcho              #+#    #+#             */
/*   Updated: 2020/12/30 21:13:56 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static char		*get_save(char *save)
{
	char	*new_save;
	size_t	i;
	size_t	j;

	if (!save)
		return (0);
	i = 0;
	while (*(save + i) && *(save + i) != '\n')
		i++;
	if (!*(save + i))
	{
		free(save);
		return (0);
	}
	if (!(new_save = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	j = 0;
	while (*(save + i))
		*(new_save + (j++)) = *(save + (i++));
	*(new_save + j) = 0;
	free(save);
	return (new_save);
}

static char		*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save)
		return (0);
	while (*(save + i) && *(save + i) != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (*(save + i) && *(save + i) != '\n')
	{
		*(line + i) = *(save + i);
		i++;
	}
	*(line + i) = 0;
	return (line);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save[OPEN_MAX + 1];
	int				read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(save[fd], '\n') && read_len != 0)
	{
		if ((read_len = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		*(buf + read_len) = 0;
		save[fd] = ft_strjoinfree(save[fd], buf);
	}
	free(buf);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	return (read_len == 0) ? 0 : 1;
}
