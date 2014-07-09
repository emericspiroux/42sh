/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 17:15:29 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/15 16:35:07 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		verify_op(char c, char d)
{
	if (c == '&' && d == '&')
		return (1);
	if (c == '|' && d == '|')
		return (1);
	return (0);
}

t_cmds	*make_lc_or_and2(t_cmds *l_cmds, t_cmds *new)
{
	t_cmds	*tmp;

	tmp = l_cmds;
	if (l_cmds == NULL)
	{
		l_cmds = new;
		l_cmds->befor = NULL;
	}
	else
	{
		while (tmp->after != NULL)
			tmp = tmp->after;
		tmp->after = new;
		new->befor = tmp;
	}
	return (l_cmds);
}

t_cmds	*make_lc_or_and(t_cmds *l_cmds, char *str, char c)
{
	t_cmds	*new;
	t_cmds	*new2;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	new->str = ft_strdup(str);
	new->type = 'c';
	if (c == '\0')
		new->after = NULL;
	else
	{
		new2 = (t_cmds *)malloc(sizeof(t_cmds));
		new->after = new2;
		new2->after = NULL;
		new2->befor = new;
		new2->type = 'o';
		if (c == '&')
			new2->str = ft_strdup("&&");
		if (c == '|')
			new2->str = ft_strdup("||");
	}
	l_cmds = make_lc_or_and2(l_cmds, new);
	free(str);
	return (l_cmds);
}

void	ft_my_and_or(t_cmds *l_cmds)
{
	t_cmds	*tmp;
	int		i;

	i = 1;
	tmp = l_cmds;
	while (tmp != NULL && i == 1)
	{
		make_my_extra(tmp->str);
		tmp = tmp->after;
		if (tmp != NULL && tmp->str[0] == '|' && g_son == 1)
			i = -1;
		if (tmp != NULL && tmp->str[0] == '&' && g_son == -1)
			i = -1;
		if (tmp != NULL)
			tmp = tmp->after;
	}
	ft_free_lc(l_cmds);
}

void	make_and_or(char *line)
{
	int		i;
	int		j;
	char	*tmp;
	t_cmds	*l_cmds;

	i = 0;
	j = 0;
	l_cmds = NULL;
	if (ft_strstr(line, "&&") != NULL || ft_strstr(line, "||") != NULL)
	{
		while (line[j] != '\0')
		{
			while (verify_op(line[i], line[i + 1]) != 1 && line[i] != '\0')
				i++;
			tmp = (char *)malloc(sizeof(char) * (i + 1));
			tmp = ft_strncpy(tmp, line + j, i);
			l_cmds = make_lc_or_and(l_cmds, tmp, line[i]);
			if (line[i] != '\0')
				i += 2;
			j = i;
		}
		ft_my_and_or(l_cmds);
	}
	else
		make_my_extra(line);
}
