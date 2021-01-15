/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/15 16:51:19 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_dpadding(long long n, t_op *opt, int *cnt)
{
	int			padding;
	int			num_len;
	int			sign_len;
	long long	i;

	num_len = 1;
	i = n;
	while ((i /= 10) != 0)
		num_len++;
	num_len = (opt->dot == 1 && opt->prec == 0 && n == 0) ? 0 : num_len;
	num_len = (opt->prec > num_len) ? opt->prec : num_len;
	sign_len = (n < 0 || opt->plus == 1 || opt->space == 1) ? 1 : 0;
	padding = opt->width - num_len - sign_len;
	while (padding > 0)
	{
		(opt->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
		*cnt += 1;
		padding--;
	}
}

void		put_dsign(long long n, t_op *opt, int *cnt)
{
	if (n < 0 || opt->plus == 1 || opt->space == 1)
	{
		*cnt += 1;
		if (n < 0)
			write(1, "-", 1);
		else
			(opt->plus == 1) ? write(1, "+", 1) : write(1, " ", 1);
	}
}

static void	put_dzero(long long n, t_op *opt, int *cnt)
{
	int			zero_len;
	int			num_len;
	long long	i;

	num_len = 1;
	i = n;
	while ((i /= 10) != 0)
		num_len++;
	zero_len = opt->prec - num_len;
	while (zero_len > 0)
	{
		*cnt += 1;
		write(1, "0", 1);
		zero_len--;
	}
}

static void	cur_dnum(long long n, long long o, t_op *opt, int *cnt)
{
	char	digit;

	if (n == 0)
	{
		put_dzero(o, opt, cnt);
		return ;
	}
	*cnt += 1;
	cur_dnum(n / 10, o, opt, cnt);
	digit = '0' + (n % 10);
	write(1, &digit, 1);
}

void		put_dnum(long long n, t_op *opt, int *cnt)
{
	char	digit;

	if (n < 0)
	{
		*cnt += 1;
		cur_dnum(-(n / 10), n, opt, cnt);
		digit = '0' - (n % 10);
		write(1, &digit, 1);
	}
	else
	{
		if (opt->dot == 1 && opt->prec == 0 && n == 0)
			return ;
		*cnt += 1;
		cur_dnum(n / 10, n, opt, cnt);
		digit = '0' + (n % 10);
		write(1, &digit, 1);
	}
}
