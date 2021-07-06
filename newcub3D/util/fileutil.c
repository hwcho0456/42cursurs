/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:02:44 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 14:26:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int filelen(char *filename)
{
	int len;
	int fd;
	char buf;

	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	len = 0;
	while (read(fd, &buf, 1))
		len++;
	close(fd);
	return len;
}

char *read_file(char *filename)
{
	int len;
	int fd;
	char *buf;

	if (!(len = filelen(filename)))
	   return (0);
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!(fd = open(filename, O_RDONLY)))
		return (0);
	read(fd, buf, len + 1);
	*(buf + len) = 0;
	return (buf);
}
