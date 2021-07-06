/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 17:29:12 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

void		print_f(va_list ap, t_op *opt, int *cnt)
{
	double		f;
	long double d;

	opt->prec = (opt->dot == 0) ? 6 : opt->prec;
	opt->zero = (opt->minus == 1) ? 0 : opt->zero;
	f = va_arg(ap, double);
	d = (long double)f;
	if (is_inf(f) != 0)
		opt->zero = 0;
	else if (f != 0)
		ft_fround(&d, opt);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_fsign(d, opt, cnt);
		opt->minus == 1 ? put_fnum(f, d, opt, cnt) : put_fpadding(f, opt, cnt);
		opt->minus == 1 ? put_fpadding(f, opt, cnt) : put_fnum(f, d, opt, cnt);
	}
	else
	{
		put_fpadding(f, opt, cnt);
		put_fsign(f, opt, cnt);
		put_fnum(f, d, opt, cnt);
	}
}

void		print_e(va_list ap, t_op *opt, int *cnt)
{
	double		f;
	long double	d;

	opt->prec = (opt->dot == 0) ? 6 : opt->prec;
	opt->zero = (opt->minus == 1) ? 0 : opt->zero;
	f = va_arg(ap, double);
	d = (long double)f;
	if (is_inf(f) != 0)
		opt->zero = 0;
	else if (f != 0)
		ft_eround(&d, opt);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_fsign(f, opt, cnt);
		opt->minus == 1 ? put_enum(f, d, opt, cnt) : put_epadding(f, opt, cnt);
		opt->minus == 1 ? put_epadding(f, opt, cnt) : put_enum(f, d, opt, cnt);
	}
	else
	{
		put_epadding(f, opt, cnt);
		put_fsign(f, opt, cnt);
		put_enum(f, d, opt, cnt);
	}
}

static void	adjust_g_option(t_op *opt, double f, long double d)
{
	opt->zero = (opt->minus == 1) ? 0 : opt->zero;
	opt->width += ((f == 0.0 || f == -0.0) && opt->sharp == 0) ? 1 : 0;
	opt->zero = (is_inf(f) != 0) ? 0 : opt->zero;
	(is_inf(f) == 0 && opt->sharp == 0) ? find_omitprec(d, opt, 0, 0) : 0;
}

void		print_g(va_list ap, t_op *opt, int *cnt)
{
	double		f;
	long double	d;

	f = va_arg(ap, double);
	d = (long double)f;
	opt->form = get_gprec(f, opt);
	if (is_inf(f) == 0 && f != 0)
		opt->form ? ft_fround(&d, opt) : ft_eround(&d, opt);
	adjust_g_option(opt, f, d);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_fsign(f, opt, cnt);
		if (opt->minus == 1)
			opt->form ? put_fnum(f, d, opt, cnt) : put_enum(f, d, opt, cnt);
		opt->form ? put_fpadding(f, opt, cnt) : put_epadding(f, opt, cnt);
		if (opt->minus == 0)
			opt->form ? put_fnum(f, d, opt, cnt) : put_enum(f, d, opt, cnt);
	}
	else
	{
		opt->form ? put_fpadding(f, opt, cnt) : put_epadding(f, opt, cnt);
		put_fsign(f, opt, cnt);
		opt->form ? put_fnum(f, d, opt, cnt) : put_enum(f, d, opt, cnt);
	}
}

void		print_n(va_list ap, t_op *opt, int *cnt)
{
	if (opt->len == 2)
		*(va_arg(ap, long long *)) = (long long)*cnt;
	else if (opt->len == 1)
		*(va_arg(ap, long *)) = (long)*cnt;
	else if (opt->len == -1)
		*(va_arg(ap, short *)) = (short)*cnt;
	else if (opt->len == -2)
		*(va_arg(ap, char *)) = (char)*cnt;
	else
		*(va_arg(ap, int *)) = *cnt;
}
