/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:34:17 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 12:44:28 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void			param_init(t_param *param)
{
	param->x = 0;
}

int				key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
        param->x++;
    else if (keycode == KEY_S)
        param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
