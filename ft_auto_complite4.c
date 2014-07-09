/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complite4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:20:43 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:25:57 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_auto_cmp_exe3(char *dup, char *way, char *file, char * myfile)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (ft_strcmp(way, ".") == 0)
		i = ft_isx(file);
	else
	{
		tmp = ft_strjoin(way, "/");
		tmp2 = ft_strjoin(tmp, file);
		i = ft_isx(tmp2);
		free(tmp);
		free(tmp2);
	}
	if (i == 1)
		dup = add_lc_complite1(dup, file, myfile);
	return (dup);
}

void	ft_display_cmp(t_char *l_char)
{
	int		i;
	int		j;
	int		k;

	if (l_char != NULL)
	{
		k = verify_last_lc(l_char);
		j = ft_my_sig_cmp_file(-1);
		if (j != -3 && k == 0)
		{
			i = verify_where_complite(l_char);
			if (i == 0)
				ft_dspl_cmp_file(l_char);
			else if (i == 1)
				ft_dspl_cmp_exe(l_char);
			else if (i == 2)
				ft_dspl_cmp_cmd(l_char);
			j++;
			ft_my_sig_cmp_file(j);
		}
		if (j == -3)
			ft_my_sig_cmp_file(0);
	}
}

void	ft_dspl_cmp_file(t_char *l_char)
{
	char	*dup;
	char	*way;
	char	*file;

	dup = send_my_char(l_char);
	if (ft_strchr(dup, '/') != NULL)
	{
		way = make_divise_way(dup);
		file = make_divise_file(dup);
		ft_display_file(way, file);
		free(way);
		free(file);
	}
	else
		ft_display_file(NULL, dup);
	free(dup);
}

void	ft_display_file(char *way, char *myfile)
{
	struct dirent	*file;
	DIR				*rep;
	t_cmds			*l_cmd;

	l_cmd = NULL;
	if (way == NULL)
		rep = opendir(".");
	else if (ft_strcmp(way, "") == 0)
		rep = opendir("/");
	else
		rep = opendir(way);
	if (rep != NULL)
	{
		while ((file = readdir(rep)))
			l_cmd = dsp_file_cmp(l_cmd, file->d_name, myfile);
		closedir(rep);
		if (l_cmd != NULL)
		{
			dsp_files(l_cmd);
			ft_free_lc(l_cmd);
		}
	}
}

t_cmds	*dsp_file_cmp(t_cmds *l_cmd, char *file, char *cmp)
{
	int		i;
	t_cmds	*new;

	i = 0;
	while (cmp[i] != '\0' && file[i] != '\0' && file[i] == cmp[i])
		i++;
	if (cmp[i] == '\0')
	{
		new = (t_cmds *)malloc(sizeof(t_cmds));
		new->str = ft_strdup(file);
		new->done = 0;
		new->after = NULL;
		l_cmd = dsp_file_cmp2(l_cmd, new);
	}
	return (l_cmd);
}
