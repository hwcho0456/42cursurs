/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho <hcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:28:52 by hcho              #+#    #+#             */
/*   Updated: 2021/08/16 16:28:53 by hcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	open_file(char *filename, int mode)
{
	if (mode == 0)
	{
		if (access(filename, R_OK))
		{
			perror("infile error");
			exit(1);
		}
		return (open(filename, O_RDONLY));
	}
	return (open(filename, O_CREAT | O_WRONLY | O_TRUNC));
}

char	*parse_path(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_pathjoin(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_strichr(args[0], '/') != -1)
		path = args[0];
	else
		path = parse_path(args[0], envp);
	execve(path, args, envp);
	perror("command not found");
	exit(1);
}

void	redirect(char *cmd, char **envp, int fdin)
{
	pid_t	pid;
	int		fd[2];

	if ((pipe(fd) == -1) || ((pid = fork()) == -1))
	{
		perror("pipe error\n");
		exit(1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (fdin == 0)
			exit(1);
		else
			execute(cmd, envp);
	}		
    close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, NULL, 0);
}