/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/07/05 16:28:44 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int				g_flag;
pid_t			g_client;
unsigned char	g_char;

void			ft_handler(int sig)
{
	if (g_flag <= 16)
		g_client = 2 * g_client + (sig - SIGUSR1);
	else if (g_flag % 8 != 0)
		g_char = 2 * g_char + (sig - SIGUSR1);
	else
	{
		g_char = 2 * g_char + (sig - SIGUSR1);
		write(1, &g_char, 1);
		if (g_char != 0)
			g_char = 0;
		else
		{
			putpid("\ntransmission: ", g_client);
			g_flag = -1;
			g_client = 0;
		}
	}
	g_flag += 1;
}

int				main(void)
{
	putpid("server PID: ", getpid());
	g_flag = 0;
	g_client = 0;
	g_char = 0;
	signal(SIGUSR1, (void *)ft_handler);
	signal(SIGUSR2, (void *)ft_handler);
	while (1)
	{
	}
	return (0);
}
