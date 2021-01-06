/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:47 by hcho              #+#    #+#             */
/*   Updated: 2021/01/06 16:45:27 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_s(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_p(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_n(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_percent(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
