/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_signal3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 19:10:25 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 19:26:30 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_alias	*ft_my_sig_alias(t_alias *l_alias, int sig)
{
	static t_alias		*save;

	if (sig == 0)
		return (save);
	if (sig == 1)
		save = l_alias;
	if (sig == -1)
	{
		save = NULL;
		ft_free_lc_alias(l_alias);
	}
	return (save);
}

int		ft_my_sig_resize(int sig)
{
	static int		i;

	if (sig < 0)
		return (i);
	else
		i = sig;
	return (i);
}
