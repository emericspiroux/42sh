/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 13:28:29 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 18:03:49 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_exit_circle(t_cmds *l_cmds, char *read)
{
	if (l_cmds == NULL)
		return (1);
	if (ft_strcmp(l_cmds->str, "exit") == 0)
		return (0);
	if (read[0] == 4)
		return (0);
	return (1);
}

t_cmds	*ft_read_char2(t_cmds *l_cmds, t_char *l_char, char *read_char)
{
	ft_print_liste(l_char, l_cmds);
	save_l_char(l_char, 1);
	if (read_char[0] == 9)
		ft_display_cmp(l_char);
	tputs(tgetstr("rc", NULL), 1, tputs_putchar);
	if (reset_history_sig(-1) == 1)
	{
		save_history_sig(NULL, -1);
		return (NULL);
	}
	return (l_cmds);
}

void	ft_read_char(t_char *l_char, t_cmds *l_cmds)
{
	char	read_char[6] = {0};

	while (ft_exit_circle(l_cmds, read_char) == 1)
	{
		ft_signal();
		ft_bzero(read_char, 5);
		read(0, read_char, 4);
		l_char = save_l_char(NULL, 0);
		if (read_char[0] == 4)
			exit(-1);
		if (read_char[0] == 10)
		{
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
			if (l_char != NULL)
			{
				l_cmds = make_my_line_cmd(l_char, l_cmds);
				l_char = free_liste_char(l_char);
				if (reset_history_sig(-1) == 1)
					l_cmds = ft_reset_cmds(l_cmds);
			}
		}
		else
			l_char = ft_path_char(read_char, l_char, l_cmds);
		l_cmds = ft_read_char2(l_cmds, l_char, read_char);
	}
}

int		main(void)
{
	char			buffer[2048];
	struct termios	term;

	make_my_env();
	g_son = 1;
	if (g_my_env != NULL)
	{
		if (tgetent(buffer, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		tcsetattr(0, 0, &term);
		ft_read_alias();
		make_my_prompt();
		ft_read_char(NULL, NULL);
		term.c_lflag |= ICANON;
		term.c_lflag |= ECHO;
		tcsetattr(0, 0, &term);
		ft_free_tab(g_my_env);
	}
	return (0);
}
