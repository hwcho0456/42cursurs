/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:33:35 by hcho              #+#    #+#             */
/*   Updated: 2021/01/04 18:02:19 by hcho             ###   ########.fr       */
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
void			get_spec(const char *format, va_list ap, size_t *i, t_op *opt);
void			get_length(const char *format, size_t *i, t_op *opt);
int				ft_printf(const char *format, ...);
#endif
