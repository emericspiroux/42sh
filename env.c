/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftabarie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:13:40 by ftabarie          #+#    #+#             */
/*   Updated: 2014/03/25 15:02:28 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	check_path(void)
{
	int		i;
	char	**path;
	char	*str;
	int		j;
	char	*pwd;

	j = 0;
	str = ft_strdup("PATH=");
	i = get_line_env("PATH=");
	path = find_my_path("PATH=");
	free(g_my_env[i]);
	g_my_env[i] = check_path2(path, str, j);
	pwd = find_my_way("PWD=");
	chdir(pwd);
	free(pwd);
	ft_free_tab(path);
}

char	*check_path2(char **path, char *str, int j)
{
	char	*tmp;
	char	*tmp2;

	while (path[j] != NULL)
	{
		if (chdir(path[j]) != -1)
		{
			tmp = ft_strjoin(str, path[j]);
			tmp2 = ft_strjoin(tmp, ":");
			free(str);
			str = ft_strdup(tmp2);
			free(tmp);
			free(tmp2);
		}
		j++;
	}
	j = 0;
	while (str[j])
		j++;
	str[j - 1] = '\0';
	return (str);
}

void	make_my_env(void)
{
	int		i;

	if (environ[0] != NULL)
	{
		i = 0;
		while (environ[i])
			i++;
		g_my_env = (char **)malloc(sizeof(char *) * i + 1);
		i = 0;
		while (environ[i])
			i = get_old_n_pwd(i);
		g_my_env[i] = NULL;
		make_my_home();
		check_path();
	}
	else
	{
		g_my_env = NULL;
		ft_putendl_fd("\e[41m42sh: can't start minishell ", 2);
		ft_putendl_fd("without environ.\e[0m", 2);
	}
}

void	make_my_home(void)
{
	char	*home;
	int		i;

	if ((i = get_line_env("HOME=")) != -1)
	{
		if ((home = find_my_way("HOME=")) != NULL)
		{
			make_pwd_to_old();
			chdir(home);
			free(home);
			home = ft_getpwd("HOME=");
			free(g_my_env[i]);
			g_my_env[i] = ft_strdup(home);
			free(home);
			make_old_cd();
		}
	}
}
