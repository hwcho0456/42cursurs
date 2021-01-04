/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/04 19:53:24 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_int_len(unsigned long long int n)
{
	size_t					num_len;
	unsigned long long int	i;

	num_len = 1;
	i = n;
	while ((i = i/10) != 0)
		num_len++;
	return (num_len);
}

static void		put_int(unsigned long long int n, t_op *opt, size_t *span, int *cnt)
{
	char	digit;
	int		

	if (n == 0)
	{
		while (opt->spec >= 0)
		{
			write(1, "0", 1);
			*cnt += 1;
			*span += 1;
			opt->spec--;
		}
	}
	put_int(n/10, opt, span, cnt);
	digit = n%10 + '0';
	write(1, &digit, 1);
	*cnt += 1;
	opt->
}

void			print_d(va_list ap, t_op *opt, int *cnt)
{
	size_t			span;
	long long int	n;

	if (opt->len > 0)
		n = (opt->len == 1) ? va_arg(ap, long int) : va_arg(ap, long long int);
	else if (opt->len < 0)
		n = (opt->len == -1) ? va_arg(ap, short int) : va_arg(ap, signed char);
	else
		n = va_arg(ap, int);
	span = get_int_len(n);
	if ((n >= 0 && (opt->plus == 1 || opt->space == 1)) || n < 0)
		span++;
	if (opt->minus == 0)
	{
		while (
	}
	put_int((unsigned long long int)(-n), opt, &span, cnt);
}

void	print_i(va_list ap, t_op *opt, int *cnt)
{
}
void	print_u(va_list ap, t_op *opt, int *cnt)
{
}
void	print_x(va_list ap, t_op *opt, int *cnt)
{
}
void	print_X(va_list ap, t_op *opt, int *cnt)
{
}
