/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 23:11:17 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/18 17:16:56 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*way_to_home(char *way)
{
	int		i;

	i = get_line_env("HOME=");
	if (i != -1)
		way = ft_strchr(g_my_env[i], '=') + 1;
	else
		return (NULL);
	return (way);
}

int		get_line_env(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (g_my_env[i] && k != 0 && g_my_env[i] != NULL)
	{
		k = 0;
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] != g_my_env[i][j])
				k = -1;
			j++;
		}
		i++;
	}
	if (k == -1)
		return (k);
	return (i - 1);
}

int		verify_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		verify_word(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && verify_space(s1[i]) == 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] == '\0')
		return (1);
	return (0);
}

int		verify_char_str(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}
