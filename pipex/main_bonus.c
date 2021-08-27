/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:42:50 by hcho              #+#    #+#             */
/*   Updated: 2021/08/23 12:42:51 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	main (int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;
    int i;

	if (argc < 5)
    {
        write(2, "usage: ./pipex <file1> <cmd1> ... <cmdn> <file2>\n", 49);
        exit(1);
    }
	fdin = open_file(argv[1], 0);
	fdout = open_file(argv[argc - 1], 1);
	dup2(fdin, 0);
	dup2(fdout, 1);
	redirect(argv[2], envp, fdin);
    i = 3;
	while (i < argc - 2)
        redirect(argv[i++], envp, 1);
	execute(argv[i], envp);
	exit(0);
}