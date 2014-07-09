/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:50:26 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 15:04:45 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		verify_stars(char *str, char cut, int i)
{
	int		j;

	j = i;
	while (str[j] != cut && str[j] != '\0')
	{
		if (str[j] == '*')
			return (1);
		j++;
	}
	return (0);
}

int		ft_count_word(char *str, char cut, int i)
{
	while (str[i] != '\0' && str[i] != cut)
		i++;
	return (1);
}

int		ft_count_char(char *str, char cut, int i)
{
	while (str[i] != '\0' && str[i] != cut)
		i++;
	return (i);
}

char	*make_str(char *str, char cut, int i)
{
	char	*dup;
	int		j;
	int		k;

	j = ft_count_char(str, cut, i);
	dup = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	k = i;
	while (str[k] != cut && str[k] != '\0')
	{
		dup[j] = str[k];
		k++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

t_cmds	*ft_reset_cmds(t_cmds *l_cmds)
{
	l_cmds = NULL;
	save_history_sig(l_cmds, -1);
	reset_history_sig(-2);
	return (NULL);
}
