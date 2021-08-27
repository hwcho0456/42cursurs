/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:24:24 by hcho              #+#    #+#             */
/*   Updated: 2021/08/16 15:24:26 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

int	    open_file(char *filename, int mode);
char	*parse_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);
void	redirect(char *cmd, char **envp, int fdin);
char	*ft_pathjoin(char *s1, char *s2);
int	    ft_strncmp(char *s1, char *s2, size_t n);
int	    ft_strichr(char *str, int c);
char	*ft_strndup(char *src, size_t n);
char	**ft_split(char *str, char sep);

#endif