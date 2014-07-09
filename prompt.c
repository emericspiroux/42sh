/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftabarie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:38:19 by ftabarie          #+#    #+#             */
/*   Updated: 2014/03/21 18:48:23 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_my_prompt(void)
{
	char		*str;
	char		*pwd;
	char		*home;
	char		*login;

	pwd = find_my_way("PWD=");
	home = find_my_way("HOME=");
	login = find_my_way("USER=");
	if (ft_strlen(pwd) >= ft_strlen(home))
		str = ft_strjoin(login, "\e[0;94m@\e[0m \e[0;91m~");
	else
		str = ft_strjoin(login, "\e[0;94m@\e[0m \e[0;91m");
	my_prompt(pwd, home, str);
	free(str);
	free(pwd);
	free(home);
	free(login);
}

void	my_prompt(char *pwd, char *home, char *str)
{
	char		*str2;
	char		*str3;
	char		*path;
	int			i;

	if (ft_strlen(pwd) > ft_strlen(home))
	{
		i = ft_strlen(pwd) - ft_strlen(home);
		path = ft_strsub(pwd, ft_strlen(home), i);
		str2 = ft_strjoin(str, path);
		free(path);
	}
		else if (ft_strlen(pwd) < ft_strlen(home))
		str2 = ft_strjoin(str, pwd);
	else
		str2 = ft_strdup(str);
	str3 = ft_strjoin(str2, ">\e[0m ");
	ft_putstr(str3);
	prompt_print_nb(ft_strlen(str3) - 22);
	free(str2);
	free(str3);
}
