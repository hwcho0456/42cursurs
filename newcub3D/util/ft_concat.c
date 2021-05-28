/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:01:17 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 21:30:40 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char *ft_concat(char *s1, char c, char *s2)
{
	char *str;
	int len;
	int i;
	int j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	j = ft_strlen(s1);
	while (++i < j)
		*(str + i) = *(s1 + i);
	*(str + i) = c;
	while (++i < len)
		*(str + i) = *(s2 + i - j - 1);
	str[len] = 0;
	free(s1);
	printf("concat : \n%s\n", str);
	return (str);
}
