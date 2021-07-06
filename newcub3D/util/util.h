/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:13:35 by hcho              #+#    #+#             */
/*   Updated: 2021/05/05 21:13:33 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

char	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char    **ft_wfree(char **strs);
char	**ft_split(const char *s, char c);
char 	*read_file(char *filename);
int		is_num(char *str);
int		is_onlyspace(char *str);
char *ft_concat(char *s1, char c, char *s2);

#endif
