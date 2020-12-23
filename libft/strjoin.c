/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho </var/mail/hcho>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:35:09 by hcho              #+#    #+#             */
/*   Updated: 2020/12/22 21:42:23 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t i;
	size_t j;
	size_t k;
	char *str;

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
   *(str + k) = 0;
	return (str);   
}
