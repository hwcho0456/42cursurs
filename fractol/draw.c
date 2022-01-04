/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:01:25 by hcho              #+#    #+#             */
/*   Updated: 2022/01/04 17:31:12 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int shift[3][15] = {{0x1e5965, 0x781f19, 0x474a51, 0x922b3e, 0x8a6642, 0x522129, 0x60628c, 0x1e213d, 0xa98307, 0x49678d, 0x47402e, 0xb5b8b1, 0xf3da0b, 0x20603d, 0x1f3a3d}, {0xf5d033, 0xb8b799, 0x734222, 0x4e5754, 0xd84b20, 0xc2b078, 0xf3da0b, 0x193737, 0x23282b, 0xc6a664, 0x5b3a29, 0x6c6960, 0x425754, 0x1e2460, 0x9d9101}, {0x3d642d, 0x781f19, 0x2d572c, 0x102c54, 0xcb2821, 0xff7514, 0xe5be01, 0xcac4b0, 0xff2301, 0xeae6ca, 0x1f3438, 0x4e5452, 0xec7c26, 0x3e3b32, 0xb44c43}};

void draw_fractal(t_vars *vars)
{
    int x;
    int y;
    int size_l;
    int depth;

    size_l = vars->img.size_l / (vars->img.bpp / 8);
    vars->limit_depth = 10 * log(vars->zoom);
    y = -1;
    while (++y < vars->y_res)
    {
        x = -1;
        while (++x < vars->x_res)
        {           
            if (vars->set_number == 0)
                depth = iter_Mandelbrot(x, y, vars);
            else if (vars->set_number == 1)
                depth = iter_Julia(x, y, vars);
            else 
                depth = iter_Burningship(x, y, vars);
            if (depth == vars->limit_depth)
                vars->img.data[y * size_l + x] = shift[vars->color][14];
            else
                vars->img.data[y * size_l + x] = shift[vars->color][((int)(700*log(depth)) % 70) / 14];
        }
    }
   mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
}
