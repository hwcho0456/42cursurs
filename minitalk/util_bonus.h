/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:03:17 by hcho              #+#    #+#             */
/*   Updated: 2021/07/05 17:49:30 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <time.h>

void	putpid(char *msg, pid_t pid);
pid_t	readpid(char *s);
void	safe_kill(pid_t pid, int sig);
#endif
