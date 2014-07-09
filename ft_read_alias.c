/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:36:38 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 15:31:40 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_print_alias(t_alias *l_alias)
{
	t_alias	*tmp;

	tmp = l_alias;
	ft_putchar('\n');
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		ft_putendl(tmp->cmd);
		tmp = tmp->next;
	}
}

void	ft_read_alias(void)
{
	static t_alias		*l_alias;
	char		*line;
	int			fd;
	char		*alias;
	char		*cmd;

	fd = open("./.my42shrc", O_RDONLY | O_CREAT, 0644);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (verify_alias(line, &alias, &cmd) == 0)
		{
			l_alias = make_lc_alias(l_alias, alias, cmd);
			/*ft_print_alias(l_alias);*/
		}
		free(line);
	}
	close(fd);
	ft_my_sig_alias(l_alias, 1);
}

t_alias	*make_lc_alias(t_alias *l_alias, char *alias, char *cmd)
{
	t_alias	*tmp;
	t_alias	*new;

	tmp = l_alias;
	new = (t_alias *)malloc(sizeof(t_alias));
	new->name = ft_strdup(alias);
	new->cmd = ft_strdup(cmd);
	new->next = NULL;
	free(alias);
	free(cmd);
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		l_alias = new;
	return (l_alias);
}
