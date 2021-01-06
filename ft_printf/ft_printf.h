/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:33:35 by hcho              #+#    #+#             */
/*   Updated: 2021/01/06 12:58:42 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_op
{
	char	minus;
	char	plus;
	char	space;
	char	sharp;
	char	zero;
	int		width;
	int		prec;
	int		len;
}				t_op;

void			init_option(t_op *opt);
void			get_flag(const char *format, size_t *i, t_op *opt);
void			get_width(const char *format, va_list ap, size_t *i, t_op *opt);
void			get_prec(const char *format, va_list ap, size_t *i, t_op *opt);
void			get_length(const char *format, size_t *i, t_op *opt);
void			print_d(va_list ap, t_op *opt, int *cnt);
void			print_i(va_list ap, t_op *opt, int *cnt);
void			print_u(va_list ap, t_op *opt, int *cnt);
void			print_x(va_list ap, t_op *opt, int *cnt);
void			print_X(va_list ap, t_op *opt, int *cnt);
void			print_c(va_list ap, t_op *opt, int *cnt);
void			print_s(va_list ap, t_op *opt, int *cnt);
void			print_p(va_list ap, t_op *opt, int *cnt);
void			print_n(va_list ap, t_op *opt, int *cnt);
void			print_percent(va_list ap, t_op *opt, int *cnt);
void			print_f(va_list ap, t_op *opt, int *cnt);
void			print_e(va_list ap, t_op *opt, int *cnt);
void			print_g(va_list ap, t_op *opt, int *cnt);
int				ft_printf(const char *format, ...);
#endif
