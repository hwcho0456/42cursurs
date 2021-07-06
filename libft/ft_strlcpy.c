/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:59:35 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 17:03:17 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	s_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	s_len = 0;
	i = 0;
	while (*(src + s_len))
		s_len++;
	if (size == 0)
		return (s_len);
	while (*(src + i) && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (s_len);
}
