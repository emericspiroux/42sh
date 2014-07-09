/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:50:57 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:18:13 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		count_stars_noway(char *str)
{
	struct dirent	*file;
	DIR				*rep;
	int				j;

	j = 0;
	rep = opendir(".");
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
		{
			if (ft_match(file->d_name, str) == 1)
				j++;
		}
		closedir(rep);
	}
	return (j);
}

int		count_stars_way(char *str)
{
	struct dirent	*file;
	DIR				*rep;
	char			*way;
	char			*myfile;
	int				j;

	j = 0;
	way = make_divise_way(str);
	myfile = make_divise_file(str);
	rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
		{
			if (ft_match(file->d_name, myfile) == 1)
				j++;
		}
		closedir(rep);
	}
	else
		error_isnt(way);
	return (j);
}

int		ft_count_stars(char *str)
{
	int		j;

	if (ft_strchr(str, '/') != NULL)
		j = count_stars_way(str);
	else
		j = count_stars_noway(str);
	return (j);
}

int		ft_count_malloc(char *str, char cut)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == cut)
			i++;
		str2 = make_str(str, cut, i);
		if (verify_stars(str, cut, i) == 1)
			j = j + ft_count_stars(str2);
		else
			j++;
		while (str[i] != cut && str[i] != '\0')
			i++;
		free(str2);
	}
	return (j);
}
