/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:02:46 by hcho              #+#    #+#             */
/*   Updated: 2022/01/03 18:27:30 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void invalid_param_error(void) 
{
    printf("Usage: ./fractol [Madelbrot | Julia [opt_number] | Burningship]\n");
    exit(0);
}
