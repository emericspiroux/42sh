#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:38:09 by rduclos           #+#    #+#              #
#    Updated: 2014/03/25 17:01:09 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 		42sh

SRC =	ft_error.c ft_un_setenv.c ft_verify.c ft_sh2.c make_my_arg.c \
		make_my_cd.c make_my_cd2.c minishell.c way_path_env.c \
		ft_tools1.c ft_isspace.c verify_pipe_and_ci.c ft_tools2.c \
		ft_tools3.c ft_pipex.c ft_my_dir.c make_my_lc_char2.c \
		ft_make_line_cmd.c ft_move_my_cmds.c ft_path_char.c ft_select.c \
		ft_tools4.c ft_tools5.c make_my_lc_char.c ft_my_move.c \
		ft_sup_home_end.c ft_my_dir2.c ft_signal.c ft_error2.c \
		make_my_cd3.c ft_and_or.c ft_un_setenv2.c ft_tools6.c \
		ft_tools7.c ft_auto_complite.c ft_isx.c ft_tools8.c prompt.c \
		ft_auto_complite2.c ft_auto_complite3.c ft_my_signal.c \
		ft_auto_complite4.c ft_auto_complite5.c ft_auto_complite6.c env.c \
		history.c make_simple_history.c search_history.c valid_hist_arg.c \
		ft_count_split.c ft_make_split.c ft_strsplit_stars.c ft_tools9.c \
		ft_tools10.c ft_my_signal2.c ft_my_signal3.c aliassing.c aliassing2.c \
		ft_read_alias.c unaliassing.c ft_tools11.c verify_no_exist_alias.c \
		ft_echo.c

FLAGS = 	-Wall -Wextra -Werror -O2

LIB = 		-L libft -lft -L /usr/lib -ltermcap

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(SRC) -I. $(LIB) -I libft/ -g

clean:
	make -C libft clean
	clear

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
	clear
