/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:41:46 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 18:20:41 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	*ft_wcpy(const char *s, size_t start, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (*(s + start + i) && *(s + start + i) != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (*(s + start + i) && *(s + start + i) != c)
	{
		*(word + i) = *(s + start + i);
		i++;
	}
	*(word + i) = 0;
	return (word);
}

char		**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i;
	int		cnt;
	int		st;

	i = 0;
	cnt = 0;
	st = 0;
	while (*(s + i))
	{
		cnt = (*(s + i) != c && st == 0) ? cnt + 1 : cnt;
		st = (*(s + i++) == c) ? 0 : 1;
	}
	if (!(strs = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (0);
	cnt = -1;
	i = 0;
	st = 0;
	while (*(s + i))
	{
		(*(s + i) != c && st == 0) ? *(strs + (++cnt)) = ft_wcpy(s, i, c) : 0;
		st = (*(s + i++) == c) ? 0 : 1;
	}
	*(strs + (++cnt)) = 0;
	return (strs);
}
