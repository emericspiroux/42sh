/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 20:21:55 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:36:37 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		display_bad(char c)
{
	print_bad_opt(c);
	return (-1);
}

void	dsp_cmds(t_cmds *l_cmd)
{
	if (l_cmd != NULL)
	{
		dsp_files(l_cmd);
		ft_free_lc(l_cmd);
	}
}

void	dsp_files2(t_cmds *l_cmd)
{
	t_cmds	*tmp;
	int		i;

	tmp = l_cmd;
	i = 1;
	if (tmp != NULL)
	{
		ft_putchar('\n');
		while (tmp != NULL)
		{
			if (tmp->str[0] != '.')
			{
				ft_putstr(tmp->str);
				ft_putchar('\n');
				i++;
			}
			tmp = tmp->after;
		}
		save_lines_print(i, 1);
	}
}

void	dsp_files(t_cmds *l_cmd)
{
	struct winsize		*term_sizes;
	size_t				max_row;
	size_t				i;
	t_cmds				*tmp;

	i = 0;
	term_sizes = (struct winsize *)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, term_sizes);
	max_row = term_sizes->ws_row;
	while (l_cmd->befor != NULL)
		l_cmd = l_cmd->befor;
	tmp = l_cmd;
	while (tmp != NULL)
	{
		tmp = tmp->after;
		i++;
	}
	if (i > max_row)
		ft_read_answer(l_cmd, i);
	else
		dsp_files3(l_cmd);
}

void	ft_bintoperm(char *str, char *cm)
{
	if ((cm[0]) == '1')
		str[0] = 'r';
	if ((cm[1]) == '1')
		str[1] = 'w';
	if ((cm[2]) == '1')
		str[2] = 'x';
	if ((cm[3]) == '1')
		str[3] = 'r';
	if ((cm[4]) == '1')
		str[4] = 'w';
	if ((cm[5]) == '1')
		str[5] = 'x';
	if ((cm[6]) == '1')
		str[6] = 'r';
	if ((cm[7]) == '1')
		str[7] = 'w';
	if ((cm[8]) == '1')
		str[8] = 'x';
	str[9] = '\0';
}
