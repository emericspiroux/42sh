/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:06:14 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:26:43 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*ft_display_cmd3(t_cmds *l_cmd, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;
	char			**path;
	int				i;

	i = 0;
	path = find_my_path("PATH=");
	while (path[i] != NULL)
	{
		rep = opendir(path[i]);
		while ((file = readdir(rep)))
		{
			if (ft_display_cmd2(path[i], file->d_name) == 1)
				l_cmd = dsp_file_cmp(l_cmd, file->d_name, myfile);
		}
		closedir(rep);
		i++;
	}
	if (l_cmd == NULL)
		l_cmd = ft_display_cmd(l_cmd, ".", myfile);
	return (l_cmd);
}

void	ft_dspl_cmp_exe(t_char *l_char)
{
	char	*dup;
	char	*way;
	char	*file;

	dup = send_my_char(l_char);
	if (ft_strchr(dup, '/') != NULL)
	{
		way = make_divise_way(dup);
		file = make_divise_file(dup);
		ft_display_exe(way, file);
		free(way);
		free(file);
	}
	else
		ft_display_exe(NULL, dup);
	free(dup);
}

void	ft_display_exe(char *way, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;
	t_cmds			*l_cmd;

	l_cmd = NULL;
	if (way == NULL)
		rep = opendir(".");
	else
		rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
			l_cmd = ft_display_exe2(way, file->d_name, myfile, l_cmd);
		closedir(rep);
		if (l_cmd != NULL)
		{
			dsp_files(l_cmd);
			ft_free_lc(l_cmd);
		}
	}
}

t_cmds	*ft_display_exe2(char *way, char *file, char *myfile, t_cmds *l_cmd)
{
	char	*tmp;
	char	*tmp2;

	if (way != NULL)
	{
		tmp = ft_strjoin(way, "/");
		tmp2 = ft_strjoin(tmp, file);
		if (ft_isx(tmp2) == 1)
			l_cmd = dsp_file_cmp(l_cmd, file, myfile);
		free(tmp);
		free(tmp2);
	}
	else
	{
		if (ft_isx(file) == 1)
			l_cmd = dsp_file_cmp(l_cmd, file, myfile);
	}
	return (l_cmd);
}
