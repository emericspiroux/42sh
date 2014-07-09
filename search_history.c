/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:22:47 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/23 15:14:36 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		reset_cmds(t_cmds *first_cmds)
{
	ft_putendl("history: Reset history done !");
	ft_free_lc(first_cmds);
	reset_history_sig(1);
	save_history_sig(NULL, -1);
}

int			search_history(char *name, t_cmds *first_cmds, char **argv)
{
	int		begin;

	if ((name = find_name(argv)))
	{
		if ((begin = find_cmds(name, first_cmds)) == -1)
		{
			ft_putstr("fc: event not found: ");
			ft_putendl(name);
			return (-1);
		}
	}
	else
	{
		ft_putendl("(Usage) history -a [name]");
		return (-1);
	}
	if (name != NULL)
		free(name);
	return (begin);
}

char		*find_name(char **argv)
{
	int		i;
	char	*name;

	i = 1;
	while (argv[i])
	{
		if (!(ft_strstr(argv[i], "-")))
		{
			name = (char*) malloc(sizeof(char) * ft_strlen(argv[i]) + 1);
			ft_strcpy(name, argv[i]);
			return (name);
		}
		i++;
	}
	return (NULL);
}

int			find_cmds(char *name, t_cmds *first_cmds)
{
	t_cmds	*p_curs;
	int		i;

	i = 0;
	p_curs = first_cmds;
	while (p_curs->befor->befor)
	{
		i++;
		p_curs = p_curs->befor;
	}
	while (i > 0)
	{
		if (p_curs && ft_strcmp(p_curs->str, name) == 0)
			return (i);
		p_curs = p_curs->after;
		i--;
	}
	return (-1);
}
