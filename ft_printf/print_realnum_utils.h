/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:42:50 by hcho              #+#    #+#             */
/*   Updated: 2021/01/13 17:24:58 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_REALNUM_UTILS_H
# define PRINT_REALNUM_UTILS_H

#include "ft_printf.h"

int		is_inf(double f);
void	ft_fround(double *f, t_op *opt);
void	ft_eround(double *f, t_op *opt);
int		get_gprec(double f, t_op *opt);
void	find_omitprec(double f, t_op *opt, int form);
int		get_fnumlen(double f, t_op *opt, int *dp, int *exp);
void	put_fpadding(double f, t_op *opt, int *cnt);
void	put_fsign(double f, t_op *opt, int *cnt);
void	put_fintnum(double *f, int *cnt);
void	put_fnum(double f, t_op *opt, int *cnt);
int		get_enumlen(double f, t_op *opt, int *dp, int *exp);
void	put_epadding(double f, t_op *opt, int *cnt);
void	put_esign(double f, t_op *opt, int *cnt);
void	put_eintnum(double *f, int *exp, int *cnt);
void	put_enum(double f, t_op *opt, int *cnt);
#endif
