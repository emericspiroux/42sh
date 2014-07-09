/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:21:42 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/23 15:33:41 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_read_answer(t_cmds *l_cmd, int i)
{
	char	read_char[6] = {0};
	t_char	*l_char;

	ft_putstr("\n42sh: do you wish to see all (");
	ft_putnbr(i);
	ft_putstr(") possibilities ? [y/n] : ");
	ft_bzero(read_char, 5);
	read(0, read_char, 4);
	if (read_char[0] == 121)
	{
		dsp_files2(l_cmd);
		tputs(tgetstr("ll", NULL), 1, tputs_putchar);
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
		l_char = save_l_char(NULL, 0);
		ft_print_liste(l_char, NULL);
		save_lines_print(0, -1);
	}
	else
		replace_cursor(1);
}

void	replace_cursor(int lines)
{
	int		prompt;
	int		liste;
	int		all;

	prompt = prompt_print_nb(-1);
	liste = liste_print_nb(-1);
	all = prompt + liste;
	while (lines != 0)
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		lines--;
	}
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	while (all != 0)
	{
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		all--;
	}
	tputs(tgetstr("sc", NULL), 1, tputs_putchar);
}

void	verify_line_term(void)
{
	int					wr;
	int					i;
	struct winsize		*term_sizes;
	size_t				max_col;

	term_sizes = (struct winsize *)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, term_sizes);
	max_col = term_sizes->ws_col;
	wr = prompt_print_nb(-1) + all_liste_print_nb(-1) - 1;
	if (ft_my_sig_resize(-1) == 1)
	{
		wr = wr + 1;
		ft_my_sig_resize(0);
	}
	i = wr / (int)max_col;
	while (i > 0)
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		i--;
	}
	free(term_sizes);
}

int		get_old_n_pwd(int i)
{
	if (strncmp(environ[i], "OLDPWD=", 7) == 0)
		g_my_env[i] = ft_getpwd("OLDPWD=");
	else if (strncmp(environ[i], "PWD=", 4) == 0)
		g_my_env[i] = ft_getpwd("PWD=");
	else
		g_my_env[i] = ft_strdup(environ[i]);
	return (i + 1);
}

char	*ft_getpwd(char *cmp)
{
	char			*pwd;
	char			*pwd2;

	pwd = (char *)malloc(sizeof(char) * 1024);
	getcwd(pwd, 1024);
	pwd2 = ft_strjoin(cmp, pwd);
	free(pwd);
	return (pwd2);
}
