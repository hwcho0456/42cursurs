/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:35:09 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 21:33:43 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (*(s1 + i))
		i++;
	j = 0;
	while (*(s2 + j))
		j++;
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
	return (str);
}
