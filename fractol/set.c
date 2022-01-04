/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:18:11 by hcho              #+#    #+#             */
/*   Updated: 2022/01/04 20:11:34 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const int SET_NUMBER = 3;
const char SET_NAME[3][11] = {"Mandelbrot", "Julia", "Burningship"};

void check_valid_set(const char *s, t_vars *vars)
{
    int i;
    int j;
    int len;

    i = -1;
    while (++i < SET_NUMBER)
    {
        j = 0;
        while (*(SET_NAME[i] + j) && *(s + j) && *(SET_NAME[i] + j) == *(s + j)) 
            j++;
        if (*(SET_NAME[i] + j) != *(s + j))
            continue;
        len = j;
        vars->set_number = i;
        vars->set_name = (char *)malloc(sizeof(char) * (len + 1));
        if (!vars->set_name)
            break ;
        j = -1;
        while (*(SET_NAME[i] + (++j)))
            *(vars->set_name + j) = *(SET_NAME[i] + j);
        *(vars->set_name + j) = 0;
        return;
    }
    vars->set_number = -1;
}

int iter_Mandelbrot(int x, int y, t_vars *vars)
{
    t_complex z;
    t_complex c;
    t_complex z2;
    double w;
    int depth;

    c.re = vars->x_pos + (x - vars->x_res / 2) / vars->zoom;
    c.im = vars->y_pos + (y - vars->y_res / 2) / vars->zoom;
    z2.re = 0;
    z2.im = 0;
    w = 0;
    depth = -1;
    while (++depth < vars->limit_depth && z2.re + z2.im < 4.0f)
    {
        z.re = z2.re - z2.im + c.re;
        z.im = w - z2.re -z2.im + c.im;
        z2.re = z.re * z.re;
        z2.im = z.im * z.im;
        w = (z.re + z.im) * (z.re + z.im);
    }
    return (depth);
}

int iter_Julia(int x, int y, t_vars *vars)
{
    t_complex z;
    t_complex c;
    t_complex z2;
    double w;
    int depth;
   
    c.re = vars->julia_x;
    c.im = vars->julia_y;
    z2.re = vars->x_pos + (x - vars->x_res / 2) / vars->zoom;
    z2.im = vars->y_pos + (y - vars->y_res / 2) / vars->zoom;
    w = 0;
    depth = -1;
    while (++depth < vars->limit_depth && z2.re + z2.im < 4.0f)
    {
        z.re = z2.re - z2.im + c.re;
        z.im = w - z2.re - z2.im + c.im;
        z2.re = z.re * z.re;
        z2.im = z.im * z.im;
        w = (z.re + z.im) * (z.re + z.im); 
    }
    return (depth);
}

int iter_Burningship(int x, int y, t_vars *vars)
{
    t_complex z;
    t_complex c;
    t_complex z2;
    double w;
    int depth;

    c.re = vars->x_pos + (x - vars->x_res / 2) / vars->zoom;
    c.im = vars->y_pos + (y - vars->y_res / 2) / vars->zoom;
    z2.re = 0;
    z2.im = 0;
    w = 0;
    depth = -1;
    while (++depth < vars->limit_depth && z2.re + z2.im < 4.0f)
    {
        z.re = z2.re - z2.im + c.re;
        if (z.re < 0)
            z.re *= -1;
        z.im = w - z2.re -z2.im + c.im;
        if (z.im < 0)
            z.im *= -1;
        z2.re = z.re * z.re;
        z2.im = z.im * z.im;
        w = (z.re + z.im) * (z.re + z.im);
    }
    return (depth);
}
