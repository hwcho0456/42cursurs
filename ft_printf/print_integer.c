/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/06 12:39:08 by hcho             ###   ########.fr       */
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

static void		put_span(t_op *opt, int n, size_t *span, int *cnt)
{
	int	i;

	i = 0;
	while (i < n)
	{
		(opt->zero == 1) ? write(1, "0", 1) : write(1, " ", 1);
		*span += 1;
		*cnt += 1;
		i++;
	}
}

static void		put_int(long long int n, t_op *opt, size_t *span, int *cnt)
{
	char	digit;

	if (n == 0)
	{
		while (*span < opt->spec)
		{
			*span += 1;
			*cnt += 1;
			write(1, "0", 1);
		}
	}
	*cnt += 1;
	*span += 1;
	cur(n / 10, opt, span, cnt);
	digit = n % 10 + '0';
	write(1, &digit, 1);
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
	span = 0;
		if (n < 0)
			write(1, "-", 1);
		else
			(opt->plus == 1) ? write(1, "+", 1) : write(1, " ", 1);
	}
}

void	print_i(va_list ap, t_op *opt, int *cnt)
{
	return ;
}
void	print_u(va_list ap, t_op *opt, int *cnt)
{
	return ;
}
void	print_x(va_list ap, t_op *opt, int *cnt)
{
	return ;
}
void	print_X(va_list ap, t_op *opt, int *cnt)
{
	return ;
}
