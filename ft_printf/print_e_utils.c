/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/13 18:27:26 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_realnum_utils.h"

int		get_enumlen(double f, t_op *opt, int *dp, int *exp)
{
	int	num_len;

	num_len = 0;
	while (f >= 10.00000000000000000000)
	{
		f = f / 10.0000000000000000000;
		*exp += 1;
	}
	while (f != 0.0 && f < 1.00000000000000000000)
	{
		f = f * 10.00000000000000000000;
		*exp -= 1;
	}
	f = f - (char)f;
	num_len += 1;
	num_len = (opt->prec != 0 || opt->sharp == 1) ? num_len + 1 : num_len;
	while (*dp < opt->prec)
	{
		f = f * 10.00000000000000000000;
		f = f - (char)f;
		num_len += 1;
		*dp += 1;
	}
	num_len = (*exp >= 100 || *exp <= 100) ? num_len + 5 : num_len + 4;
	return (num_len);
}
void	put_epadding(double f, t_op *opt, int *cnt)
{
	int	num_len;
	int	exp;
	int sign_len;
	int padding;
	int dp;

	if (is_inf(f))
		num_len = 3;
	else
	{
		f = (f < 0) ? -f : f;
		exp = 0;
		dp = 0;
		num_len = get_enumlen(f, opt, &dp, &exp);
	}
	if (is_inf(f))
		sign_len = (is_inf(f) == 3 && opt->plus == 0 && opt->space == 0) ? 0 : 1;
	else
		sign_len = (!(f < 0) && opt->plus == 0 && opt->space == 0) ? 0 : 1;
	padding = opt->width - num_len - sign_len + 1;
	while (--padding > 0)
	{
		(opt->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
		*cnt += 1;
	}
}

void	put_esign(double f, t_op *opt, int *cnt)
{
	int sign;
	const unsigned long long signcheck = 0x8000000000000000;

	if (is_inf(f))
		sign = (is_inf(f) == 3) ? 1 : -1; 
	else
		sign = ((*(unsigned long long *)&f & signcheck) == signcheck) ? -1 : 1;
	if (sign == -1 || opt->plus == 1 || opt->space == 1)
	{
		if (sign == -1)
			write(1, "-", 1);
		else
			(opt->plus == 1) ? write(1, "+", 1) : write(1, " ", 1);
		*cnt += 1;
	}
}

void	put_eintnum(double *f, int *exp, int *cnt)
{
	char	digit;

	while (*f >= 10.00000000000000000000)
	{
		*f = *f / 10.0000000000000000000;
		*exp += 1;
	}
	while (*f != 0.0 && *f < 1.00000000000000000000)
	{
		*f = *f * 10.0000000000000000000;
		*exp -= 1;
	}
	digit = ((char)(*f) % 10) + '0';
	*f = *f - (char)(*f);
	write(1, &digit, 1);
	*cnt += 1;
}

void	put_enum(double f, t_op *opt, int *cnt)
{
	int	dp;
	char digit;
	int exp;

	if (is_inf(f))
	{
		(is_inf(f) == 1) ? write(1, "nan", 3) : write(1, "inf", 3);
		*cnt += 3;
		return ;
	}
	f = (f < 0) ? -f : f;
	exp = 0;
	put_eintnum(&f, &exp, cnt);
	(opt->prec > 0 || opt->sharp == 1) ? write(1, ".", 1) : 0;
	*cnt += (opt->prec > 0 || opt->sharp == 1) ? 1 : 0;
	dp = -1;
	while (++dp < opt->prec)
	{
		f = f * 10.00000000000000000000;
		digit = ((char)f % 10) + '0';
		f = f - (char)f;
		write(1, &digit, 1);
		*cnt += 1;
	}
	(exp >= 0) ? write(1, "e+", 2) : write(1, "e-", 2);
	*cnt += 2;
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
