/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:42:12 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 14:23:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	if (!dest && !src)
		return (0);
	i = -1;
	while (++i < n)
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	return (dest);
}
