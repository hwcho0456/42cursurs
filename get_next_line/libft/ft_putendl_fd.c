/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:25:08 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 22:49:52 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t i;

	if (!s || fd == -1)
		return ;
	i = 0;
	while (*(s + i))
	{
		write(fd, s + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}
