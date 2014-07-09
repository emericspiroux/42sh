/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:17:29 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/17 19:18:46 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*make_my_line_cmd(t_char *l_char, t_cmds *l_cmds)
{
	t_char	*tmp;
	char	*line;
	int		i;
	int		j;

	i = 0;
	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	j = ft_count_liste(tmp);
	line = (char *)malloc(sizeof(char) * (j + 1));
	while (tmp != NULL)
	{
		line[i] = tmp->c;
		tmp = tmp->after;
		i++;
	}
	line[i] = '\0';
	l_cmds = make_my_lc_cmds(line, l_cmds);
	if (ft_strcmp(l_cmds->str, "exit") != 0)
		ft_sh2(l_cmds->str);
	ft_clear_liste_cmds(l_cmds);
	ft_my_sig_cmp_file(-2);
	save_history_sig(l_cmds, 1);
	return (l_cmds);
}
