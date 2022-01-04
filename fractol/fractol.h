/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:04:34 by hcho              #+#    #+#             */
/*   Updated: 2022/01/04 18:25:50 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define X_RESOLUTION 800
#define Y_RESOLUTION 600
#define BASIC_ZOOM 200
#define KEY_PRESS   2
# define MOUSE_UP   4
# define MOUSE_DOWN 5
#define W 13
#define A 0
#define S 1
#define D 2
#define R 15
#define C 8
#define ESC 53
#include "mlx_beta/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_img
{
	void		*img_ptr;
	unsigned int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     x_res;
    int     y_res;
    double     x_pos;
    double     y_pos;
    double   zoom;
    int     limit_depth;
    int     color;
    int     set_number;
    char    *set_name;
    double    julia_x;
    double     julia_y;
    t_img   img;
}				t_vars;

typedef struct s_complex {
    double re;
    double im;
}              t_complex;

void check_valid_set (const char *s, t_vars *vars);
void invalid_param_error();
int key_press (int keycode, t_vars *vars);
int zoom(int button, int x, int y, t_vars *vars);
int iter_Mandelbrot (int x, int y, t_vars *vars);
int iter_Julia (int x, int y, t_vars *vars);
int iter_Burningship (int x, int y, t_vars *vars);
void draw_fractal(t_vars *vars);

#endif
