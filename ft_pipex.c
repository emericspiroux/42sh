/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 12:27:36 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 18:44:04 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		set_cmds(t_cmds *cmds)
{
	t_cmds	*tmp;

	ft_init_cmds(cmds);
	tmp = cmds;
	while (tmp->after != NULL)
		tmp = tmp->after;
	if (ft_verify_pipe(tmp) == 1)
	{
		while (ft_strcmp(tmp->str, "|") != 0)
			tmp = tmp->befor;
		ft_my_pipe(tmp);
	}
	else
	{
		while (tmp->befor != NULL)
			tmp = tmp->befor;
		ft_make_my_dir(tmp);
	}
}

void		make_my_pipe_in(t_cmds *cmds, int tabfd[2])
{
	t_cmds	*tmp;

	tmp = cmds;
	tmp = tmp->befor;
	dup2(tabfd[1], 1);
	close(tabfd[0]);
	if (ft_verify_pipe(tmp) == 1)
	{
		while (ft_strcmp(tmp->str, "|") != 0)
			tmp = tmp->befor;
		ft_my_pipe2(tmp, tabfd);
	}
	else
	{
		tmp = ft_re_set(cmds);
		if (ft_verify_dir(tmp) == 1)
			ft_make_my_dir(tmp);
		else
		{
			tmp->done = 1;
			make_my_builtin(tmp->str);
		}
	}
}

void		make_my_pipe_out(int father, t_cmds *cmds, int tabfd[2])
{
	t_cmds	*tmp;
	int		status;

	waitpid(father, &status, 0);
	tmp = cmds;
	dup2(tabfd[0], 0);
	close(tabfd[1]);
	tmp = tmp->after;
	if (ft_verify_dir(tmp) == 1)
		ft_make_my_dir(tmp);
	else
	{
		tmp->done = 1;
		make_my_builtin(tmp->str);
	}
}

void		ft_my_pipe2(t_cmds *cmds, int tabfd2[2])
{
	pid_t	father;
	int		tabfd[2];

	tabfd[1] = 0;
	dup2(tabfd2[1], tabfd[1]);
	cmds->done = 1;
	cmds->type = 'p';
	pipe(tabfd);
	father = fork();
	if (father > 0)
	{
		make_my_pipe_out(father, cmds, tabfd);
	}
	if (father == 0)
	{
		make_my_pipe_in(cmds, tabfd);
		exit(0);
	}
}

void		ft_my_pipe(t_cmds *cmds)
{
	pid_t	father;
	pid_t	father2;
	int		tabfd[2];
	int		status;

	father = fork();
	cmds->done = 1;
	cmds->type = 'p';
	if (father > 0)
		waitpid(father, &status, 0);
	if (father == 0)
	{
		pipe(tabfd);
		father2 = fork();
		if (father2 > 0)
		{
			make_my_pipe_out(father2, cmds, tabfd);
		}
		if (father2 == 0)
		{
			make_my_pipe_in(cmds, tabfd);
			exit(0);
		}
		exit(0);
	}
}
