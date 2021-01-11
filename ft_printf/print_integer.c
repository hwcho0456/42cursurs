/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/11 17:59:16 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_integer_utils.h"

void	print_d(va_list ap, t_op *opt, int *cnt)
{
	long long	n;

	opt->sharp = 0;
	opt->space = (opt->plus == 1) ? 0 : opt->space;
	opt->zero = (opt->minus == 1 || opt->dot == 1) ? 0 : opt->zero;
	if (opt->len > 0)
		n = (opt->len == 1) ? va_arg(ap, long) : va_arg(ap, long long);
	else if (opt->len < 0)
		n = (opt->len == -1) ? (short)va_arg(ap, int) : (char)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	if (opt->dot == 1 && opt->prec == 0 && n == 0)
		return ;
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_dsign(n, opt, cnt);
		(opt->minus == 1) ? put_dnum(n, opt, cnt) : put_dpadding(n, opt, cnt);
		(opt->minus == 1) ? put_dpadding(n, opt, cnt) : put_dnum(n, opt, cnt);
	}
	else
	{
		put_dpadding(n, opt, cnt);
		put_dsign(n, opt, cnt);
		put_dnum(n, opt, cnt);
	}
}

void	print_u(va_list ap, t_op *opt, int *cnt)
{
	unsigned long long	n;

	opt->sharp = 0;
	opt->plus = 0;
	opt->space = 0;
	if (opt->minus == 1 || opt->dot == 1)
		opt->zero = 0;
	if (opt->len ==  2)
		n = va_arg(ap, unsigned long long);	
	else if (opt->len ==  1)
		n = va_arg(ap, unsigned long);
	else if (opt->len ==  -1)
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (opt->len ==  -2)
		n = (unsigned char)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	if (opt->dot == 1 && opt->prec == 0 && n == 0)
		return ;
	(opt->minus == 1) ? put_unum(n, opt, cnt) : put_upadding(n, opt, cnt);
	(opt->minus == 1) ? put_upadding(n, opt, cnt) : put_unum(n, opt, cnt);
}
void	print_x(va_list ap, t_op *opt, int *cnt)
{
	unsigned long long	n;

	g_hex = "0123456789abcdef";
	opt->plus = 0;
	opt->space = 0;
	if (opt->minus == 1 || opt->dot == 1)
		opt->zero = 0;
	if (opt->len ==  2)
		n = va_arg(ap, unsigned long long);	
	else if (opt->len ==  1)
		n = va_arg(ap, unsigned long);
	else if (opt->len ==  -1)
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (opt->len ==  -2)
		n = (unsigned char)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	if (opt->dot == 1 && opt->prec == 0 && n == 0)
		return ;
	(opt->minus == 1) ? put_hnum(n, opt, cnt) : put_hpadding(n, opt, cnt);
	(opt->minus == 1) ? put_hpadding(n, opt, cnt) : put_hnum(n, opt, cnt);
}
void	print_X(va_list ap, t_op *opt, int *cnt)
{
	unsigned long long	n;

	g_hex = "0123456789ABCDEF";
	opt->plus = 0;
	opt->space = 0;
	if (opt->minus == 1 || opt->dot == 1)
		opt->zero = 0;
	if (opt->len ==  2)
		n = va_arg(ap, unsigned long long);	
	else if (opt->len ==  1)
		n = va_arg(ap, unsigned long);
	else if (opt->len ==  -1)
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (opt->len ==  -2)
		n = (unsigned char)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);	
	if (opt->dot == 1 && opt->prec == 0 && n == 0)
		return ;
	(opt->minus == 1) ? put_hnum(n, opt, cnt) : put_hpadding(n, opt, cnt);
	(opt->minus == 1) ? put_hpadding(n, opt, cnt) : put_hnum(n, opt, cnt);
}
