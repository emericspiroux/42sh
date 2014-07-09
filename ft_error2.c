/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:40:23 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/07 16:47:17 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	error_un_set_few(void)
{
	ft_putendl_fd("un/setenv: too few arguments.", 2);
}

void	error_cmd(char *line)
{
	ft_putstr_fd("42sh: Error: command not found : ", 2);
	ft_putendl_fd(line, 2);
}

