/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho </var/mail/hcho>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:42:52 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 08:41:26 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	ft_strchr(const char *str, const int c)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	end = 0;
	while (*(s1 + end))
		end++;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	end--;
	while (end >= 0 && *(s1 + end) && ft_strchr(set, *(s1 + end)))
		end--;
	if (start > end)
		return (0);
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	i = -1;
	while (++i <= end - start)
		*(str + i) = *(s1 + start + i);
	*(str + i) = 0;
	return (str);
}
