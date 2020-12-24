/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:55:12 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 14:50:05 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n && *((unsigned char *)src + i))
	{
		if (*((unsigned char *)src + i) == (unsigned char)c)
		{
			*((unsigned char *)dest + i) = (unsigned char)c;
			return (dest + i + 1);
		}
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	}
	if (!*((unsigned char *)src + i))
		*((unsigned char *)dest + i) = 0;
	return (0);
}
