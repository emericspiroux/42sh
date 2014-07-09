/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 23:20:47 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/15 16:34:12 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_realloc_tab(char **env)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 2));
	while (env[j])
	{
		tab[j] = ft_strdup(env[j]);
		j++;
	}
	tab[j + 1] = NULL;
	ft_free_tab(env);
	return (tab);
}

char	**ft_realloc_tab_m(char **env, int k)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i])
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[j])
	{
		if (j == k)
			j++;
		else
		{
			tab[i] = ft_strdup(env[j]);
			i++;
			j++;
		}
	}
	tab[i] = NULL;
	ft_free_tab(env);
	return (tab);
}

void	make_my_unsetenv(char *line)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	j = 1;
	tab = ft_strsplit(line, ' ');
	while (tab[j] != NULL)
	{
		if (make_verify_setenv(tab[j]) == 0)
			error_unset(tab[j]);
		else
		{
			str = ft_strjoin(tab[j], "=");
			i = get_line_env(str);
			if (i != -1)
				g_my_env = ft_realloc_tab_m(g_my_env, i);
			else
				error_unset_isnt(tab[j]);
			free(str);
		}
		j++;
	}
	ft_free_tab(tab);
}

int		make_verify_setenv(char *line)
{
	if (ft_strcmp(line, "PWD") == 0 || ft_strcmp(line, "HOME") == 0)
	{
		error_unset(line);
		return (0);
	}
	else if (ft_strcmp(line, "OLDPWD") == 0 || ft_strcmp(line, "PATH") == 0)
	{
		error_unset(line);
		return (0);
	}
	else if (ft_strcmp(line, "USER") == 0 || ft_strcmp(line, "GROUP") == 0)
	{
		error_unset(line);
		return (0);
	}
	return (-1);
}

void	make_my_setenv(char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (tab[2] == NULL || tab[3] == NULL)
	{
		if (tab[1] && ((make_verify_setenv(tab[1])) == -1))
			make_my_setenv2(tab);
	}
	else if (tab[3] != NULL)
		ft_putendl_fd("setenv: too many arguments", 2);
	ft_free_tab(tab);
}
