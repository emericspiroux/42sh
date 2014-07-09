/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_lc_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:02:55 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/21 18:44:46 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_cmds	*make_my_lc_cmds(char *line, t_cmds *l_cmds)
{
	t_cmds	*new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	new->str = ft_strdup(line);
	new->done = 0;
	new->befor = NULL;
	free(line);
	if (l_cmds == NULL)
	{
		new->after = NULL;
		l_cmds = new;
	}
	else
	{
		new->after = l_cmds;
		l_cmds->befor = new;
		l_cmds = new;
	}
	return (l_cmds);
}

t_char	*ft_make_lc_char(char *str, t_char *l_char)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		l_char = make_my_lc_char(str[i], l_char);
		i++;
	}
	return (l_char);
}

t_char	*make_my_lc_char(char c, t_char *l_char)
{
	t_char	*new;
	t_char	*tmp;

	new = (t_char *)malloc(sizeof(t_char));
	new->b_prompt = 1;
	new->c = c;
	new->a_prompt = 0;
	if (l_char == NULL)
		l_char = first_of_lc(new);
	else
	{
		tmp = l_char;
		while (tmp->after != NULL && tmp->b_prompt != 1 && tmp->a_prompt != 1)
			tmp = tmp->after;
		if (tmp->after == NULL)
			end_of_lc(tmp, new);
		else if (tmp->b_prompt == 1)
			midle_of_lc(tmp, new);
		else if (tmp->a_prompt == 1)
			l_char = start_of_lc(tmp, new);
	}
	return (l_char);
}


void	ft_print_liste(t_char *l_char, t_cmds *l_cmds)
{
	t_char	*tmp;

	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	verify_line_term();
	if (reset_line_sig(0, 0) != 1)
		tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	else
		reset_line_sig(0, -1);
	if (l_cmds == NULL || ft_strcmp(l_cmds->str, "exit") != 0)
		make_my_prompt();
	if (l_char != NULL)
	{
		tmp = l_char;
		while (tmp->befor != NULL)
			tmp = tmp->befor;
		ft_print_liste2(l_char);
	}
	else
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
}

void	ft_print_liste2(t_char *l_char)
{
	t_char	*tmp;
	int		i;

	i = 0;
	tmp = l_char;
	while (tmp != NULL)
	{
		if (tmp->a_prompt == 1)
		{
			liste_print_nb(i);
			tputs(tgetstr("sc", NULL), 1, tputs_putchar);
		}
		ft_putchar(tmp->c);
		i++;
		if (tmp->b_prompt == 1)
		{
			liste_print_nb(i);
			tputs(tgetstr("sc", NULL), 1, tputs_putchar);
		}
		tmp = tmp->after;
	}
	all_liste_print_nb(i);
}
