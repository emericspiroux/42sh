/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:14:01 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/18 20:59:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*make_divise_way(char *line)
{
	char	*way;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (line[i] != '\0')
	{
		if (line[i] == '/')
			j = i;
		i++;
	}
	way = (char *)malloc(sizeof(char) * (j + 1));
	i = 0;
	while (i < j)
	{
		way[i] = line[i];
		i++;
	}
	way[j] = '\0';
	return (way);
}

char	*make_divise_file(char *line)
{
	char	*file;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	file = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '/')
			tmp = line + i + 1;
		i++;
	}
	if (tmp != NULL || tmp != '\0')
		file = ft_strdup(tmp);
	return (file);
}

void	add_my_lc_complite(char c, t_char *tmp)
{
	t_char	*new;
	t_char	*tmp2;

	tmp2 = tmp->after;
	new = (t_char *)malloc(sizeof(t_char));
	new->c = c;
	tmp->b_prompt = 0;
	new->b_prompt = 1;
	new->after = tmp2;
	if (tmp2 != NULL)
		tmp2->befor = new;
	new->befor = tmp;
	tmp->after = new;
}

int		verify_where_complite(t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	while (tmp->befor != NULL && tmp->c != '/'
		&& ft_isspace(tmp->befor->c) != 1)
		tmp = tmp->befor;
	if (tmp->c == '/' && tmp->befor != NULL
		&& tmp->befor->c == '.')
		return (1);
	while (tmp->befor != NULL && ft_isspace(tmp->befor->c) != 1)
		tmp = tmp->befor;
	while (tmp->befor != NULL && ft_isspace(tmp->befor->c) == 1)
		tmp = tmp->befor;
	if (tmp->befor == NULL || tmp->befor->c == '|' || tmp->befor->c == ';')
		return (2);
	if (tmp->befor->c == '&')
		return (2);
	return (0);
}

void	dsp_files3(t_cmds *l_cmd)
{
	t_char	*l_char;

	dsp_files2(l_cmd);
	replace_cursor(save_lines_print(0, 0));
	l_char = save_l_char(NULL, 0);
	reset_line_sig(1, 1);
	ft_print_liste(l_char, NULL);
}
