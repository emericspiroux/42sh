/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:32:18 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/25 17:56:25 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "libft.h"

/*
** Macro for history error.
*/
# define LEN_VHIST 16
# define TRUE 1
# define FALSE 0
# define OPT_NUM 4

/*
** Macro for alias error.
*/
#define NO_EQUAL 1
#define NO_CMD 2
#define SPLIT_ERROR 3
#define SPLIT_ERROR2 7
#define SPLIT_ERROR3 8
#define ALIAS_EXIST 4
#define NO_ALIAS 6

extern char     **environ;
char			**g_my_env;
int				g_son;

typedef struct		s_alias
{
	char			*name;
	char			*cmd;
	struct s_alias	*next;
}					t_alias;

typedef struct		s_cmds
{
	char			*str;
	char			type;
	int				done;
	struct s_cmds	*after;
	struct s_cmds	*befor;
}					t_cmds;

typedef struct		s_char
{
	char			c;
	int				b_prompt;
	int				a_prompt;
	struct s_char	*after;
	struct s_char	*befor;
}					t_char;

/*
**ft_error.c
*/
void	error_file(char *file);
void	error_extra(char *str);
void	error_unset_isnt(char *way);
void	error_unset(char *way);
void	error_isnt(char *way);
/*
**ft_error2.c
*/
void	error_un_set_few(void);
void	error_env(void);
void	error_cmd(char *line);
/*
**ft_un_set_env.c
*/
char	**ft_realloc_tab(char **env);
char	**ft_realloc_tab_m(char **env, int k);
int		make_verify_setenv(char *line);
void	make_my_unsetenv(char *line);
void	make_my_setenv(char *line);
/*
**ft_un_set_env2.c
*/
void	make_my_setenv2(char **tab);
void	make_my_setenv3(char **tab, char *str, int i);
/*
**ft_verify.c
*/
char	*way_to_home(char *way);
int		get_line_env(char *str);
int		verify_space(char c);
int		verify_word(char *s1, char *s2);
int		verify_char_str(char *str, char c);
/*
**ft_sh2.c
*/
int		ft_exit(char *line);
void	make_my_builtin(char *line);
void	ft_make_add(char *line);
int		ft_sh2(char *line);
/*
**make_my_arg.c
*/
char	**make_arg2(char *line);
char	**make_arg(char *line);
char	*make_line(char *line, char *path);
char	*cut_fs(char *line);
void	make_my_cmds(char *cmds_str);
/*
**make_my_cd.c
*/
void	make_pwd_to_old(void);
void	make_d_cd(char *way);
void	make_old_cd(void);
void	make_just_cd(void);
void	make_cd(char **av);
/*
**make_my_cd2.c
*/
char	*add_dir_way(char *way, char *dir);
char	*cut_last_dir(char *way);
int		count_a_char(char *str, char c);
void	make_cd_1arg(char *way, char **av);
void	make_cd_2arg(char *way, char **av);
/*
**make_my_cd3.c
*/
char	*make_cd_1arg2(char *way, char **av);
char	*make_cd_2arg2(char *way, char **av);
/*
**minishell.c
*/
void	make_my_shell(char *line, char **av);
void	make_my_shell1_2(char *line, char **av, char **path);
void	make_my_sehll2(char *line, char **av);
/*
**way_path_env.c
*/
char	*find_my_way(char *str);
char	*cut_rab(char *line);
char	**find_my_path(char *str);
void	make_my_way(char *line);
void	show_my_env(void);
/*
**ft_tools1.c
*/
t_cmds	*verify_my_parser(t_cmds *cmds);
char	*make_propper_line(char *str);
int		ft_strlen_propper(char *str);
int		ft_strlen_isspace(char *str);
void	ft_free_tab(char **tab);
/*
**ft_isspace.c
*/
int		ft_isspace(char c);
char	*ft_replace_isspace(char *str);
char	*ft_cut_multi_space(char *str);
char	*ft_cut_last_space(char *str);
char	*ft_cut_some_space(char *str, char c);
/*
**verify_pipe_and_ci.c
*/
int		verify_pipe_and_ci(char *str);
void	make_my_extra(char *str);
char	ft_my_lexer(char c, char d);
t_cmds	*ft_make_lc(t_cmds *cmds, char *str, char type);
t_cmds	*ft_strsplit_lc(char *cm);
/*
**ft_tools2.c
*/
t_cmds	*ft_my_lexer_1(t_cmds *cmds, char c);
t_cmds	*ft_my_lexer_2(t_cmds *cmds, char c);
t_cmds	*ft_my_lexer_3(t_cmds *cmds, char *cm, int i);
void	ft_print_lc(t_cmds *cmds);
t_cmds	*ft_my_parser(t_cmds *cmds);
/*
**ft_tools3.c
*/
void	ft_free_lc(t_cmds *cmds);
t_cmds	*ft_init_cmds(t_cmds *cmds);
int		ft_verify_pipe(t_cmds *cmds);
int		ft_verify_dir(t_cmds *cmds);
/*
**ft_tools4.c
*/
t_cmds	*ft_re_set(t_cmds *cmds);
char	*propper_my_line(char *str);
int		ft_verify_all_pipe(t_cmds *tmp);
int		ft_count_liste(t_char *l_char);
int		ft_verify_cmds(t_cmds *l_cmds);
/*
**ft_pipex.c
*/
void	set_cmds(t_cmds *cmds);
void	make_my_pipe_in(t_cmds *cmds, int tabfd[2]);
void	make_my_pipe_out(int father, t_cmds *cmds, int tabfd[2]);
void	ft_my_pipe(t_cmds *cmds);
void	ft_my_pipe2(t_cmds *cmds, int tabfd[2]);
/*
**ft_my_dir.c
*/
void	my_dir_sio(t_cmds *cmds);
void	my_dir_soi(t_cmds *cmds);
void	ft_make_my_dir(t_cmds *cmds);
void	make_sio(t_cmds *cmds, int fdo);
void	make_soi(t_cmds *cmds, int fdi);
/*
**ft_my_dir.c
*/
void	make_dio(t_cmds *cmds, int fdo);
void	my_dir_dio(t_cmds *cmds);
/*
**ft_select.c
*/
int		tputs_putchar(int c);
int		ft_exit_circle(t_cmds *l_cmds, char *read);
void	ft_read_char(t_char *l_char, t_cmds *l_cmds);
t_cmds	*ft_read_char2(t_cmds *l_cmds, t_char *l_char, char *read_char);
/*
**ft_make_line_cmd.c
*/
t_cmds	*make_my_line_cmd(t_char *l_char, t_cmds *l_cmds);
/*
**ft_move_my_cmds.c
*/
t_char	*ft_move_my_cmds(int touch, t_cmds *l_cmds, t_char *l_char);
t_char	*ft_move_my_cmds2(int touch, t_cmds *l_cmds, t_char *l_char);
t_char	*ft_move_my_cmds3(t_cmds *l_cmds, t_char *l_char);
/*
**ft_my_move.c
*/
void	move_left_char(t_char *l_char);
void	move_right_char(t_char *l_char);
void	move_on_char(int touch, t_char *l_char);
/*
**ft_path_char.c
*/
t_char	*ft_path_char3(char *read, t_char *l_char, t_cmds *l_cmds);
t_char	*ft_path_char2(char *read, t_char *l_char, t_cmds *l_cmds);
t_char	*ft_path_char(char *read, t_char *l_char, t_cmds *l_cmds);
t_char	*ft_make_my_tab(t_char *l_char, char *read);
/*
**ft_tools5.c
*/
t_char	*free_liste_one_char(t_char *l_char);
t_char	*free_liste_char(t_char *l_char);
int		verify_dir_char(char *read);
void	ft_clear_liste_cmds(t_cmds *l_cmds);
void	ft_clear_liste_char(t_char *l_char);
/*
**make_my_lc_char.c
*/
t_cmds	*make_my_lc_cmds(char *line, t_cmds *l_cmds);
t_char	*ft_make_lc_char(char *str, t_char *l_char);
t_char	*make_my_lc_char(char c, t_char *l_char);
void	ft_print_liste(t_char *l_char, t_cmds *l_cmds);
void	ft_print_liste2(t_char *l_char);
/*
**ft_sup_home_end.c
*/
t_char	*sup_one_char(int touch, char *read, t_char *l_char);
void	ft_home_and_end(int touch, t_char *l_char);
t_char	*ft_del_befor(t_char *l_char);
t_char	*ft_del_after(t_char *l_char);
/*
**make_my_lc_char2.c
*/
t_char	*first_of_lc(t_char *new);
void	end_of_lc(t_char *tmp, t_char *new);
void	midle_of_lc(t_char *tmp, t_char *new);
t_char	*start_of_lc(t_char *tmp, t_char *new);
/*
**ft_signal.c
*/
void	ft_signal(void);
void	sig_new_line(int sig);
void	sigexit(int sig);
void	sig_sleep(int sig);
void	sig_resize(int sig);
/*
**ft_and_or.c
*/
int		verify_op(char c, char d);
t_cmds	*make_lc_or_and2(t_cmds *l_cmds, t_cmds *new);
t_cmds	*make_lc_or_and(t_cmds *l_cmds, char *str, char c);
void	ft_my_and_or(t_cmds *l_cmds);
void	make_and_or(char *line);
/*
**ft_tools6.c
*/
int		verify_last_lc(t_char *l_char);
t_char	*verify_last_char(t_char *l_char);
char	*make_lc_to_str(t_char *l_char);
char	*send_my_char(t_char *l_char);
/*
**ft_tools7.c
*/
char	*make_divise_way(char *line);
char	*make_divise_file(char *line);
void	add_my_lc_complite(char c, t_char *tmp);
int		verify_where_complite(t_char *l_char);
void	dsp_files3(t_cmds *l_cdm);
/*
**ft_auto_complite.c
*/
t_char	*ft_my_complite(t_char *l_char);
t_char	*ft_auto_complite(t_char *l_char);
t_char	*add_lc_complite(t_char *l_char, char *way, char *myfile);
char	*add_lc_complite1(char *cmp, char *file, char *myin);
char	*add_lc_complite12(char *cmp, char *file, char *myin);
/*
**ft_auto_complite2.c
*/
t_char	*add_lc_complite2(t_char *l_char, char *cmp, char *old, char *way);
t_char	*add_lc_complite21(t_char *l_char, char *cmp, char *old, int type);
t_char	*ft_auto_cmp_cmd(t_char *l_char);
t_char  *add_lc_cmp_cmd(t_char *l_char, char *way, char *myfile);
char	*add_lc_cmp_cmd2(char *file, char *way, char *myfile, char *dup);
/*
**ft_auto_complite3.c
*/
t_char	*add_lc_cmp_cmd3(t_char *l_char, char *myfile, char *way);
char	*add_lc_cmp_cmd4(char *dup, char *way, char *myfile);
char	*add_lc_cmp_cmd5(char *dup, char *way, char *myfile, char *file);
t_char	*ft_auto_cmp_exe(t_char *l_char);
t_char	*ft_auto_cmp_exe2(t_char *l_char, char *way, char *myfile);
/*
**ft_auto_complite4.c
*/
char	*ft_auto_cmp_exe3(char *dup, char *way, char *file, char * myfile);
void	ft_display_cmp(t_char *l_char);
void	ft_dspl_cmp_file(t_char *l_char);
void	ft_display_file(char *way, char *myfile);
t_cmds	*dsp_file_cmp(t_cmds *l_cmd, char *file, char *cmp);
/*
**ft_auto_complite5.c
*/
t_cmds	*dsp_file_cmp2(t_cmds *l_cmd, t_cmds *new);
t_cmds	*dsp_file_cmp3(t_cmds *l_cmd, t_cmds *new);
void	ft_dspl_cmp_cmd(t_char *l_char);
t_cmds	*ft_display_cmd(t_cmds *l_cmd, char *way, char *myfile);
int		ft_display_cmd2(char *way, char *file);
/*
**ft_auto_complite6.c
*/
t_cmds	*ft_display_cmd3(t_cmds *l_cmd, char *myfile);
void	ft_dspl_cmp_exe(t_char *l_char);
void	ft_display_exe(char *way, char *myfile);
t_cmds	*ft_display_exe2(char *way, char *file, char *myfile, t_cmds *l_cmd);
/*
**ft_tools8.c
*/
int		display_bad(char c);
void	dsp_cmds(t_cmds *l_cmd);
void	dsp_files2(t_cmds *l_cmd);
void	dsp_files(t_cmds *l_cmd);
void	ft_bintoperm(char *str, char *cm);
/*
**ft_isx.c
*/
int		ft_isx(char *file);
char	*ft_lspermi(int c);
char	*ft_dtob(int c);
int		ft_lsrmtype(int c);
char	ft_lsistype(int c);
/*
**prompt.c
*/
void	make_my_prompt(void);
void	my_prompt(char *pwd, char *home, char *str);
/*
**ft_my_signal.c
*/
int		ft_my_sig_cmp_file(int sig);
int		ft_my_sig_cmp_file2(int sig);
int		reset_history_sig(int sig);
t_cmds	*save_history_sig(t_cmds *l_cmd, int sig);
int		save_lines_print(int lines, int sig);
/*
**env.c
*/
void	check_path(void);
char	*check_path2(char **path, char *str, int j);
void	make_my_env(void);
void	make_my_home(void);
/*
**history.c
*/
void	history(char *line);
t_cmds	*find_first_cmds(t_cmds *cmds);
int		adjust_history(t_cmds *first_cmds);
int		count_arg(char **argv);
/*
**make_simple_history.c
*/
void	make_simple_history(int begin, int bool_count, t_cmds *first_cmds);
void	ft_space(int count);
void	no_history(t_cmds *pcurs, int bool_count);
/*
**valid_hist_arg.c
*/
void	valid_hist_arg(char **argv, int argc, int begin, t_cmds *first_cmds);
int		find_opt(char *hash, char **argv, int argc);
void	print_bad_opt(char a);
void	apply_opt(char *hash, int begin, char **argv, t_cmds *first_cmds);
/*
**search_history.c
*/
void	reset_cmds(t_cmds *first_cmds);
int		search_history(char *name, t_cmds *first_cmds, char **argv);
char	*find_name(char **argv);
int		find_cmds(char *name, t_cmds *first_cmds);
char	opt_hist(char letter);
/*
**ft_count_split.c
*/
int		count_stars_noway(char *str);
int		count_stars_way(char *str);
int		ft_count_stars(char *str);
int		ft_count_malloc(char *str, char cut);
/*
**ft_make_split.c
*/
void	make_stars_noway(char **tab, char *str, int i[2]);
void	make_stars_way(char **tab, char *str, int i[2]);
void	ft_split_stars(char **tab, char *str, int i[2]);
void	ft_split_word(char **tab, char *str, int i[2]);
char	**ft_make_split(char **tab, char *str, char cut);
/*
**ft_strsplit_stars.c
*/
char	**ft_strsplit_stars(char *str, char cut);
/*
**ft_tools9.c
*/
int		verify_stars(char *str, char cut, int i);
int		ft_count_word(char *str, char cut, int i);
int		ft_count_char(char *str, char cut, int i);
char	*make_str(char *str, char cut, int i);
t_cmds	*ft_reset_cmds(t_cmds *l_cmds);
/*
**ft_my_signal2.c
*/
int		prompt_print_nb(int prompt);
int		liste_print_nb(int liste);
int		all_liste_print_nb(int liste);
t_char	*save_l_char(t_char *l_char, int sig);
int		reset_line_sig(int reset, int sig);
/*
**ft_my_signal3.c
*/
t_alias	*ft_my_sig_alias(t_alias *l_alias, int sig);
int		ft_my_sig_resize(int sig);
/*
**ft_tools10.c
*/
void	ft_read_answer(t_cmds *l_cmd, int i);
void	replace_cursor(int lines);
void	verify_line_term(void);
char	*ft_getpwd(char *cmp);
int		get_old_n_pwd(int i);
/*
**ft_tools11.c
*/
void	ft_free_one_alias(t_alias *prev, t_alias *del);
void	ft_free_lc_alias(t_alias *l_alias);
/*
**ft_read_alias.c
*/
void	ft_read_alias(void);
t_alias	*make_lc_alias(t_alias *l_alias, char *alias, char *cmd);
/*
**aliassing.c
*/
int		verify_no_exist_alias(char **alias);
void	aliassing(char *line);
int		splitalias(char *line, char **alias, char **cmd);
int		verify_alias(char *line, char **alias, char **cmd);
void	create_my_alias(int argc, char **argv);
int		ft_error_alias(int error, char *cmd);
int		putalias(char *alias, char *cmd);
char	*cut_quote(char *s);
void	show_alias(void);
/*
**unaliassing.c
*/
void		unaliassing(char *line);
int			ft_error_unalias(int error, char *name);
void		uncreate_my_alias(int argc, char **argv);
void		erase_all_alias(void);
void		erase_one_alias(char *alias);
/*
**ft_echo.c
*/
void		make_echo(char *line);

#endif
