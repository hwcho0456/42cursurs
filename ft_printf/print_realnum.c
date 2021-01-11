/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/11 17:50:59 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

void	print_f(va_list ap, t_op *opt, int *cnt)
{
	double		f;

	if (opt->dot == 0)
		opt->prec = opt->len == 0 ? 6 : 15;
	f = (opt->len == 1) ? va_arg(ap, double) : (float)va_arg(ap, double);
	if (is_inf(f) != 0)
		opt->zero = 0;
	else
		ft_round(&f, opt);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_fsign(f, opt, cnt);
		(opt->minus == 1) ? put_fnum(f, opt, cnt) : put_fpadding(f, opt, cnt);
		(opt->minus == 1) ? put_fpadding(f, opt, cnt) : put_fnum(f, opt, cnt);
	}
	else
	{
		put_fpadding(f, opt, cnt);
		put_fsign(f, opt, cnt);
		put_fnum(f, opt, cnt);
	}
}
void	print_e(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
void	print_g(va_list ap, t_op *opt, int *cnt)
{
	print_d(ap, opt, cnt);
}
