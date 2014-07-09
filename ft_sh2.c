/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:08:52 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 15:54:04 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_exit(char *line)
{
	if (ft_strcmp(line, "exit") == 0)
		return (1);
	return (0);
}

void	make_my_builtin(char *line)
{
	if (ft_strcmp(line, "env") == 0)
		show_my_env();
	else if (verify_word(line, "cd") == 1)
		make_cd(make_arg2(line));
	else if (verify_word(line, "setenv") == 1)
	{
		if (ft_strcmp(line, "setenv") != 0)
			make_my_setenv(line);
		else
			error_un_set_few();
	}
	else if (verify_word(line, "unsetenv") == 1)
	{
		if (ft_strcmp(line, "unsetenv") != 0)
			make_my_unsetenv(line);
		else
			error_un_set_few();
	}
	else if (verify_word(line, "history") == 1)
		history(line);
	else if (verify_word(line, "alias") == 1)
		aliassing(line);
	else if (verify_word(line, "unalias") == 1)
		unaliassing(line);
	else if (verify_word(line, "echo") == 1)
			 make_echo(line);
	else
		make_my_way(line);
}

void	ft_make_add(char *line)
{
	line = make_propper_line(line);
	if (verify_char_str(line, ';') > 0)
		make_my_cmds(line);
	else
		make_and_or(line);
	free(line);
}

int		ft_sh2(char *line)
{
	char			buffer[2048];
	struct termios	term;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	if (*line)
		ft_make_add(line);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	return (0);
}
