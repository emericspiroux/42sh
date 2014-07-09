/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 18:59:37 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/24 19:09:28 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds		*ft_my_lexer_1(t_cmds *cmds, char c)
{
	if (c == '<')
		cmds = ft_make_lc(cmds, "<", 'd');
	else if (c == '>')
		cmds = ft_make_lc(cmds, ">", 'd');
	else if (c == '|')
		cmds = ft_make_lc(cmds, "|", 'd');
	return (cmds);
}

t_cmds		*ft_my_lexer_2(t_cmds *cmds, char c)
{
	if (c == '<')
		cmds = ft_make_lc(cmds, "<", 'v');
	else
		cmds = ft_make_lc(cmds, ">", 'v');
	return (cmds);
}

t_cmds		*ft_my_lexer_3(t_cmds *cmds, char *cm, int i)
{
	char	*dup;
	int		j;

	j = 0;
	dup = (char *)malloc(sizeof(char) * (verify_pipe_and_ci(cm + i) + 1));
	while (cm[i] != 60 && cm[i] != 62 && cm[i] != '|' && cm[i] != '\0')
	{
		dup[j] = cm[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	cmds = ft_make_lc(cmds, dup, 'c');
	free(dup);
	return (cmds);
}

t_cmds		*ft_my_parser(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		j;

	j = 0;
	tmp = cmds;
	while (tmp != NULL)
	{
		if (tmp->type == 'd' || tmp->type == 'v')
			j++;
		else
			j = 0;
		if (j == 2)
		{
			error_extra(tmp->str);
			return (NULL);
		}
		tmp = tmp->after;
	}
	return (cmds);
}

void		ft_print_lc(t_cmds *cmds)
{
	t_cmds		*tmp;

	tmp = cmds;
	while (tmp != NULL)
	{
		ft_putstr(tmp->str);
		ft_putchar(' ');
		ft_putchar(tmp->type);
		ft_putchar('\n');
		tmp = tmp->after;
	}
}
