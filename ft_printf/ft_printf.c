/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:51:46 by hcho              #+#    #+#             */
/*   Updated: 2021/01/09 13:03:21 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_type(const char c)
{
	const char *type = "diuxXcspfegn%";
	size_t	i;

	i = 0;
	while (*(type + i))
	{
		if (*(type + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static void	print_type(const char type, va_list ap, t_op *opt, int *cnt)
{
	if (type == 'd' || type == 'i')
		print_d(ap, opt, cnt);
	else if (type == 'u')
		print_u(ap, opt, cnt);
	else if (type == 'x')
		print_x(ap, opt, cnt);
	else if (type == 'X')
		print_X(ap, opt, cnt);	
	else if (type == 'c')
		print_c(ap, opt, cnt);	
	else if (type == 's')
		print_s(ap, opt, cnt);
	else if (type == 'p')
		print_p(ap, opt, cnt);
	else if (type == 'f')
		print_f(ap, opt, cnt);
	else if (type == 'e')
		print_e(ap, opt, cnt);	
	else if (type == 'g')
		print_g(ap, opt, cnt);
	else if (type == 'n')
		print_n(ap, opt, cnt);
	else if (type == '%')
		print_percent(cnt);
}

static int	process(const char *format, va_list ap, size_t *i, int *cnt)
{
	t_op	*opt;

	opt = (t_op *)malloc(sizeof(t_op));
	if (!opt)
		return (0);
	init_option(opt);
	get_flag(format, i, opt);
	get_width(format, ap, i, opt);
	if (*(format + *i) == '.')
	{
		*i += 1;
		opt->dot = 1;
		get_prec(format, ap, i, opt);
	}
	get_length(format, i, opt);
	if (is_type(*(format + *i)))
	{
		print_type(*(format + *i), ap, opt, cnt);
		free(opt);
		return (1);
	}
	free(opt);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		cnt;	
	
	va_start(ap, format);
	cnt = 0;
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;
			if (process(format, ap, &i, &cnt) == 0)
				return (-1);
		}
		else
		{
			write(1, format + i, 1);
			cnt++;
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}
