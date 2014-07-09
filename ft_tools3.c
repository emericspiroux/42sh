/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:16:38 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/15 16:12:12 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_free_lc(t_cmds *cmds)
{
	t_cmds	*tmp;
	t_cmds	*del;

	tmp = cmds;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->after;
		free(del->str);
		free(del);
	}
}

t_cmds	*ft_init_cmds(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp != NULL)
	{
		tmp->done = 0;
		tmp = tmp->after;
	}
	return (cmds);
}

int		ft_verify_pipe(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->str, "|") == 0)
			return (1);
		tmp = tmp->befor;
	}
	return (0);
}

int		ft_verify_dir(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp != NULL && tmp->type != 'p')
	{
		if (tmp->type == 'd' || tmp->type == 'v')
		{
			tmp->after->type = 'f';
			return (1);
		}
		tmp = tmp->after;
	}
	return (0);
}
