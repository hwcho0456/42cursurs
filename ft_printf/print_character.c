/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:47 by hcho              #+#    #+#             */
/*   Updated: 2021/01/15 17:08:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_integer_utils.h"

void		print_c(va_list ap, t_op *opt, int *cnt)
{
	char	c;
	int		padding;

	c = (char)va_arg(ap, int);
	padding = opt->width - 1;
	*cnt += 1;
	(opt->minus == 1) ? write(1, &c, 1) : 0;
	while (padding > 0)
	{
		write(1, " ", 1);
		*cnt += 1;
		padding--;
	}
	(opt->minus == 0) ? write(1, &c, 1) : 0;
}

static void	put_string(char *str, t_op *opt, int str_len, int padding)
{
	if (opt->minus == 1)
	{
		if (str)
			write(1, str, str_len);
		else if (opt->dot == 0 || opt->prec >= 6)
			write(1, "(null)", 6);
	}
	while (--padding >= 0)
		write(1, " ", 1);
	if (opt->minus == 0)
	{
		if (str)
			write(1, str, str_len);
		else if (opt->dot == 0 || opt->prec >= 6)
			write(1, "(null)", 6);
	}
}

void		print_s(va_list ap, t_op *opt, int *cnt)
{
	char	*str;
	int		padding;
	int		str_len;

	str = va_arg(ap, char *);
	str_len = 0;
	if (str)
	{
		while (*(str + str_len))
			str_len++;
		str_len = (opt->dot == 1 && opt->prec < str_len) ? opt->prec : str_len;
	}
	if (str)
		padding = opt->width - str_len;
	else
		padding = opt->width - (opt->dot == 1 && opt->prec < 6 ? 0 : 6);
	if (str)
		*cnt += str_len;
	else if (opt->dot == 0 || opt->prec >= 6)
		*cnt += 6;
	*cnt += (padding > 0) ? padding : 0;
	put_string(str, opt, str_len, padding);
}

void		print_p(va_list ap, t_op *opt, int *cnt)
{
	unsigned long long	n;

	g_hex = "0123456789abcdef";
	opt->space = (opt->plus == 1) ? 0 : opt->space;
	if (opt->minus == 1 || opt->dot == 1)
		opt->zero = 0;
	n = va_arg(ap, unsigned long long);
	if (opt->minus == 1 || opt->zero == 1)
	{
		put_psign(n, opt, cnt);
		(opt->minus == 1) ? put_pnum(n, opt, cnt) : put_ppadding(n, opt, cnt);
		(opt->minus == 1) ? put_ppadding(n, opt, cnt) : put_pnum(n, opt, cnt);
	}
	else
	{
		put_ppadding(n, opt, cnt);
		put_psign(n, opt, cnt);
		put_pnum(n, opt, cnt);
	}
}

void		print_percent(int *cnt)
{
	*cnt += 1;
	write(1, "%", 1);
}
