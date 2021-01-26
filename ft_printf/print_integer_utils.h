/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/21 12:55:24 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INTEGER_UTILS_H
# define PRINT_INTEGER_UTILS_H
# include "ft_printf.h"

char	*g_hex;
char	*g_oct;
void	put_dpadding(long long n, t_op *opt, int *cnt);
void	put_dsign(long long n, t_op *opt, int *cnt);
void	put_dnum(long long n, t_op *opt, int *cnt);
void	put_upadding(unsigned long long n, t_op *opt, int *cnt);
void	put_unum(unsigned long long n, t_op *opt, int *cnt);
void	put_xpadding(unsigned long long n, t_op *opt, int *cnt);
void	put_xnum(unsigned long long n, t_op *opt, int *cnt);
void	put_opadding(unsigned long long n, t_op *opt, int *cnt);
void	put_onum(unsigned long long n, t_op *opt, int *cnt);
void	put_ppadding(unsigned long long n, t_op *opt, int *cnt);
void	put_pnum(unsigned long long n, t_op *opt, int *cnt);
void	put_psign(unsigned long long n, t_op *opt, int *cnt);
#endif
