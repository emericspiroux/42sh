/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:34:22 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 18:03:30 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_signal(void)
{
	signal(SIGQUIT, sig_sleep);
	signal(SIGSTOP, sig_sleep);
	signal(SIGTSTP, sig_sleep);
	signal(SIGCONT, sigexit);
	signal(SIGWINCH, sig_resize);
	signal(SIGINT, sig_new_line);
}

void	sig_new_line(int sig)
{
	t_char	*l_char;

	l_char = save_l_char(NULL, 0);
	if (l_char != NULL)
		free_liste_char(l_char);
	save_l_char(NULL, -1);
	(void)sig;
	signal(SIGINT, sig_new_line);
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
	make_my_prompt();
}

void	sigexit(int sig)
{
	struct termios	term;

	(void)sig;
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	ft_free_tab(g_my_env);
	exit(0);
}

void	sig_sleep(int sig)
{
	(void)sig;
}

void	sig_resize(int sig)
{
	t_char				*l_char;

	ft_my_sig_resize(1);
	l_char = save_l_char(NULL, 0);
	ft_print_liste(l_char, NULL);
	(void)sig;
}
