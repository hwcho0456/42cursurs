/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:15:52 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 12:16:05 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str+i))
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}
