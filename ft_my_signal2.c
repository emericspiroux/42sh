/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_signal2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:31:07 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:36:16 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		prompt_print_nb(int prompt)
{
	static int	save;

	if (prompt == -1)
		return (save);
	else
		save = prompt;
	return (save);
}

int		liste_print_nb(int liste)
{
	static int	save;

	if (liste == -1)
		return (save);
	else
		save = liste;
	return (save);
}

int		all_liste_print_nb(int liste)
{
	static int	save;

	if (liste == -1)
		return (save);
	else
		save = liste;
	return (save);
}

t_char	*save_l_char(t_char *l_char, int sig)
{
	static t_char	*save;

	if (sig == -1)
		save = NULL;
	if (sig == 0)
		return (save);
	if (sig == 1)
		save = l_char;
	return (save);
}

int		reset_line_sig(int reset, int sig)
{
	static int	save;

	if (sig == -1)
		save = 0;
	else if (sig == 0)
		return (save);
	else if (sig == 1)
		save = reset;
	return (save);
}

