/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:47 by hcho              #+#    #+#             */
/*   Updated: 2021/01/07 15:43:54 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_integer_utils.h"

void	print_c(va_list ap, t_op *opt, int *cnt)
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
void	print_s(va_list ap, t_op *opt, int *cnt)
{
	char	*str;
	int		padding;
	int		str_len;

	str = va_arg(ap, char *);
	str_len = 0;
	while (*(str + str_len))
		str_len++;
	str_len = (opt->dot == 1 && opt->prec < str_len) ? opt->prec : str_len;
	if (!str)
	{
		str = "(null)";
		str_len = 6;
	}
	padding = opt->width - str_len;
	*cnt += str_len;
	(opt->minus == 1) ? write(1, str, str_len) : 0;
	while (padding > 0)
	{
		write(1, " ", 1);
		*cnt += 1;
		padding--;
	}
	(opt->minus == 0) ? write(1, str, str_len) : 0;
}
void	print_p(va_list ap, t_op *opt, int *cnt)
{
	opt->prec = 12;
	opt->sharp = 1;
	opt->len = 2;
	print_x(ap, opt, cnt);
}
void	print_n(va_list ap, int *cnt)
{
	int	*n;

	n = va_arg(ap, int *);
	*n = *cnt;
}
void	print_percent(int *cnt)
{
	*cnt += 1;
	write(1, "%", 1);
}
