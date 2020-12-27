/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:30:12 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 22:52:08 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_cur(int n, int fd)
{
	char digit;

	if (n == 0)
		return ;
	ft_cur(n / 10, fd);
	digit = '0' + n % 10;
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (fd == -1)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_cur(-(n / 10), fd);
		digit = '0' - n % 10;
		write(fd, &digit, 1);
	}
	else
	{
		ft_cur(n / 10, fd);
		digit = '0' + n % 10;
		write(fd, &digit, 1);
	}
}
