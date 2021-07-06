/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:12:36 by hcho              #+#    #+#             */
/*   Updated: 2021/07/05 18:20:05 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

void	putpid(char *msg, pid_t pid)
{
	char	digit[5];
	int		i;

	while (*msg)
	{
		write(1, msg, 1);
		msg++;
	}
	i = -1;
	while (++i < 5)
	{
		digit[4 - i] = pid % 10 + '0';
		pid /= 10;
	}
	write(1, &digit, 5);
	write(1, "\n", 1);
}

pid_t	readpid(char *s)
{
	int	pid;
	int	i;

	pid = 0;
	i = -1;
	while (*(s + (++i)))
	{
		if (*(s + i) < '0' || *(s + i) > '9')
			exit(0);
		pid = 10 * pid + *(s + i) - '0';
	}
	return (pid);
}

void	safe_kill(pid_t pid, int sig)
{
	usleep(40);
	if (kill(pid, sig) < 0)
		exit(0);
}
