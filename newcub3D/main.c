/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:37:53 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 20:36:21 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util/util.h"
#include "game/game.h"

int		main(int argc, char *argv[])
{
	t_game	*game;
		
	if (argc == 1 || argc > 3 || (argc == 3 && ft_strcmp(argv[2], "--save")))
	{
		perror("wrong number of arguments");
		exit(0);
	}
	game = init_game();
	load_map(game, argv[1]);
	if (argc == 3)
		save_game(game);
	print_game(game);
	play_game(game);
}
