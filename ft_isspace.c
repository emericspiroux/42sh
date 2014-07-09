/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 18:36:17 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/18 18:10:35 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_isspace(char c)
{
	if (c == '\t' ||  c == '\v' ||  c == '\f' ||  c == '\r' ||  c == 9)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

char	*ft_replace_isspace(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 1)
			dup[i] = ' ';
		else
			dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_cut_multi_space(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*dup;

	i = 0;
	j = 0;
	k = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen_isspace(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			j++;
		else
			j = 0;
		if (j < 2)
		{
			dup[k] = str[i];
			k++;
		}
		i++;
	}
	dup[i] = '\0';
	free(str);
	return (dup);
}

char	*ft_cut_last_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (ft_isspace(str[i]) == 1)
		str[i] = '\0';
	return (str);
}

char	*ft_cut_some_space(char *str, char c)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen_propper(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i - 1] && str[i - 1] == ' ')
				j--;
		}
		dup[j] = str[i];
		j++;
		i++;
		if (str[i - 1] == c && str[i] == ' ')
			i++;
	}
	dup[j] = '\0';
	free(str);
	return (dup);
}
