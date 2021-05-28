/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:30:58 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 18:18:29 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

#include "../util/util.h"
#include "../mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_release	3
#define X_EVENT_KEY_EXIT	17

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_param{
	int	x;
}				t_param;

void			param_init(t_param *param);
int				key_press(int keycode, t_param *param);

#endif
