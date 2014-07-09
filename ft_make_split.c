/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:39:25 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:18:00 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	make_stars_noway(char **tab, char *str, int i[2])
{
	struct dirent	*file;
	DIR		*rep;

	rep = opendir(".");
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
		{
			if (ft_match(file->d_name, str) == 1)
			{
				tab[i[1]] = ft_strdup(file->d_name);
				i[1]++;
			}
		}
		closedir(rep);
	}
}

void	make_stars_way(char **tab, char *str, int i[2])
{
	struct dirent	*file;
	DIR		*rep;
	char		*way;
	char		*myfile;

	way = make_divise_way(str);
	myfile = make_divise_file(str);
	rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
		{
			if (ft_match(file->d_name, myfile) == 1)
			{
				tab[i[1]] = ft_strjoin(way, file->d_name);
				i[1]++;
			}
		}
		closedir(rep);
	}
	else
		error_isnt(way);
}

void	ft_split_stars(char **tab, char *str, int i[2])
{
	if (ft_strchr(str, '/') != NULL)
		make_stars_way(tab, str, i);
	else
		make_stars_noway(tab, str, i);
}

void	ft_split_word(char **tab, char *str, int i[2])
{
	tab[i[1]] = ft_strdup(str);
	i[1]++;
}

char	**ft_make_split(char **tab, char *str, char cut)
{
	int		i[2];
	char	*str2;

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] != '\0')
	{
		if (str[i[0]] == cut)
			i[0]++;
		str2 = make_str(str, cut, i[0]);
		if (verify_stars(str2, cut, i[0]) == 1)
			ft_split_stars(tab, str2, i);
		else
			ft_split_word(tab, str2, i);
		free(str2);
		while (str[i[0]] != cut && str[i[0]] != '\0')
			i[0]++;
	}
	tab[i[1]] = NULL;
	return (tab);
}
