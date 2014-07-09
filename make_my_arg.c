/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 19:13:03 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/17 19:30:01 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**make_arg2(char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		tmp = NULL;
	else
		tmp = ft_strsplit(line + i, ' ');
	return (tmp);
}

char	**make_arg(char *line)
{
	int		i;
	char	**tab;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	tab = ft_strsplit_stars(line, ' ');
	return (tab);
}

char	*make_line(char *line, char *path)
{
	int		i;
	int		j;
	char	*dup;

	j = 0;
	i = ft_strlen(line) + ft_strlen(path);
	dup = (char *)malloc(sizeof(char) * (i + 1));
	dup = ft_strcpy(dup, path);
	i = ft_strlen(path);
	dup[i] = '/';
	i++;
	while(line[j] != ' ' && line[j] != '\0' && line[j] != '\t')
	{
		dup[i] = line[j];
		i++;
		j++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*cut_fs(char *line)
{
	int		i;
	char	*dup;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	dup = ft_strdup(line + i);
	free(line);
	return (dup);
}

void	make_my_cmds(char *cmds_str)
{
	int		i;
	char	**tab_cmds;

	i = verify_char_str(cmds_str, ';');
	tab_cmds = ft_strsplit(cmds_str, ';');
	i = 0;
	while (tab_cmds[i] != NULL)
	{
		make_and_or(tab_cmds[i]);
		i++;
	}
	free(tab_cmds);
}
