/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:32:21 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 21:32:23 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void read_mapc(t_game *game, char *line)
{
	if (!game->rawmap)
	{
		game->row++;
		if (game->col < ft_strlen(line))
			game->col = ft_strlen(line);
		if ((game->rawmap = ft_strdup(line)))
			return ;
	}
	else
	{
		game->row++;
		if (game->col < ft_strlen(line))
			game->col = ft_strlen(line);
		if ((game->rawmap = ft_concat(game->rawmap, '\n', line)))
			return ;
	}
	perror("map reading failed");
	exit(0);
}

void load_map(t_game *game, char *mapname)
{
	char	*text;
	char	**line;
	int		i;
	int		status;

	check_mapname(mapname);
	if (!(text = read_file(mapname)))
	{
		perror("cannot read file");
		exit(0);
	}
	line = ft_split(text, '\n');
	status = 0;
	i = -1;
	while (line[++i])
	{
		if (status == 0 && is_onlyspace(line[i]))
			continue ;
		set_game(game, line[i], &status);
	}
	ft_wfree(line);
	free(text);
}
