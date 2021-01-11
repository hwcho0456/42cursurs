/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_real_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:10:30 by hcho              #+#    #+#             */
/*   Updated: 2021/01/11 17:41:42 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_inf(double f)
{
	if ((*(unsigned long long *)&f & 0x7FF0000000000000) == 0x7FF0000000000000)
	{
		if (*(unsigned long long *)&f == 0x7FF0000000000000)
			return (3); // +inf
		else if (*(unsigned long long *)&f == 0xFFF0000000000000)
			return (2); // -inf
		else
			return (1); // -nan
	}
	return (0);
}

void	ft_round(double *f, t_op *opt)
{
	double	d;
	int		exp;
	double	fp;

	d = (*f < 0) ? -(*f) : *f;
	exp = 0;
	while (d > 10.00000000000000000000 && ++exp >= 0)
		d = d / 10.0000000000000000000;
	fp = 1.00000000000000000000;
	while (d < 1.00000000000000000000)
	{
		d = d * 10.00000000000000000000;
		fp = fp / 10.00000000000000000000;
		exp--;
	}
	while (--exp >= 0)
		d = (d - (char)d) * 10.00000000000000000000;
	while (--exp >= -opt->prec - 2)
	{
		d = (d - (char)d) * 10.00000000000000000000;
		fp = fp / 10.00000000000000000000;
	}
	if ((char)d >= 5)
		*f = (*f < 0) ? *f - (10 - (char)d) * fp : *f + (10 - (char)d) * fp; 
}
