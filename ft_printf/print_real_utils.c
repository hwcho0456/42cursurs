/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_real_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 17:09:22 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

static const long double	g_b = 0.00000000000000006L;

int		is_inf(double f)
{
	if ((*(unsigned long long *)&f & 0x7FF0000000000000) == 0x7FF0000000000000)
	{
		if (*(unsigned long long *)&f == 0x7FF0000000000000)
			return (3);
		else if (*(unsigned long long *)&f == 0xFFF0000000000000)
			return (2);
		else
			return (1);
	}
	return (0);
}

void	ft_fround(long double *f, t_op *opt)
{
	long double	d;
	int			exp;
	long double	fp;
	int			l;

	d = (*f < 0) ? -(*f) : *f;
	exp = 0;
	fp = 1.0;
	while (d >= 10.0 && ++exp >= 0)
		d = d / 10;
	while ((int)d == 0 && --exp >= -100000)
	{
		d = d * 10.0;
		fp = fp / 10.0;
	}
	while (--exp >= 0)
		d = (d - (int)(d + g_b)) * 10.0;
	while (--exp >= -opt->prec - 2)
	{
		l = (int)(d + g_b);
		d = (d - (int)(d + g_b)) * 10.0;
		fp = fp / 10.0;
	}
	if ((int)(d + g_b) > 5 || ((int)(d + g_b) == 5 && (l % 2 || opt->prec)))
		*f = (*f < 0) ? *f - 5 * fp : *f + 5 * fp;
}

void	ft_eround(long double *f, t_op *opt)
{
	long double	d;
	int			exp;
	long double	fp;
	int			l;

	d = (*f < 0) ? -(*f) : *f;
	exp = 0;
	fp = 1.0;
	while (d >= 10.0 && ++exp >= 0)
		d = d / 10.0;
	while ((int)d == 0 && --exp >= -100000)
		d = d * 10.0;
	while (exp != 0)
	{
		fp = (exp > 0) ? fp * 10.0 : fp / 10.0;
		exp = (exp > 0) ? exp - 1 : exp + 1;
	}
	while (--exp >= -opt->prec - 1)
	{
		l = (int)(d + g_b);
		d = (d - (int)(d + g_b)) * 10.0;
		fp = fp / 10.0;
	}
	if ((int)(d + g_b) > 5 || ((int)(d + g_b) == 5 && (l % 2 || opt->prec)))
		*f = (*f < 0) ? *f - 5 * fp : *f + 5 * fp;
}

int		get_gprec(double f, t_op *opt)
{
	long double	d;
	int			p;
	int			x;

	opt->prec = (opt->dot == 0) ? 6 : opt->prec;
	d = (f < 0) ? -f : f;
	if (is_inf(d))
		return (1);
	else if (d != 0)
		ft_eround(&d, opt);
	p = opt->prec;
	if (opt->dot == 0 || opt->prec == 0)
		p = (opt->dot == 0) ? 6 : 1;
	x = 0;
	while (d >= 10.0 && ++x >= 0)
		d = d / 10.0;
	while (d < 1.0 && d != 0)
	{
		d = d * 10.0;
		x--;
	}
	opt->prec = (p > x && x >= -4) ? p - (x + 1) : p - 1;
	return ((p > x && x >= -4) ? 1 : 0);
}

void	find_omitprec(long double d, t_op *opt, int exp, int omitcnt)
{
	d = (d < 0) ? -d : d;
	if (opt->form)
	{
		while (d >= 10.0 && ++exp >= 0)
			d = d / 10.0;
		while (exp > 0 && --exp >= -100000)
			d = (d - (char)(d + g_b)) * 10.0;
		while (--exp > -opt->prec - 2)
		{
			omitcnt = ((char)d == 0) ? omitcnt + 1 : 0;
			d = (d - (char)(d + g_b)) * 10.0;
		}
	}
	else
	{
		while (d >= 10.0 || (d < 1.0 && d != 0.0))
			d = (d >= 10.0) ? d / 10.0 : d * 10.0;
		d = (d - (char)(d + g_b)) * 10.0;
		while (--exp > -opt->prec - 1)
		{
			omitcnt = ((char)(d + g_b) == 0) ? omitcnt + 1 : 0;
			d = (d - (char)(d + g_b)) * 10.0;
		}
	}
	opt->prec -= omitcnt;
}
