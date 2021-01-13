/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/13 18:24:43 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

void	print_f(va_list ap, t_op *opt, int *cnt)
{
	double		f;

	if (opt->dot == 0)
		opt->prec = 6;
	f = va_arg(ap, double);
	if (opt->len == 0 && is_inf((float)f) == 0 && (float)f != 0.0)
		f = (float)f;
	if (is_inf(f) != 0)
		opt->zero = 0;
	else if (f != 0)
		ft_fround(&f, opt);
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
	double		f;

	if (opt->dot == 0)
		opt->prec = 6;	
	f = va_arg(ap, double);
	if (opt->len == 0 && is_inf((float)f) == 0 && (float)f != 0.0)
		f = (float)f;
	if (is_inf(f) != 0)
		opt->zero = 0;
	else if (f != 0)
		ft_eround(&f, opt);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_esign(f, opt, cnt);
		(opt->minus == 1) ? put_enum(f, opt, cnt) : put_epadding(f, opt, cnt);
		(opt->minus == 1) ? put_epadding(f, opt, cnt) : put_enum(f, opt, cnt);
	}
	else
	{
		put_epadding(f, opt, cnt);
		put_esign(f, opt, cnt);
		put_enum(f, opt, cnt);
	}
}
void	print_g(va_list ap, t_op *opt, int *cnt)
{
	double		f;
	int			form;

	f = va_arg(ap, double);
	f = (!opt->len && is_inf((float)f) == 0 && (float)f != 0.0) ? (float)f : f;
	form = get_gprec(f, opt);
	opt->zero =  (is_inf(f) != 0) ? 0 : opt->zero;
	if (is_inf(f) == 0 && f != 0)
		form ? ft_fround(&f, opt) : ft_eround(&f, opt);
	(opt->sharp == 0) ? find_omitprec(f, opt, form) : 0;
	if (opt->minus == 1 || opt->zero == 1)
	{
		form ? put_fsign(f, opt, cnt) : put_esign(f, opt, cnt);
		if (opt->minus == 1)
			form  ? put_fnum(f, opt, cnt) : put_enum(f, opt, cnt);
		form ? put_fpadding(f, opt, cnt) : put_epadding(f, opt, cnt);
		if (opt->minus == 0) 
			form  ? put_fnum(f, opt, cnt) : put_enum(f, opt, cnt);
	}
	else
	{
		form ? put_fpadding(f, opt, cnt) : put_epadding(f, opt, cnt);
		form ? put_fsign(f, opt, cnt) : put_esign(f, opt, cnt);
		form ? put_fnum(f, opt, cnt) : put_enum(f, opt, cnt);
	}
}
