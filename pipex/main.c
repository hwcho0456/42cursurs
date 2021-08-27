/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:07:40 by hcho              #+#    #+#             */
/*   Updated: 2021/08/16 15:07:41 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	main (int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc != 5)
    {
        write(2, "usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 48);
        exit(1);
    }
	fdin = open_file(argv[1], 0);
	fdout = open_file(argv[4], 1);
	dup2(fdin, 0);
	dup2(fdout, 1);
	redirect(argv[2], envp, fdin);
	execute(argv[3], envp);
	exit(0);
}