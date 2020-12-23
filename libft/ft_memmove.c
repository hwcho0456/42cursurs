/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:54:43 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 16:16:33 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest <= src)
	{
		i = -1;
		while (++i < n)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	}
	else
	{
		i = n;
		while (i-- > 0)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	}
	return (dest);
}
