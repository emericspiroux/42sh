/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:20:43 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/18 18:13:30 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_my_sig_cmp_file(int sig)
{
	static int	i;

	if (sig == -1)
		return (i);
	if (sig == -2)
		i = 0;
	else
		i = sig;
	return (i);
}

int	ft_my_sig_cmp_file2(int sig)
{
	static int	i;

	if (sig == -1)
		return (i);
	if (sig == -2)
		i = 0;
	else
	{
		if (i > 0 && sig == 1)
			i = 2;
		else
		  i = 1;
	}
	return (i);
}

int	reset_history_sig(int sig)
{
	static int	i;

	if (sig == -1)
		return (i);
	if (sig == -2)
		i = 0;
	else
		i = sig;
	return (i);
}

t_cmds	*save_history_sig(t_cmds *l_cmd, int sig)
{
	static t_cmds	*save;

	if (sig == 0)
		return (save);
	else if (sig == 1)
		save = l_cmd;
	else if (sig == -1)
		save = NULL;
	return (save);
}


int		save_lines_print(int lines, int sig)
{
	static int	save;

	if (sig == 1)
		save = lines;
	else if (sig == 0)
		return (save);
	else if (sig == -1)
		save = 0;
	return (save);
}
