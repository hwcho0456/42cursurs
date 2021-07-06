/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:10:05 by hcho              #+#    #+#             */
/*   Updated: 2021/07/05 18:17:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

int	main(int argc, char *argv[])
{
	pid_t			server;
	pid_t			client;
	size_t			i;
	unsigned char	c;

	if (argc != 3)
		return (0);
	server = readpid(argv[1]);
	client = getpid();
	putpid("client PID: ", client);
	i = 0x1LL << (sizeof(pid_t) * 4 + 1);
	while ((i >>= 1) > 0)
		(client & i) ? safe_kill(server, SIGUSR2) : safe_kill(server, SIGUSR1);
	while (*argv[2])
	{
		i = 0x1 << 8;
		c = *argv[2];
		while ((i >>= 1) > 0)
			(c & i) ? safe_kill(server, SIGUSR2) : safe_kill(server, SIGUSR1);
		argv[2]++;
	}
	i = 0;
	while (++i <= 8)
		safe_kill(server, SIGUSR1);
	return (0);
}
