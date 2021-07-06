/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_realnum_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:42:50 by hcho              #+#    #+#             */
/*   Updated: 2021/01/26 17:27:56 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_REALNUM_UTILS_H
# define PRINT_REALNUM_UTILS_H

# include "ft_printf.h"

int		is_inf(double f);
void	ft_fround(long double *f, t_op *opt);
void	ft_eround(long double *f, t_op *opt);
int		get_gprec(double f, t_op *opt);
void	find_omitprec(long double d, t_op *opt, int exp, int omitcnt);
int		get_fnumlen(double f, t_op *opt, int dp, int exp);
void	put_fpadding(double f, t_op *opt, int *cnt);
void	put_fsign(double f, t_op *opt, int *cnt);
void	put_fintnum(long double *f, int *cnt);
void	put_fnum(double f, long double d, t_op *opt, int *cnt);
int		get_enumlen(double f, t_op *opt, int dp, int exp);
void	put_epadding(double f, t_op *opt, int *cnt);
void	put_eintnum(long double *f, int *exp, int *cnt);
void	put_enum(double f, long double d, t_op *opt, int *cnt);
#endif
