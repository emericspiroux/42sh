/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_setenv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:29:34 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/15 16:36:36 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_my_setenv2(char **tab)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strjoin(tab[1], "=");
	if (get_line_env(str) == -1)
	{
		while (g_my_env[i])
			i++;
		g_my_env = ft_realloc_tab(g_my_env);
	}
	else
		i = get_line_env(str);
	make_my_setenv3(tab, str, i);
	free(str);
}

void	make_my_setenv3(char **tab, char *str, int i)
{
	char	*tmp;
	char	*tmp2;

	if (tab[2] != NULL)
	{
		tmp = ft_strjoin(str, tab[2]);
		tmp2 = ft_strdup(tmp);
		free(tmp);
		if (i != -1)
			g_my_env[i] = ft_strdup(tmp2);
		free(tmp2);
	}
	else
	{
		if (i != -1)
			g_my_env[i] = ft_strdup(str);
	}
}
