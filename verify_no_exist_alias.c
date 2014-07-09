/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliassing3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 13:39:49 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/24 13:40:16 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int			verify_no_exist_alias(char **alias)
{
	t_alias		*l_alias;

	l_alias = ft_my_sig_alias(NULL, 0);
	while (l_alias)
	{
		if ((ft_strcmp(l_alias->name, *alias) == 0)
			|| ft_strcmp("emacs", *alias) == 0)
			return (ALIAS_EXIST);
		l_alias = l_alias->next;
	}
	return (0);
}
