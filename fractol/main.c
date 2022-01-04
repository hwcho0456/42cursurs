/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:33:16 by hcho              #+#    #+#             */
/*   Updated: 2022/01/04 18:40:38 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void init_vars(t_vars *vars)
{
    vars->x_res = X_RESOLUTION;
    vars->y_res = Y_RESOLUTION;
    vars->x_pos = 0;
    vars->y_pos = 0;
    vars->zoom = BASIC_ZOOM;
    vars->color = 0;
    vars->julia_x = -0.8;
    vars->julia_y = 0.156;
}

static void set_julia(const char *str, t_vars *vars)
{
    if (str[0] == '1' && str[1] == 0)
    {
        vars->julia_x = 0.285;
        vars->julia_y = 0.01;
    }
    else if (str[0] == '2' && str[1] == 0)
    {
        vars->julia_x = -0.70176;
        vars->julia_y = -0.3842;
    }
    else if (str[0] == '3' && str[1] == 0)
    {
        vars->julia_x = -0.835;
        vars->julia_y = -0.2321;
    }
    else if (str[0] == '4' && str[1] == 0)
    {
        vars->julia_x = -0.7269;
        vars->julia_y = 0.1889;
    }
}
int main(int argc, char *argv[])
{
   t_vars vars;

   if (argc == 1) 
        invalid_param_error();
   init_vars(&vars);
   check_valid_set(argv[1], &vars);
   if (vars.set_number == -1)
       invalid_param_error();
   if (vars.set_number == 1 && argc >= 3)
       set_julia(argv[2], &vars);
   vars.mlx = mlx_init();
   vars.win = mlx_new_window(vars.mlx, vars.x_res, vars.y_res, vars.set_name);
   vars.img.img_ptr = mlx_new_image(vars.mlx, vars.x_res, vars.y_res);
   vars.img.data = (unsigned int *)mlx_get_data_addr(vars.img.img_ptr, &vars.img.bpp, &vars.img.size_l, &vars.img.endian);
   draw_fractal(&vars);
   mlx_hook(vars.win, KEY_PRESS, 0, key_press, &vars);
   mlx_hook(vars.win, 4, 0, zoom, &vars);
   mlx_loop(vars.mlx);
}
