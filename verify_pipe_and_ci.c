/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pipe_and_ci.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:14:42 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/14 13:40:39 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int			verify_pipe_and_ci(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '|' || str[i] == '>')
			return (i);
		i++;
	}
	return (-1);
}

void		make_my_extra(char *str)
{
	t_cmds		*cmds;

	if (verify_pipe_and_ci(str) > -1)
	{
		cmds = ft_strsplit_lc(str);
		if (ft_my_parser(cmds) != NULL && verify_my_parser(cmds) != NULL)
			set_cmds(cmds);
		ft_free_lc(cmds);
	}
	else
		make_my_builtin(str);
}

char		ft_my_lexer(char c, char d)
{
	if (c == '<' && d == '<')
		return ('v');
	else if (c == '>' && d == '>')
		return ('v');
	else if (c == '>')
		return ('d');
	else if (c == '<')
		return ('d');
	else if (c == '|')
		return ('d');
	return ('a');
}

t_cmds		*ft_make_lc(t_cmds *cmds, char *str, char type)
{
	t_cmds	*new;
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp && tmp->after != NULL)
		tmp = tmp->after;
	if (cmds != NULL)
	{
		new = (t_cmds *)malloc(sizeof(t_cmds));
		tmp->after = new;
		new->str = ft_strdup(str);
		new->type = type;
		new->after = NULL;
		new->befor = tmp;
	}
	else
	{
		new = (t_cmds *)malloc(sizeof(t_cmds));
		new->after = NULL;
		new->str = ft_strdup(str);
		new->befor = NULL;
		new->type = type;
		cmds = new;
	}
	return (cmds);
}

t_cmds		*ft_strsplit_lc(char *cm)
{
	int		i;
	t_cmds	*cmds;

	i = 0;
	cmds = NULL;
	while (cm[i] != '\0')
	{
		if (ft_my_lexer(cm[i], cm[i + 1]) == 'd')
			cmds = ft_my_lexer_1(cmds, cm[i++]);
		else if (ft_my_lexer(cm[i], cm[i + 1]) == 'v')
		{
			cmds = ft_my_lexer_2(cmds, cm[i]);
			i += 2;
		}
		else
		{
			cmds = ft_my_lexer_3(cmds, cm, i);
			while (cm[i] != 60 && cm[i] != 62 && cm[i] != '|' && cm[i] != '\0')
				i++;
		}
	}
	return (cmds);
}
