/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:42:19 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/17 19:21:54 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*free_liste_one_char(t_char *l_char)
{
	t_char	*del;
	t_char	*befor;
	t_char	*after;

	del = l_char;
	while (l_char->befor != NULL)
		l_char = l_char->befor;
	if (del == l_char)
		l_char = l_char->after;
	befor = l_char->befor;
	after = l_char->after;
	if (befor != NULL)
		befor->after = after;
	if (after != NULL)
		after->befor = befor;
	free(del);
	return (l_char);
}

t_char	*free_liste_char(t_char *l_char)
{
	t_char	*tmp;
	t_char	*del;

	if (l_char != NULL)
	{
		while (l_char->befor != NULL)
			l_char = l_char->befor;
		tmp = l_char;
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->after;
			free(del);
		}
	}
	return (NULL);
}

int		verify_dir_char(char *read)
{
	if (read[0] == 27)
	{
		if (read[1] == 91)
		{
			if (read[2] == 68)
				return (1);
			else if (read[2] == 67)
				return (2);
			else if (read[2] == 66)
				return (3);
			else if (read[2] == 65)
				return (4);
			else if (read[2] == 70)
				return (5);
			else if (read[2] == 72)
				return (6);
			else if (read[2] == 51)
				return (7);
		}
	}
	return (0);
}

void	ft_clear_liste_cmds(t_cmds *l_cmds)
{
	t_cmds	*tmp;

	if (reset_history_sig(-1) == 1)
	{
		save_history_sig(NULL, -1);
		l_cmds = NULL;
	}
	tmp = l_cmds;
	if (tmp != NULL)
	{
		while (tmp->befor != NULL)
			tmp = tmp->befor;
		while (tmp != NULL)
		{
			tmp->done = 0;
			tmp = tmp->after;
		}
	}
}

void	ft_clear_liste_char(t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp != NULL)
	{
		tmp->a_prompt = 0;
		tmp->b_prompt = 0;
		tmp = tmp->after;
	}
}
