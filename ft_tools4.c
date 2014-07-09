/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 18:46:34 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/15 16:39:58 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*ft_re_set(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		i;

	tmp = cmds;
	i = 0;
	if (ft_strcmp(tmp->befor->str, "|") == 0)
		i = 1;
	while (tmp->befor != NULL && i != 1)
	{
		if (ft_strcmp(tmp->befor->str, "|") == 0)
			i = 1;
			tmp = tmp->befor;
	}
	return (tmp);
}

char	*propper_my_line(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	dup = ft_strncpy(dup, str, i);
	return (dup);
}

int		ft_verify_all_pipe(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->str, "|") == 0)
			return (1);
		tmp = tmp->after;
	}
	return (0);
}

int		ft_count_liste(t_char *l_char)
{
	t_char	*tmp;
	int		i;

	i = 0;
	tmp = l_char;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->after;
	}
	return (i);
}

int		ft_verify_cmds(t_cmds *l_cmds)
{
	t_cmds	*tmp;

	tmp = l_cmds;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp != NULL)
	{
		if (tmp->done == 1)
			return (1);
		tmp = tmp->after;
	}
	return (0);
}
