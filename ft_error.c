/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 21:53:43 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/07 16:46:33 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	error_file(char *file)
{
	ft_putstr_fd("42sh: file doesn't exist : ", 2);
	ft_putendl_fd(file, 2);
}

void	error_extra(char *str)
{
	ft_putstr_fd("42sh: parse error near `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}

void	error_unset_isnt(char *way)
{
	if (way)
	{
		ft_putstr_fd("unsetenv: no such env : ", 2);
		ft_putendl_fd(way, 2);
	}
}

void	error_unset(char *way)
{
	if (way)
	{
		ft_putstr_fd("un/setenv: Forbidden to write : ", 2);
		ft_putendl_fd(way, 2);
	}
}

void	error_isnt(char *way)
{
	ft_putstr_fd("cd: no such file or directory ", 2);
	ft_putstr_fd("or permission denied : ", 2);
	if (way)
		ft_putstr_fd(way, 2);
	ft_putchar_fd('\n', 2);
}
