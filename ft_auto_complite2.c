/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:20:43 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 16:50:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*add_lc_complite2(t_char *l_char, char *cmp, char *old, char *way)
{
	int		type;
	char	*tmp;
	char	*tmp2;

	if (cmp != NULL)
	{
		type = 0;
		if (way != NULL)
		{
			tmp = ft_strjoin(way, "/");
			tmp2 = ft_strjoin(tmp, cmp);
			type = ft_isx(tmp2);
			free(tmp);
			free(tmp2);
		}
		else
			type = ft_isx(cmp);
		if (cmp != NULL)
			l_char = add_lc_complite21(l_char, cmp, old, type);
	}
	return (l_char);
}

t_char	*add_lc_complite21(t_char *l_char, char *cmp, char *old, int type)
{
	t_char	*tmp;
	int		i;

	i = 0;
	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	while (tmp->after != NULL && ft_isspace(tmp->after->c) != 1)
		tmp = tmp->after;
	while (old[i] != '\0')
		i++;
	while (cmp[i] != '\0')
	{
		ft_clear_liste_char(l_char);
		add_my_lc_complite(cmp[i], tmp);
		i++;
		tmp = tmp->after;
		ft_my_sig_cmp_file(-3);
	}
	if (type == 2 && tmp->c != '/')
		add_my_lc_complite('/', tmp);
	return (l_char);
}

t_char	*ft_auto_cmp_cmd(t_char *l_char)
{
	char	*dup;
	char	*way;
	char	*file;

	dup = send_my_char(l_char);
	if (ft_strchr(dup, '/') != NULL)
	{
		way = make_divise_way(dup);
		file = make_divise_file(dup);
		if (way[0] == '\0')
			l_char = add_lc_cmp_cmd(l_char, "/", file);
		else
			l_char = add_lc_cmp_cmd(l_char, way, file);
		free(way);
		free(file);
	}
	else
		l_char = add_lc_cmp_cmd(l_char, NULL, dup);
	free(dup);
	return (l_char);
}

t_char  *add_lc_cmp_cmd(t_char *l_char, char *way, char *myfile)
{
	struct dirent		*file;
	DIR					*rep;
	char				*dup;

	dup = NULL;
	if (way == NULL)
		l_char = add_lc_cmp_cmd3(l_char, myfile, way);
	else
	{
		rep = opendir(way);
		if (rep != NULL)
		{
			while ((file = readdir(rep)))
				dup = add_lc_cmp_cmd2(file->d_name, way, myfile, dup);
			closedir(rep);
		}
		l_char = add_lc_complite2(l_char, dup, myfile, way);
		if (dup != NULL)
			free(dup);
	}
	return (l_char);
}

char	*add_lc_cmp_cmd2(char *file, char *way, char *myfile, char *dup)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (way != NULL)
	{
		tmp = ft_strjoin(way, "/");
		tmp2 = ft_strjoin(tmp, file);
		i = ft_isx(tmp2);
		if ((i == 1 || i == 2) && ft_strcmp(file, ".") != 0)
		{
			if (ft_strcmp(file, "..") != 0)
				dup = add_lc_complite1(dup, file, myfile);
		}
		free(tmp);
		free(tmp2);
	}
	else
	{
		i = ft_isx(file);
		if (i == 1 || i == 2)
			dup = add_lc_complite1(dup, file, myfile);
	}
	return (dup);
}
