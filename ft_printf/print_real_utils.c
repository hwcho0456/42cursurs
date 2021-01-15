/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_real_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/15 17:19:55 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

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

void	ft_fround(double *f, t_op *opt)
{
	double	d;
	int		exp;
	double	fp;

	d = (*f < 0) ? -(*f) : *f;
	exp = 0;
	while (d >= 10.00000000000000000000 && ++exp >= 0)
		d = d / 10.0000000000000000000;
	fp = 1.00000000000000000000;
	while (d < 1.00000000000000000000)
	{
		d = d * 10.00000000000000000000;
		fp = fp / 10.00000000000000000000;
		exp--;
	}
	while (--exp >= 0)
		d = (d - (char)d) * 10.00000000000000000000;
	while (--exp >= -opt->prec - 2)
	{
		d = (d - (char)d) * 10.00000000000000000000;
		fp = fp / 10.00000000000000000000;
	}
	if ((char)d >= 5)
		*f = (*f < 0) ? *f - (10 - (char)d) * fp : *f + (10 - (char)d) * fp;
}

void	ft_eround(double *f, t_op *opt)
{
	double	d;
	int		exp;
	double	fp;

	d = (*f < 0) ? -(*f) : *f;
	exp = 0;
	while (d >= 10.00000000000000000000 && ++exp >= 0)
		d = d / 10.0000000000000000000;
	while (d < 1.00000000000000000000)
	{
		d = d * 10.00000000000000000000;
		exp--;
	}
	fp = 1.00000000000000000000;
	while (exp != 0)
	{
		fp = (exp > 0) ? fp * 10.00000000000000000000 : fp / 10.00000000000000000000;
		exp = (exp > 0) ? exp - 1 : exp + 1;
	}
	while (--exp >= -opt->prec - 1)
	{
		d = (d - (char)d) * 10.00000000000000000000;
		fp = fp / 10.00000000000000000000;
	}
	if ((char)d >= 5)
		*f = (*f < 0) ? *f - (10 - (char)d) * fp : *f + (10 - (char)d) * fp; 
}

int		get_gprec(double f, t_op *opt)
{
	int	p;
	int	x;

	if (is_inf(f))
		return (1);
	p = opt->prec;
	if (opt->dot == 0 || opt->prec == 0)
		p = (opt->dot == 0) ? 6 : 1;
	x = 0;
	while (f >= 10.0)
	{
		f = f / 10.0;
		x++;
	}
	while (f < 1.0 && f != 0)
	{
		f = f * 10.0;
		x--;
	}
	opt->prec = (p > x && x >= -4) ? p - (x + 1) : p - 1;
	return ((p > x && x >= -4) ? 1 : 0);
}

void	find_omitprec(double f, t_op *opt, int form)
{
	double	d;
	int		exp;
	int		omitcnt;

	d = (f > 0) ? f : -f;
	if (form)
	{
		exp = 0;
		while (d >= 10.0)
		{
			d = d / 10.0;
			exp++;
		}
		while (exp > 0)
		{
			d = (d - (char)d) * 10.0;
			exp--;
		}
		omitcnt = 0;
		while (--exp > -opt->prec - 2)
		{
			omitcnt = ((char)d == 0) ? omitcnt + 1 : 0;
			d = (d - (char)d) * 10.0;
		}
		opt->prec -= omitcnt;
	}
	else
	{
		while (d >= 10.0)
			d = d / 10.0;
		while (d < 1.0 && d != 0.0)
			d = d * 10.0;
		d = (d - (char)d) * 10.0;
		omitcnt = 0;
		exp = 0;
		while (--exp > -opt->prec - 1)
		{
			omitcnt = ((char)d == 0) ? omitcnt + 1 : 0;
			d = (d - (char)d) * 10.0;
		}
		opt->prec -= omitcnt;
	}
	return ;
}
