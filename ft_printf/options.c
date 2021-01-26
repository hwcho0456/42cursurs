/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:05:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 17:05:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_option(t_op *opt)
{
	opt->minus = 0;
	opt->plus = 0;
	opt->space = 0;
	opt->sharp = 0;
	opt->zero = 0;
	opt->dot = 0;
	opt->width = 0;
	opt->prec = 0;
	opt->len = 0;
	opt->form = 0;
}

void			get_flag(const char *format, size_t *i, t_op *opt)
{
	while (*(format + *i))
	{
		if (*(format + *i) == '-')
			opt->minus = 1;
		else if (*(format + *i) == '+')
			opt->plus = 1;
		else if (*(format + *i) == ' ')
			opt->space = 1;
		else if (*(format + *i) == '#')
			opt->sharp = 1;
		else if (*(format + *i) == '0')
			opt->zero = 1;
		else
			break ;
		*i += 1;
	}
}

void			get_width(const char *format, va_list ap, size_t *i, t_op *opt)
{
	while (*(format + *i) >= '0' && *(format + *i) <= '9')
	{
		opt->width = 10 * opt->width + *(format + *i) - '0';
		*i += 1;
	}
	if (*(format + *i) == '*')
	{
		opt->width = va_arg(ap, int);
		*i += 1;
	}
	if (opt->width < 0)
	{
		opt->minus = 1;
		opt->width = -opt->width;
	}
}

void			get_prec(const char *format, va_list ap, size_t *i, t_op *opt)
{
	while (*(format + *i) >= '0' && *(format + *i) <= '9')
	{
		opt->prec = 10 * opt->prec + *(format + *i) - '0';
		*i += 1;
	}
	if (*(format + *i) == '*')
	{
		opt->prec = va_arg(ap, int);
		*i += 1;
	}
	if (opt->prec < 0)
	{
		opt->prec = 0;
		opt->dot = 0;
	}
}

void			get_length(const char *format, size_t *i, t_op *opt)
{
	if (*(format + *i) == 'l')
	{
		opt->len += 1;
		*i += 1;
		if (*(format + *i) == 'l')
		{
			opt->len += 1;
			*i += 1;
		}
	}
	else if (*(format + *i) == 'h')
	{
		opt->len -= 1;
		*i += 1;
		if (*(format + *i) == 'h')
		{
			opt->len -= 1;
			*i += 1;
		}
	}
}
