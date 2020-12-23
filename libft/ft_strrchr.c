/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:58:43 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 18:27:21 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	ptr = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char)c)
			ptr = ((char *)s + i);
		i++;
	}
	return (ptr);
}
