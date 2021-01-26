/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 14:45:35 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*g_hex;

void		put_ppadding(unsigned long long n, t_op *opt, int *cnt)
{
	int					padding;
	int					num_len;
	int					sign_len;
	unsigned long long	i;

	num_len = 1;
	i = n;
	while ((i /= 16) != 0)
		num_len++;
	num_len = (opt->dot == 1 && opt->prec == 0 && n == 0) ? 0 : num_len;
	num_len = (opt->prec > num_len) ? opt->prec : num_len;
	sign_len = (opt->plus == 1 || opt->space == 1) ? 1 : 0;
	padding = opt->width - num_len - sign_len - 2;
	if (opt->sharp == 1 && opt->zero == 1 && n != 0)
	{
		write(1, "0x", 2);
		*cnt += 2;
	}
	while (--padding >= 0)
	{
		(opt->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
		*cnt += 1;
	}
}

static void	put_pzero(unsigned long long n, t_op *opt, int *cnt)
{
	int					zero_len;
	int					num_len;
	unsigned long long	i;

	num_len = 1;
	i = n;
	while ((i /= 16) != 0)
		num_len++;
	zero_len = opt->prec - num_len;
	while (zero_len > 0)
	{
		*cnt += 1;
		write(1, "0", 1);
		zero_len--;
	}
}

static void	cur_pnum(unsigned long long n,
		unsigned long long o, t_op *opt, int *cnt)
{
	if (n == 0)
	{
		write(1, "0x", 2);
		*cnt += 2;
		put_pzero(o, opt, cnt);
		return ;
	}
	*cnt += 1;
	cur_pnum(n / 16, o, opt, cnt);
	write(1, &g_hex[n % 16], 1);
}

void		put_pnum(unsigned long long n, t_op *opt, int *cnt)
{
	cur_pnum(n / 16, n, opt, cnt);
	if (opt->dot == 1 && opt->prec == 0 && n == 0)
		return ;
	write(1, &g_hex[n % 16], 1);
	*cnt += 1;
}
