/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_my_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 12:18:21 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/10 17:06:12 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*ft_move_my_cmds(int touch, t_cmds *l_cmds, t_char *l_char)
{
	t_cmds	*tmp;

	while (l_cmds->befor != NULL)
		l_cmds = l_cmds->befor;
	tmp = l_cmds;
	while (tmp != NULL && tmp->done != 1)
		tmp = tmp->after;
	if (tmp == NULL && touch == 4)
	{
		l_cmds->done = 1;
		l_char = free_liste_char(l_char);
		l_char = ft_make_lc_char(l_cmds->str, l_char);
	}
	else if (tmp != NULL && tmp->done == 1)
		l_char = ft_move_my_cmds2(touch, tmp, l_char);
	return (l_char);
}

t_char	*ft_move_my_cmds2(int touch, t_cmds *l_cmds, t_char *l_char)
{
	if (touch == 4)
	{
		if (l_cmds->after != NULL)
		{
			l_cmds->done = 0;
			l_cmds->after->done = 1;
			l_char = free_liste_char(l_char);
			l_char = ft_make_lc_char(l_cmds->after->str, l_char);
		}
	}
	else if (touch == 3)
		l_char = ft_move_my_cmds3(l_cmds, l_char);
	return (l_char);
}

t_char	*ft_move_my_cmds3(t_cmds *l_cmds, t_char *l_char)
{
	if (l_cmds->befor != NULL)
	{
		l_cmds->done = 0;
		l_cmds->befor->done = 1;
		l_char = free_liste_char(l_char);
		l_char = ft_make_lc_char(l_cmds->befor->str, l_char);
	}
	else if (l_cmds != NULL)
	{
		l_cmds->done = 0;
		l_char = free_liste_char(l_char);
	}
	else
		l_char = free_liste_char(l_char);
	return (l_char);
}
