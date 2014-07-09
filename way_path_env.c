/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_path_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:34:27 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 15:03:26 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*find_my_way(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*way;
	int		i;

	way = NULL;
	if ((i = get_line_env(str)) != -1)
	{
		tmp = ft_strdup(g_my_env[i]);
		tmp2 = ft_strchr(tmp, '=') + 1;
		way = ft_strdup(tmp2);
		free(tmp);
	}
	return (way);
}

char	*cut_rab(char *line)
{
	int		i;
	char	*dup;

	i = 0;
	dup = ft_strnew(3);
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
	{
		dup[i] = line[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**find_my_path(char *str)
{
	char	*line;
	char	**path;

	line = find_my_way(str);
	path = ft_strsplit(line, ':');
	free(line);
	return (path);
}

void	make_my_way(char *line)
{
	char	**av;

	av = make_arg(line);
	line = propper_my_line(line);
	if (ft_strchr(line, '/') != NULL)
		make_my_sehll2(line, av);
	else
		make_my_shell(line, av);
	free(line);
	ft_free_tab(av);
}

void	show_my_env(void)
{
	int		i;

	i = 0;
	while (g_my_env[i])
	{
		ft_putendl(g_my_env[i]);
		i++;
	}
}
