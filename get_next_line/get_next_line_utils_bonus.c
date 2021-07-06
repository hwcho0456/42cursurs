/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:51:08 by hcho              #+#    #+#             */
/*   Updated: 2020/12/30 20:52:31 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

char		*ft_strjoinfree(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (0);
	k = -1;
	while (++k < i)
		*(str + k) = *(s1 + k);
	k = -1;
	while (++k < j)
		*(str + i + k) = *(s2 + k);
	*(str + i + k) = 0;
	free((char *)s1);
	return (str);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}
