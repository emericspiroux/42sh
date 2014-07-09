/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:50:49 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/10 18:41:05 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		make_sio(t_cmds *cmds, int fdo)
{
	t_cmds	*tmp;
	int		fdi;

	tmp = ft_re_set(cmds);
	tmp = tmp->befor;
	if (tmp != NULL && tmp->befor != NULL
		&& ft_strcmp(tmp->befor->str, ">") == 0)
	{
		fdi = open(tmp->str, O_RDONLY);
		dup2(fdi, 0);
	}
	dup2(fdo, 1);
	cmds->done = 1;
	tmp = ft_re_set(cmds);
	if (ft_strcmp(tmp->str, "|") == 0)
		tmp = tmp->after;
	make_my_builtin(tmp->str);
	if (ft_verify_all_pipe(cmds) == 0)
		exit(0);
}

void		my_dir_sio(t_cmds *cmds)
{
	int		fdo;
	pid_t	father;

	cmds->befor->done = 1;
	fdo = open(cmds->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fdo == -1)
		ft_putendl_fd("minishell2: open fail", 2);
	else
	{
		father = fork();
		if (father > 0)
		{
			wait(0);
			close(fdo);
		}
		if (father == 0)
			make_sio(cmds, fdo);
	}
}

void		make_soi(t_cmds *cmds, int fdi)
{
	t_cmds	*tmp;

	tmp = cmds;
	dup2(fdi, 0);
	tmp = ft_re_set(cmds);
	if (ft_strcmp(tmp->str, "|") == 0)
		tmp = tmp->after;
	make_my_builtin(tmp->str);
	if (ft_verify_all_pipe(cmds) == 0)
		exit(0);
}

void		my_dir_soi(t_cmds *cmds)
{
	int		fdi;
	pid_t	father;

	cmds->done = 1;
	fdi = open(cmds->str, O_RDONLY);
	if (fdi == -1)
		error_file(cmds->str);
	else
	{
		father = fork();
		if (father > 0)
		{
			wait(0);
			close(fdi);
		}
		if (father == 0)
			make_soi(cmds, fdi);
	}
}

void		ft_make_my_dir(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp != NULL && tmp->type != 'p')
	{
		if (tmp->type == 'd')
		{
			if (ft_strcmp(tmp->str, ">") == 0)
				my_dir_sio(tmp->after);
			else if (ft_strcmp(tmp->str, "<") == 0)
				my_dir_soi(tmp->after);
		}
		else if (tmp->type == 'v')
			my_dir_dio(tmp->after);
		tmp = tmp->after;
	}
}
