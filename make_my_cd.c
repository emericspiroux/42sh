/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:35:55 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/10 14:11:25 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_pwd_to_old(void)
{
	char	*pwd;
	char	*oldpwd;
	char	*newold;
	int		i;

	if ((i = get_line_env("OLDPWD=")) != -1)
	{
		if ((pwd = find_my_way("PWD=")) != NULL)
		{
			oldpwd = find_my_way("OLDPWD=");
			newold = ft_strjoin("OLDPWD=", pwd);
			free(pwd);
			free(g_my_env[i]);
			g_my_env[i] = ft_strdup(newold);
			free(newold);
			free(oldpwd);
		}
	}
}

void	make_d_cd(char *way)
{
	int		i;
	char	*pwd;

	if((i = get_line_env("PWD=")) != -1)
	{
		if (chdir(way) == -1)
			error_isnt(way);
		else
		{
			make_pwd_to_old();
			pwd = ft_strjoin("PWD=", way);
			free(g_my_env[i]);
			g_my_env[i] = ft_strdup(pwd);
			free(pwd);
		}
	}
}

void	make_old_cd(void)
{
	char	*oldpwd;
	char	*newpwd;
	int		i;

	if ((i = get_line_env("PWD=")) != -1)
	{
		if ((oldpwd = find_my_way("OLDPWD=")) != NULL)
		{
			chdir(oldpwd);
			make_pwd_to_old();
			newpwd = ft_strjoin("PWD=", oldpwd);
			free(oldpwd);
			free(g_my_env[i]);
			g_my_env[i] = ft_strdup(newpwd);
			free(newpwd);
		}
	}
}

void	make_just_cd(void)
{
	char	*home;
	char	*pwd;
	int		i;

	if ((i = get_line_env("PWD=")) != -1)
	{
		if ((home = find_my_way("HOME=")) != NULL)
		{
			make_pwd_to_old();
			chdir(home);
			pwd = ft_strjoin("PWD=", home);
			free(g_my_env[i]);
			g_my_env[i] = ft_strdup(pwd);
			free(home);
			free(pwd);
		}
	}
}

void	make_cd(char **av)
{
	char	*str;

	str = find_my_way("PWD=");
	if (!av || av[0] == NULL || ft_strcmp(av[0], "") == 0)
		make_just_cd();
	else if (!av[1] || av[1] == NULL || ft_strcmp(av[1], "") == 0)
	{
		if (ft_strcmp(av[0], "-") == 0)
			make_old_cd();
		else if (av[0][0] == '/')
			make_d_cd(av[0]);
		else
			make_cd_1arg(str, av);
	}
	else if (!av[2] || av[2] == NULL || ft_strcmp(av[2], "") == 0)
		make_cd_2arg(str, av);
	ft_free_tab(av);
	free(str);
}
