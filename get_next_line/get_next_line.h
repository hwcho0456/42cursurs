/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:49:57 by hcho              #+#    #+#             */
/*   Updated: 2020/12/30 20:52:15 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strjoinfree(const char *s1, const char *s2);

#endif
