/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:06:44 by hcho              #+#    #+#             */
/*   Updated: 2020/12/22 15:28:50 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (*(big + i) && i < len)
	{
		if (*(big + i) == *little)
		{
			j = 0;
			while (*(little + j))
			{
				if (*(big + i + j) != *(little + j) || i + j >= len)
					break;
				j++;
			}
			if (!*(little + j))
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
