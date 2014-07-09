/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:31 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/14 19:19:27 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*verify_my_parser(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	if (ft_strcmp(tmp->str, "|")  == 0)
	{
		error_extra("|");
		return (NULL);
	}
	while (tmp->after != NULL)
		tmp = tmp->after;
	if (tmp->type == 'd' || tmp->type == 'v')
	{
		error_extra("\\n");
		return (NULL);
	}
	return (cmds);
}

char	*make_propper_line(char *str)
{
	char	*dup;

	dup = ft_replace_isspace(str);
	dup = ft_cut_multi_space(dup);
	dup = cut_fs(dup);
	dup = ft_cut_last_space(dup);
	dup = ft_cut_some_space(dup, ';');
	dup = ft_cut_some_space(dup, '|');
	dup = ft_cut_some_space(dup, '<');
	dup = ft_cut_some_space(dup, '>');
	dup = ft_cut_some_space(dup, '&');
	return (dup);
}

int		ft_strlen_propper(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j++;
		if (str[i] == ';')
		{
			if (str[i - 1] == ' ')
				j--;
			if (str[i + 1] == ' ')
				j--;
		}
		i++;
	}
	return (j);
}

int		ft_strlen_isspace(char *str)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		k++;
		if (ft_isspace(str[i]) == 1)
			j++;
		else
			j = 0;
		if (j > 1)
			k--;
		i++;
	}
	return (k);
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
