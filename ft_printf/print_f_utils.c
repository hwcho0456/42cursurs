/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 16:15:08 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

static long double			g_bias = 0.00000000000000006L;
static unsigned long long	g_sc = 0x8000000000000000;

int							get_fnumlen(double f, t_op *opt, int dp, int exp)
{
	int	num_len;

	num_len = 0;
	while (f >= 10.0)
	{
		f = f / 10.0;
		exp += 1;
	}
	f = f - (int)(f + g_bias);
	num_len += 1;
	while (exp > 0)
	{
		f = (f - (int)(f + g_bias)) * 10.0;
		num_len++;
		exp -= 1;
	}
	num_len = (opt->prec != 0 || opt->sharp == 1) ? num_len + 1 : num_len;
	while (dp < opt->prec)
	{
		f = f * 10.0;
		f = f - (int)(f + g_bias);
		num_len += 1;
		dp += 1;
	}
	return (num_len);
}

void						put_fpadding(double f, t_op *opt, int *cnt)
{
	int	num_len;
	int sign_len;
	int sign;
	int padding;

	sign = ((*(unsigned long long *)&f & g_sc) == g_sc) ? -1 : 1;
	if (is_inf(f))
		num_len = 3;
	else
	{
		f = (f <= -0.0) ? -f : f;
		num_len = get_fnumlen(f, opt, 0, 0);
	}
	if (is_inf(f))
		sign_len = (is_inf(f) == 3 && !opt->plus && !opt->space) ? 0 : 1;
	else
		sign_len = (sign == -1 || opt->space == 1 || opt->plus == 1) ? 1 : 0;
	padding = opt->width - num_len - sign_len + 1;
	while (--padding > 0)
	{
		(opt->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
		*cnt += 1;
	}
}

void						put_fsign(double f, t_op *opt, int *cnt)
{
	int sign;

	if (is_inf(f))
		sign = (is_inf(f) == 3) ? 1 : -1;
	else
		sign = ((*(unsigned long long *)&f & g_sc) == g_sc) ? -1 : 1;
	if (sign == -1 || opt->plus == 1 || opt->space == 1)
	{
		if (sign == -1)
			write(1, "-", 1);
		else
			(opt->plus == 1) ? write(1, "+", 1) : write(1, " ", 1);
		*cnt += 1;
	}
}

void						put_fintnum(long double *f, int *cnt)
{
	int		exp;
	char	digit;

	exp = 0;
	while (*f >= 10.0)
	{
		*f = *f / 10.0;
		exp++;
	}
	digit = ((int)((*f) + g_bias) % 10) + '0';
	*f = *f - (int)((*f) + g_bias);
	write(1, &digit, 1);
	*cnt += 1;
	while (exp > 0)
	{
		*f = *f * 10.0;
		digit = ((int)((*f) + g_bias) % 10) + '0';
		*f = *f - (int)((*f) + g_bias);
		write(1, &digit, 1);
		*cnt += 1;
		exp--;
	}
}

void						put_fnum(double f,
		long double d, t_op *opt, int *cnt)
{
	int		dp;
	char	digit;

	if (is_inf(f))
	{
		(is_inf(f) == 1) ? write(1, "nan", 3) : write(1, "inf", 3);
		*cnt += 3;
		return ;
	}
	d = (d < 0) ? -d : d;
	put_fintnum(&d, cnt);
	(opt->prec > 0 || opt->sharp == 1) ? write(1, ".", 1) : 0;
	*cnt += (opt->prec > 0 || opt->sharp == 1) ? 1 : 0;
	dp = 0;
	while (dp < opt->prec)
	{
		d = d * 10.0;
		digit = (int)(d + g_bias) + '0';
		d = d - (int)(d + g_bias);
		write(1, &digit, 1);
		*cnt += 1;
		dp++;
	}
}
