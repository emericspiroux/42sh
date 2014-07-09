/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliassing2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 13:38:24 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/25 15:18:19 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int			splitalias(char *line, char **alias, char **cmd)
{
	char	**split;
	char	**fsplit;

	(*alias) = NULL;
	(*cmd) = NULL;
	if ((!(*cmd)) && (!(*alias)))
	{
		fsplit = ft_strsplit(line, ' ');
		if (fsplit[1])
			split = ft_strsplit(fsplit[1], '=');
		else if (fsplit[0])
			split = ft_strsplit(fsplit[0], '=');
		else
			return (SPLIT_ERROR);
		(*alias) = ft_strdup(split[0]);
		if (split[1])
			(*cmd) = ft_strdup(split[1]);
		else
			return (SPLIT_ERROR2);
		return (0);
	}
	return (SPLIT_ERROR3);
}

int			verify_alias(char *line, char **alias, char **cmd)
{
	int		error;

	if (ft_strstr(line, "="))
	{
		if ((error = splitalias(line, alias, cmd)))
			return (ft_error_alias(error, NULL));
		*cmd = cut_quote(*cmd);
		if ((error = verify_no_exist_alias(alias)))
			return (ft_error_alias(error, *alias));
		return (0);
	}
	ft_error_alias(NO_EQUAL, NULL);
	return (1);
}

void		create_my_alias(int argc, char **argv)
{
	char	*cmd;
	char	*alias;

	if (argc == 2)
	{
		if (!(verify_alias(argv[1], &alias, &cmd)))
			putalias(alias, cmd);
		else
			return ;
	}
	else if (argc == 1)
		show_alias();
	else
		ft_error_alias(0, NULL);
}

int			ft_error_alias(int error, char *cmd)
{
	if (error == NO_EQUAL || error == 0)
		ft_putendl("usage : alias [alias]=\"[cmd]\".");
	else if (error == NO_CMD)
	{
		ft_putstr("42sh :");
		ft_putstr(cmd);
		ft_putendl(" : not found.");
	}
	else if (error == SPLIT_ERROR)
		ft_putendl("alias: split error : [alias]=\"[cmd]\". missing");
	else if (error == SPLIT_ERROR2)
		ft_putendl("alias: split error : command after equal missing");
	else if (error == SPLIT_ERROR3)
		ft_putendl("alias: split error : cmd or/and alias are not empty");
	else if (error == ALIAS_EXIST)
	{
		ft_putstr("alias: \"");
		ft_putstr(cmd);
		ft_putendl("\" already exist.");
	}
	else if (error == NO_ALIAS)
		ft_putendl("alias: Alias list empty.");
	return (1);
}

int		putalias(char *alias, char *cmd)
{
	t_alias	*l_alias;

	l_alias = ft_my_sig_alias(NULL, 0);
	l_alias = make_lc_alias(l_alias, alias, cmd);
	ft_my_sig_alias(l_alias, 1);
	return (0);
}
