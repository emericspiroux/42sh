/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:00:17 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/18 16:40:55 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*dsp_file_cmp2(t_cmds *l_cmd, t_cmds *new)
{
	if (l_cmd == NULL)
	{
		new->befor = NULL;
		l_cmd = new;
	}
	else
		l_cmd = dsp_file_cmp3(l_cmd, new);
	return (l_cmd);
}

t_cmds	*dsp_file_cmp3(t_cmds *l_cmd, t_cmds *new)
{
	t_cmds	*tmp;
	t_cmds	*tmp2;

	tmp = l_cmd;
	if (ft_strcmp(tmp->str, new->str) > 0)
	{
		tmp->befor = new;
		new->after = tmp;
		new->befor = NULL;
		l_cmd = new;
	}
	else
	{
		while (tmp->after != NULL && ft_strcmp(tmp->after->str, new->str) < 0)
			tmp = tmp->after;
		tmp2 = tmp->after;
		tmp->after = new;
		new->befor = tmp;
		new->after = tmp2;
	}
	return (l_cmd);
}

void	ft_dspl_cmp_cmd(t_char *l_char)
{
	char	*dup;
	char	*way;
	char	*file;
	t_cmds	*l_cmd;

	l_cmd = NULL;
	dup = send_my_char(l_char);
	if (ft_strchr(dup, '/') != NULL)
	{
		way = make_divise_way(dup);
		file = make_divise_way(dup);
		if (way[0] == '\0')
			l_cmd = ft_display_cmd(l_cmd, "/", file);
		else
			l_cmd = ft_display_cmd(l_cmd, way, file);
		free(way);
		free(file);
	}
	else
		l_cmd = ft_display_cmd3(l_cmd, dup);
	dsp_cmds(l_cmd);
	free(dup);
}

t_cmds	*ft_display_cmd(t_cmds *l_cmd, char *way, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;
	int				i;

	rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
		{
			i = ft_display_cmd2(way, file->d_name);
			if (i == 1 || i == 2)
				l_cmd = dsp_file_cmp(l_cmd, file->d_name, myfile);
		}
		closedir(rep);
	}
	return (l_cmd);
}

int		ft_display_cmd2(char *way, char *file)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_strjoin(way, "/");
	tmp2 = ft_strjoin(tmp, file);
	i = ft_isx(tmp2);
	free(tmp);
	free(tmp2);
	return (i);
}
