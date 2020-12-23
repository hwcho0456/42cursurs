/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:41:17 by hcho              #+#    #+#             */
/*   Updated: 2020/12/23 18:21:49 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (n == 0)
		return (0);
	len = 0;
	while ((*(s1 + len) == *(s2 + len)) && *(s1 + len) && *(s2 + len))
	{
		if (len == n - 1)
			return (*(s1 + len) - *(s2 + len));
		len++;
	}
	return (*(s1 + len) - *(s2 + len));
}
