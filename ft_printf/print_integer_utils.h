/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:09:42 by hcho              #+#    #+#             */
/*   Updated: 2021/01/06 19:48:32 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INTEGER_UTILS_H
# define PRINT_INTEGER_UTILS_H
# include "ft_printf.h"
char	*g_hex;
void	put_dpadding(long long n, t_op *opt, int *cnt);
void	put_dsign(long long n, t_op *opt, int *cnt);
void	put_dnum(long long n, t_op *opt, int *cnt);
void	put_upadding(unsigned long long n, t_op *opt, int *cnt);
void	put_unum(unsigned long long n, t_op *opt, int *cnt);
void	put_hpadding(unsigned long long n, t_op *opt, int *cnt);
void	put_hnum(unsigned long long n, t_op *opt, int *cnt);
#endif
