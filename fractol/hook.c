/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 22:11:05 by hcho              #+#    #+#             */
/*   Updated: 2022/01/04 16:24:01 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_press(int keycode, t_vars *vars)
{
    if (keycode == R) 
    {
        vars->x_pos = 0;
        vars->y_pos = 0;
        vars->zoom = BASIC_ZOOM;
    }
    else if (keycode == W || keycode == A || keycode == S || keycode == D)
    {
        if (keycode == W)
            vars->y_pos -= 50 / vars->zoom;
        else if (keycode == A)
            vars->x_pos -= 50 / vars->zoom;
        else if (keycode == S)
            vars->y_pos += 50 / vars->zoom;
        else
            vars->x_pos += 50 / vars->zoom;
    }
    else if (keycode == C)
        vars->color  = (vars->color + 1) % 3;
    else if (keycode == ESC) 
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    draw_fractal(vars);
    return (0);
}

int zoom(int button, int x, int y, t_vars *vars)
{
    vars->x_pos += (x - vars->x_res / 2) / vars->zoom;
    vars->y_pos -= (y - vars->y_res / 2) / vars->zoom;
    if (button == MOUSE_UP)
        vars->zoom  *= 1.25;
    else if (button == MOUSE_DOWN)
        vars->zoom *= 0.8;
    draw_fractal(vars);
    return (0);
}
