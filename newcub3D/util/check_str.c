/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:43:03 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 19:10:18 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int is_num(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

int is_onlyspace(char *str)
{
    int i;

    i = 0;
    while (*(str + i))
    {
        if (*(str + i) != ' ')
            return (0);
        i++;
    }
    return (1);
}
