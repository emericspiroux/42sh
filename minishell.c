/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:26:55 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 16:57:34 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_my_shell(char *line, char **av)
{
	pid_t   father;
	char	**path;
	int		child_status;

	path = find_my_path("PATH=");
	father = fork();
	if (father > 0)
	{
		wait(&child_status);
		if (child_status != 0)
			g_son = -1;
		else
			g_son = 1;
	}
	if (father == 0)
		make_my_shell1_2(line, av, path);
	ft_free_tab(path);
}

void	make_my_shell1_2(char *line, char **av, char **path)
{
	int		i;
	int		j;
	char	*cmd;

	i = 0;
	j = -1;
	while (path[i] != NULL)
	{
		cmd = make_line(line, path[i++]);
		j = execve(cmd, av, g_my_env);
		free(cmd);
	}
	if (j == -1)
	{
		ft_putstr_fd("Error : command not found : ", 2);
		ft_putendl_fd(line, 2);
		exit(-1);
	}
}

void	make_my_sehll2(char *line, char **av)
{
	pid_t	father;
	int		child_status;

	father = fork();
	if (father > 0)
	{
		wait(&child_status);
		if (child_status != 0)
			g_son = -1;
		else
			g_son = 1;
	}
	if (father == 0)
	{
		if (execve(line, av, g_my_env) == -1)
		{
			ft_putstr_fd("Error : command not found : ", 2);
			ft_putendl_fd(line, 2);
			exit(-1);
		}
	}
}
