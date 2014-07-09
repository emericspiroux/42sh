/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 15:54:15 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 16:28:44 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		make_echo(char *line)
{
	int		arg;
	char	*echo;
	char	**tab;

	arg = 0;
	tab = ft_strsplit(line, ' ');
	if (tab[1] != NULL && ft_strcmp(tab[1], "-n") == 0)
		arg = 1;
	ft_free_tab(tab);
	echo = ft_strchr(line, ' ') + 1;
	if (arg == 1)
		echo = ft_strchr(echo, ' ') + 1;
	ft_putstr(echo);
	if (arg == 1)
	{
		ft_putstr("\e[0;30;47m");
		ft_putstr("%");
		ft_putendl("\e[0m");
	}
	else
		ft_putendl("");
}
