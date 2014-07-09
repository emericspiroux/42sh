/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_dir2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 18:39:50 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/11 15:57:45 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		make_dio(t_cmds *cmds, int fdo)
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

void		my_dir_dio(t_cmds *cmds)
{
	int		fdo;
	pid_t	father;

	cmds->befor->done = 1;
	fdo = open(cmds->str, O_RDWR | O_CREAT | O_APPEND, 0644);
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
			make_dio(cmds, fdo);
	}
}
