/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:33:21 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 17:08:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int	ft_isspace(const char *str)
{
	if (*str >= '\t' && *str <= '\r')
		return (1);
	else if (*str == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	size_t		i;
	long long	num;
	long long	limit;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str + i))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
		sign = (*(str + i++) == '-') ? -1 : 1;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (sign * num);
		limit = num;
		if (sign == 1 && limit > (LLONG_MAX - *(str + i) + '0') / 10)
			return (-1);
		if (sign == -1 && limit > -((LLONG_MIN + *(str + i) - '0') / 10))
			return (0);
		num = 10 * num + (*(str + i) - '0');
		i++;
	}
	return (sign * num);
}
