/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:20:43 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 17:06:16 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*add_lc_cmp_cmd3(t_char *l_char, char *myfile, char *way)
{
	struct dirent	*file;
	DIR				*rep;
	char			**path;
	char			*dup;
	int				i;

	i = 0;
	dup = NULL;
	path = find_my_path("PATH=");
	while (path[i] != NULL)
	{
		rep = opendir(path[i]);
		while ((file = readdir(rep)))
			dup = add_lc_cmp_cmd2(file->d_name, path[i], myfile, dup);
		closedir(rep);
		i++;
	}
	dup = add_lc_cmp_cmd4(dup, way, myfile);
	l_char = add_lc_complite2(l_char, dup, myfile, NULL);
	if (dup != NULL)
		free(dup);
	ft_free_tab(path);
	return (l_char);
}

char	*add_lc_cmp_cmd4(char *dup, char *way, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;

	if (way == NULL)
		rep = opendir(".");
	else
		rep = opendir(way);
	while ((file = readdir(rep)))
		dup = add_lc_cmp_cmd5(dup, way, myfile, file->d_name);
	closedir(rep);
	return (dup);
}

char	*add_lc_cmp_cmd5(char *dup, char *way, char *myfile, char *file)
{
	char			*tmp;
	char			*tmp2;
	int				i;

	if (way != NULL)
	{
		tmp = ft_strjoin(way, "/");
		tmp2 = ft_strjoin(tmp, file);
		free(tmp);
		i = ft_isx(tmp2);
		free(tmp2);
	}
	else
		i = ft_isx(file);
	if (i == 2)
		dup = add_lc_complite1(dup, file, myfile);
	return (dup);
}

t_char	*ft_auto_cmp_exe(t_char *l_char)
{
	char		*dup;
	char		*way;
	char		*myfile;

	dup = send_my_char(l_char);
	way = make_divise_way(dup);
	myfile = make_divise_file(dup);
	l_char = ft_auto_cmp_exe2(l_char, way, myfile);
	free(dup);
	free(way);
	free(myfile);
	return (l_char);
}

t_char	*ft_auto_cmp_exe2(t_char *l_char, char *way, char *myfile)
{
	struct dirent	*file;
	char			*dup;
	DIR				*rep;

	dup = NULL;
	rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
			dup = ft_auto_cmp_exe3(dup, way, file->d_name, myfile);
		if (dup != NULL)
		{
			l_char = add_lc_complite2(l_char, dup, myfile, way);
			free(dup);
		}
		closedir(rep);
	}
	return (l_char);
}
