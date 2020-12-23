/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho </var/mail/hcho>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:47:06 by hcho              #+#    #+#             */
/*   Updated: 2020/12/22 18:10:32 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	ft_min(size_t a, size_t b)
{
	return ((a > b) ? b : a);
}

char			*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (*(s + i))
		i++;
	if (start >= i)
		return (0);
	sub = (char *)malloc(sizeof(char) * (ft_min(i - start, len + 1)));
	if (!sub)
		return (0);
	i = -1;
	while (*(s + start + (++i)) && i < len)
			*(sub + i) = *(s + start + i);
	*(sub + i) = 0;
	return (sub);
}
