/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 17:35:45 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

static long double			g_bias = 0.00000000000000006L;
static unsigned long long	g_sc = 0x8000000000000000;

int							get_enumlen(double f, t_op *opt, int dp, int exp)
{
	int	num_len;

	num_len = 0;
	while (f >= 10.0)
	{
		f = f / 10.0;
		exp += 1;
	}
	while (f != 0.0 && (int)(f + g_bias) == 0)
	{
		f = f * 10.0;
		exp -= 1;
	}
	f = f - (int)(f + g_bias);
	num_len += 1;
	num_len = (opt->prec != 0 || opt->sharp == 1) ? num_len + 1 : num_len;
	while (dp < opt->prec)
	{
		f = f * 10.0;
		f = f - (int)(f + g_bias);
		num_len += 1;
		dp += 1;
	}
	num_len = (exp >= 100 || exp <= 100) ? num_len + 5 : num_len + 4;
	return (num_len);
}

void						put_epadding(double f, t_op *opt, int *cnt)
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
		num_len = get_enumlen(f, opt, 0, 0);
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

void						put_eintnum(long double *f, int *exp, int *cnt)
{
	char	digit;

	while (*f >= 10.0)
	{
		*f = *f / 10.0;
		*exp += 1;
	}
	while (*f != 0.0 && (int)(*f + g_bias) == 0)
	{
		*f = *f * 10.0;
		*exp -= 1;
	}
	digit = ((int)((*f) + g_bias) % 10) + '0';
	*f = *f - (int)((*f) + g_bias);
	write(1, &digit, 1);
	*cnt += 1;
}

static void					put_exp(int exp, int *cnt)
{
	char digit;

	if (exp >= 100 || exp <= -100)
	{
		digit = (exp > 0) ? exp / 100 + '0' : '0' - exp / 100;
		exp = exp % 100;
		write(1, &digit, 1);
		*cnt += 1;
	}
	digit = (exp > 0) ? exp / 10 + '0' : '0' - exp / 10;
	write(1, &digit, 1);
	digit = (exp > 0) ? exp % 10 + '0' : '0' - exp % 10;
	write(1, &digit, 1);
	*cnt += 2;
}

void						put_enum(double f,
		long double d, t_op *opt, int *cnt)
{
	int		dp;
	char	digit;
	int		exp;

	if (is_inf(f))
	{
		(is_inf(f) == 1) ? write(1, "nan", 3) : write(1, "inf", 3);
		*cnt += 3;
		return ;
	}
	d = (d < 0) ? -d : d;
	exp = 0;
	put_eintnum(&d, &exp, cnt);
	(opt->prec > 0 || opt->sharp == 1) ? write(1, ".", 1) : 0;
	*cnt += (opt->prec > 0 || opt->sharp == 1) ? 3 : 2;
	dp = -1;
	while (++dp < opt->prec)
	{
		digit = ((int)(10.0 * d + g_bias) % 10) + '0';
		d = 10.0 * d - (int)(10.0 * d + g_bias);
		write(1, &digit, 1);
		*cnt += 1;
	}
	(exp >= 0) ? write(1, "e+", 2) : write(1, "e-", 2);
	put_exp(exp, cnt);
}
