/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:54:20 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/18 16:19:35 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*ft_my_complite(t_char *l_char)
{
	int	i;

	i = verify_where_complite(l_char);
	if (i == 1)
		l_char = ft_auto_cmp_exe(l_char);
	else if (i == 0)
		l_char = ft_auto_complite(l_char);
	else if (i == 2)
		l_char = ft_auto_cmp_cmd(l_char);
	return (l_char);
}

t_char	*ft_auto_complite(t_char *l_char)
{
	char	*dup;
	char	*way;
	char	*file;

	dup = send_my_char(l_char);
	if (ft_strchr(dup, '/') == NULL)
		l_char = add_lc_complite(l_char, NULL, dup);
	else
	{
		way = make_divise_way(dup);
		file = make_divise_file(dup);
		l_char = add_lc_complite(l_char, way, file);
		free(way);
		free(file);
	}
	free(dup);
	return (l_char);
}

t_char	*add_lc_complite(t_char *l_char, char *way, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;
	char			*dup;

	dup = NULL;
	if (way == NULL)
		rep = opendir(".");
	else if (ft_strcmp(way, "") == 0)
		rep = opendir("/");
	else
		rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
			dup = add_lc_complite1(dup, file->d_name, myfile);
		l_char = add_lc_complite2(l_char, dup, myfile, way);
		closedir(rep);
		if (dup != NULL)
			free(dup);
	}
	return (l_char);
}

char	*add_lc_complite1(char *cmp, char *file, char *myin)
{
	int		i;

	i = 0;
	if (cmp == NULL)
	{
		while (myin[i] == file[i])
			i++;
		if (myin[i] == '\0')
		{
			while (file[i] != '\0')
				i++;
			cmp = (char *)malloc(sizeof(char) * (i + 1));
			cmp = ft_strcpy(cmp, file);
		}
	}
	else
		cmp = add_lc_complite12(cmp, file, myin);
	return (cmp);
}

char	*add_lc_complite12(char *cmp, char *file, char *myin)
{
	int	i;

	i = 0;
	while (myin[i] == file[i])
		i++;
	if (myin[i] == '\0')
	{
		while (cmp[i] != '\0' && file[i] != '\0' && file[i] == cmp[i])
			i++;
		free(cmp);
		cmp = (char *)malloc(sizeof(char) * (i + 1));
		cmp = ft_strncpy(cmp, file, i);
	}
	return (cmp);
}
