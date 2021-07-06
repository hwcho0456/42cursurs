/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:49:00 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 20:34:43 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static char *g_mapc = " 012NSWE";

void check_mapname(char *mapname)
{
	int		i;

	i = 0;
	while (*(mapname + i))
		i++;
	if (*(mapname + i - 1) == 'b')
		if (*(mapname + i - 2) == 'u')
			if (*(mapname + i - 3) == 'c')
				if (*(mapname + i - 4) == '.')
					return ;
	perror("invalid mapname");
	exit(0);
}

static int is_mapc(int c)
{
	int	i;

	i = 0;
	while(*(g_mapc + i))
	{
		if (c == *(g_mapc + i))
			return (1);
		i++;
	}
	return (0);
}

int	check_mapc(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!is_mapc(*(str + i)))
			return (0);
		i++;
	}
	return (1);
}
