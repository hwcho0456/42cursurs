/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/06 16:46:05 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_f(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_e(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_g(va_list ap, t_op *opt, int *cnt)
{
	print_g(ap, opt, cnt);
}
