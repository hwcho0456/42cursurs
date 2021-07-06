/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:37:39 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 20:59:04 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_res(t_game *game, char **option)
{
	if (option[1] && option[2] && !option[3])
	{
	   if (is_num(option[1]) && is_num(option[2]))
	   {
		   game->x_res = ft_atoi(option[1]);
		   game->y_res = ft_atoi(option[2]);
		   return ;
	   }
	}
	perror("invalid resolution");
	exit(0);
}

static void	set_file(t_game *game, char **option)
{
    if (option[1] && !option[2])
    {
		if (ft_strcmp(option[0], "NO") == 0)
			game->north = ft_strdup(option[1]);
		else if (ft_strcmp(option[0], "SO") == 0)
            game->south = ft_strdup(option[1]);
		else if (ft_strcmp(option[0], "WE") == 0)
            game->west = ft_strdup(option[1]);
		else if (ft_strcmp(option[0], "EA") == 0)
            game->east = ft_strdup(option[1]);
		else 
            game->sprite = ft_strdup(option[1]);
		return ;
    }
    perror("invalid texture");
    exit(0);
}

static void	set_rgb(int *object, char **rgb)
{
	if (ft_strlen(rgb[0]) <= 3 && ft_strlen(rgb[1]) <= 3 && ft_strlen(rgb[2]) <= 3)
	{
		if (ft_atoi(rgb[0]) <= 255 && ft_atoi(rgb[1]) <= 255 && ft_atoi(rgb[2]) <= 255)
		{
			*object =  ft_atoi(rgb[0]) * 0x10000 + ft_atoi(rgb[1]) *0x100 + ft_atoi(rgb[2]);
		  	return ;	
		}
	}	
	perror("ivalid rgb");
	exit(0);
}

static void	set_color(t_game *game, char **option)
{
	char **rgb;

    if (option[1] && !option[2])
    {
		rgb = ft_split(option[1], ',');
		if (rgb[2] && !rgb[3])
		{
			if (is_num(rgb[0]) && is_num(rgb[1]) && is_num(rgb[2]))
			{
        		if (!ft_strcmp(option[0], "F"))
            		set_rgb(&game->floor, rgb);
				else	
					set_rgb(&game->celling, rgb);
				ft_wfree(rgb);
				return ;
			}
		}
    }
    perror("invalid color");
    exit(0);
}

void set_game(t_game *game, char *line, int *status)
{
	char **option;

	if (check_mapc(line))
	{
		*status = 1;
		read_mapc(game, line);
		return ;
	}
	option = ft_split(line, ' ');
	if (*status == 0)
	{
		if (ft_strcmp(option[0], "R") == 0)
			set_res(game, option);
		else if (ft_strcmp(option[0], "NO") == 0 || ft_strcmp(option[0], "SO") == 0 
				|| ft_strcmp(option[0], "WE") == 0|| ft_strcmp(option[0], "EA") == 0 
					|| ft_strcmp(option[0], "S") == 0)
			set_file(game, option);
		else if (ft_strcmp(option[0], "F") == 0 || ft_strcmp(option[0], "C") == 0)
			set_color(game, option);
		ft_wfree(option);
		return ;
	}
	perror("invalid option");
	exit(0);
}
