/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_cd3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:21:04 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/17 20:20:42 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*make_cd_1arg2(char *way, char **av)
{
	int		i;
	char	**tab;
	char	*tmp;

	i = 0;
	tab = ft_strsplit(av[0], '/');
	tmp = ft_strdup(way);
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "..") == 0)
			tmp = cut_last_dir(tmp);
		else if (ft_strcmp(tab[i], ".") != 0)
			tmp = add_dir_way(tmp, tab[i]);
		i++;
	}
	ft_free_tab(tab);
	free(way);
	return (tmp);
}

char	*make_cd_2arg2(char *way, char **av)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strstr(way, av[0]);
	if (tmp == NULL)
		return (NULL);
	if ((tmp2 = ft_strchr(tmp, '/')) != NULL)
		tmp2 = ft_strdup(tmp2);
	tmp = ft_strcpy(tmp, av[1]);
	if (tmp2 != NULL)
	{
		ft_strcpy(tmp + ft_strlen(av[1]), tmp2);
		free(tmp2);
	}
	return (way);
}
