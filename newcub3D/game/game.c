/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:56:35 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 21:23:25 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*init_game(void)
{
	t_game *game;
	if(!(game = (t_game *)malloc(sizeof(t_game))))
		exit(0);
	game->x_res = 800;
	game->y_res = 600;
	game->row = 0;
	game->col = 0;
	game->rawmap = 0;
	if(!(game->title = ft_strdup("hcho's cub3D")))
		exit(0);
	return (game);
}

void	print_game(t_game *game)
{
	printf("resolution : %d %d\n", game->x_res, game->y_res);
	printf("north : %s\n", game->north);
	printf("south : %s\n", game->south);
	printf("west : %s\n", game->west);
	printf("east : %s\n", game->east);
	printf("sprite : %s\n", game->sprite);
	printf("floor color : %x\n", game->floor);
	printf("celling color : %x\n", game->celling);
	printf("row : %d\n", game->row);
	printf("col : %d\n", game->col);
	printf("rawmap : %s\n", game->rawmap);
}

void	play_game(t_game *game)
{
	t_param param;

    if (!(game->mlx_ptr = mlx_init()))
		exit(0);
    if(!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->x_res, game->y_res, game->title)))
		exit(0);
    mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(game->mlx_ptr);
}

void	save_game(t_game *game)
{
	if (!game)
		exit(0);
}
