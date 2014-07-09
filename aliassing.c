/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliassing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 20:14:50 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/24 14:05:19 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		aliassing(char *line)
{
	int		argc;
	char	**argv;

	argv = ft_strsplit(line, ' ');
	argc = count_arg(argv);
	create_my_alias(argc, argv);
}

static int		ft_cut_al(char a)
{
	if (a == '"')
		return (1);
	return (0);
}

char			*cut_quote(char *s)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_cut_al(s[i]) == 1 && i < j)
		i++;
	while (ft_cut_al(s[j - 1]) == 1 && j != 0)
		j--;
	str = ft_strsub(s, i, j - i);
	return (str);
}

static void	put_line(void)
{
	ft_putstr("\033[31m \t\t= \033[0m");
}

void		show_alias(void)
{
	t_alias	*l_alias;

	if (!(l_alias = ft_my_sig_alias(NULL, 0)))
		ft_error_alias(NO_ALIAS, NULL);
	while (l_alias)
	{
		ft_putstr(l_alias->name);
		put_line();
		ft_putendl(l_alias->cmd);
		l_alias = l_alias->next;
	}
}
