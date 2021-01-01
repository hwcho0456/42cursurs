/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:41:53 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 20:35:21 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = 0;
	i = 0;
	j = 0;
	while (*(src + s_len))
		s_len++;
	while (*(dst + i) && i < size)
		i++;
	while (*(src + j) && i + j + 1 < size)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i != size)
		*(dst + i + j) = 0;
	return (i + s_len);
}
