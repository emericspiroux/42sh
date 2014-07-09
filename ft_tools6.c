/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:06:21 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/25 17:42:58 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		verify_last_lc(t_char *l_char)
{
	t_char	*tmp;

	if (l_char == NULL)
		return (1);
	tmp = l_char;
	while (tmp->after != NULL && tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	if (ft_isspace(tmp->c) == 1 && tmp->after == NULL)
		return (1);
	else if (ft_isspace(tmp->c) == 1 && ft_isspace(tmp->after->c) == 1)
		return (1);
	else
		return (0);
}

t_char	*verify_last_char(t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	while (tmp->befor != NULL && ft_isspace(tmp->befor->c) != 1)
		tmp = tmp->befor;
	return (tmp);
}

char	*make_lc_to_str(t_char *l_char)
{
	t_char	*tmp;
	char	*dup;
	int		i;

	i = 0;
	tmp = l_char;
	while (tmp != NULL && ft_isspace(tmp->c) != 1)
	{
		i++;
		tmp = tmp->after;
	}
	tmp = l_char;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (tmp != NULL && ft_isspace(tmp->c) != 1)
	{
		dup[i] = tmp->c;
		i++;
		tmp = tmp->after;
	}
	dup[i] = '\0';
	return (dup);
}

char	*send_my_char(t_char *l_char)
{
	t_char	*tmp;
	t_char	*tmp2;
	char	*dup;

	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	tmp2 = verify_last_char(tmp);
	dup = make_lc_to_str(tmp2);
	return (dup);
}
