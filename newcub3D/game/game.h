/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:48:27 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 21:18:17 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "../key/key.h"
#include "../util/util.h"
#include "../mlx.h"

typedef	struct	s_game 
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*title;    
	int		x_res;
    int		y_res;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor;
	int		celling;
	char	*rawmap;
	int		row;
	int		col;
	int		**map;
}				t_game;

t_game	*init_game(void);
void	save_game(t_game *game);
void	play_game(t_game *game);
void	print_game(t_game *game);
void	set_game(t_game *game, char *line, int *status);
void    load_map(t_game *game, char *mapname);
void    check_mapname(char *mapname);
int     check_mapc(char *str);
void	read_mapc(t_game *game, char *line);

#endif
