/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:24:05 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 20:25:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static void	ft_cur(char *str, size_t cnt, int n)
{
	if (n == 0)
		return ;
	ft_cur(str, cnt - 1, n / 10);
	*(str + cnt) = '0' + n % 10;
}

char		*ft_itoa(int n)
{
	size_t	cnt;
	int		i;
	char	*str;

	cnt = (n < 0) ? 2 : 1;
	i = n;
	while ((i /= 10) != 0)
		cnt++;
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	*(str + cnt) = 0;
	if (n < 0)
	{
		*str = '-';
		ft_cur(str, cnt - 2, -(n / 10));
		*(str + cnt - 1) = '0' - n % 10;
	}
	else
	{
		ft_cur(str, cnt - 2, n / 10);
		*(str + cnt - 1) = '0' + n % 10;
	}
	return (str);
}
