/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_cd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:58:39 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/12 18:13:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*add_dir_way(char *way, char *dir)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (way[i + 1] != '\0')
		i++;
	if (way[i] != '/')
	{
		tmp = ft_strjoin(way, "/");
		tmp2 = ft_strjoin(tmp, dir);
		free(tmp);
	}
	else
		tmp2 = ft_strjoin(way, dir);
	free(way);
	return (tmp2);
}

char	*cut_last_dir(char *way)
{
	char	*tmp;

	if (way)
	{
		tmp = ft_strrchr(way, '/');
		if (tmp)
			tmp[0] = '\0';
		if (way[0] == '\0')
		{
			way[0] = '/';
			way[1] = '\0';
		}
	}
	tmp = ft_strdup(way);
	free(way);
	return (tmp);
}

int		count_a_char(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	if (j == 0)
		j = 1;
	return (j);
}

void	make_cd_1arg(char *way, char **av)
{
	int		i;
	char	*dup;

	dup = ft_strdup(way);
	dup = make_cd_1arg2(dup, av);
	if (chdir(dup) == -1)
		error_isnt(av[0]);
	else
	{
		i = 0;
		while (dup[i + 1] != '\0')
			i++;
		if (dup[i] == '/' && ft_strcmp(dup, "/") != 0)
			dup[i] = '\0';
		make_pwd_to_old();
		i = get_line_env("PWD=");
		free(g_my_env[i]);
		g_my_env[i] = ft_strjoin("PWD=", dup);
	}
	free(dup);
}

void	make_cd_2arg(char *way, char **av)
{
	char	*tmp;
	char	*way2;
	int		i;

	i = ft_strlen(av[0]) - ft_strlen(av[1]);
	i = ft_strlen(way) + i;
	way2 = (char *)malloc(sizeof(char) * (i + 1));
	way2 = ft_strcpy(way2, way);
	way2 = make_cd_2arg2(way2, av);
	if (way2 == NULL)
		error_isnt(av[0]);
	else if (chdir(way2) == -1)
		error_isnt(av[1]);
	else
	{
		if ((i = get_line_env("PWD=")) != -1)
		{
			make_pwd_to_old();
			free(g_my_env[i]);
			g_my_env[i] = ft_strjoin("PWD=", (tmp = ft_strdup(way2)));
			free(tmp);
			free(way2);
		}
	}
	free(way2);
}
