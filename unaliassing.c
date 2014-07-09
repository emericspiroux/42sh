/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unaliassing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 08:07:29 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/23 20:23:23 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#define NO_EXIST 1
#define ALIAS_EXIST 4
#define OPEN_ERROR 5

void		unaliassing(char *line)
{
	int		argc;
	char	**argv;

	argv = ft_strsplit(line, ' ');
	argc = count_arg(argv);
	uncreate_my_alias(argc, argv);
}

int			ft_error_unalias(int error, char *name)
{
	if (error == 0)
		ft_putendl("Usage : unalias [-a] [name]");
	else if (error == NO_EXIST)
	{
		ft_putstr("unalias: \"");
		ft_putstr(name);
		ft_putendl("\" no exist, erasing aborted.");
	}
	return (1);
}

void		erase_all_alias(void)
{
	t_alias	*l_alias;

	l_alias = ft_my_sig_alias(NULL, 0);
	ft_my_sig_alias(l_alias, -1);
	ft_putendl("unalias : temporary alias deleted.");
}


void		erase_one_alias(char *alias)
{
	t_alias	*l_alias;
	t_alias	*prevalias;

	l_alias = ft_my_sig_alias(NULL, 0);
	prevalias = NULL;
	while (l_alias)
	{
		if (ft_strstr(l_alias->name, alias) != NULL)
		{
			ft_free_one_alias(prevalias, l_alias);
			break ;
		}
		prevalias = l_alias;
		l_alias = l_alias->next;
	}
}

void		uncreate_my_alias(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc >= 2)
	{
		if (ft_strstr(argv[1], "-a") != NULL)
			erase_all_alias();
		else
		{
			while ((argv[i]))
			{
				if (verify_no_exist_alias(&argv[i]) == ALIAS_EXIST)
					erase_one_alias(argv[i]);
				else
					ft_error_unalias(NO_EXIST, argv[i]);
				i++;
			}
		}
	}
	else if (argc == 1)
		ft_error_unalias(0, NULL);
}
