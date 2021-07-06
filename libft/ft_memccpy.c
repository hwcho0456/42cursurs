/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:55:12 by hcho              #+#    #+#             */
/*   Updated: 2020/12/27 10:51:00 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)src + i) == (unsigned char)c)
		{
			*((unsigned char *)dest + i) = (unsigned char)c;
			return (dest + i + 1);
		}
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (0);
}
