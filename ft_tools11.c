/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools11.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:26:38 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 20:26:08 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_free_one_alias(t_alias *prev, t_alias *del)
{
	if (prev != NULL)
		prev->next = del->next;
	else
		ft_my_sig_alias(del->next, 1);
	free(del->name);
	free(del->cmd);
	free(del);
}

void	ft_free_lc_alias(t_alias *l_alias)
{
	t_alias		*tmp;
	t_alias		*tmp2;

	tmp = l_alias;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp->cmd);
		free(tmp);
		tmp = tmp2;
	}		
}
