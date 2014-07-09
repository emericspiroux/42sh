/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 13:53:37 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/23 15:06:55 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		history(char *line)
{
	char	**argv;
	int		argc;
	int		begin;
	t_cmds	*first_cmds;

	first_cmds = save_history_sig(NULL, 0);
	first_cmds = find_first_cmds(first_cmds);
	argv = ft_strsplit(line, ' ');
	argc = count_arg(argv);
	begin = adjust_history(first_cmds);
	if (argc == 1)
		make_simple_history(begin, TRUE, first_cmds);
	else
		valid_hist_arg(argv, argc, begin, first_cmds);
	ft_free_tab(argv);
}

t_cmds		*find_first_cmds(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	if (tmp != NULL)
	{
		while (tmp->after)
			tmp = tmp->after;
	}
	return (tmp);
}

int			adjust_history(t_cmds *first_cmds)
{
	int		i;
	t_cmds	*pcurs;

	i = 0;
	pcurs = first_cmds;
	while (pcurs)
	{
		pcurs = pcurs->befor;
		i++;
	}
	if (i > 15)
		i = i - LEN_VHIST;
	else
		i = 0;
	return (i);
}

int			count_arg(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
