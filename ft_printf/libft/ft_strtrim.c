/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:42:52 by hcho              #+#    #+#             */
/*   Updated: 2020/12/24 16:59:13 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static int		ft_strchr(const char *str, const int c)
{
	size_t i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static char		*ft_strdup(const char *str)
{
	char	*dst;
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(dst + i) = *(str + i);
		i++;
	}
	*(dst + i) = 0;
	return (dst);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	end--;
	while (end >= start && *(s1 + end) && ft_strchr(set, *(s1 + end)))
		end--;
	if (start > end || !*s1)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	i = -1;
	while (++i <= end - start)
		*(str + i) = *(s1 + start + i);
	*(str + i) = 0;
	return (str);
}
