/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_simple_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:22:47 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/15 15:20:54 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_simple_history(int begin, int bool_count, t_cmds *first_cmds)
{
	t_cmds	*pcurs;
	int		count;
	int		i;

	pcurs = first_cmds;
	count = begin;
	i = 0;
	no_history(pcurs, bool_count);
	while (i < begin && pcurs != NULL)
	{
		pcurs = pcurs->befor;
		i++;
	}
	while (pcurs != NULL)
	{
		if (bool_count == TRUE)
		{
			ft_space(count);
			ft_putnbr(count + 1);
			count++;
			ft_putstr("  ");
		}
		ft_putendl(pcurs->str);
		pcurs = pcurs->befor;
	}
}

void	ft_space(int count)
{
	count = count + 1;
	if (count < 10)
		ft_putstr("    ");
	else if (count >= 10)
		ft_putstr("   ");
	else if (count >= 100)
		ft_putstr("  ");
	else if (count >= 1000)
		ft_putstr(" ");
}

void	no_history(t_cmds *pcurs, int bool_count)
{
	if (!pcurs)
	{
		if (bool_count == TRUE)
			ft_putendl("    1 history");
		else
			ft_putendl("history -n");
	}
}
