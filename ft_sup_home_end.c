/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup_home_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:21:58 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/09 21:07:11 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*ft_del_befor(t_char *l_char)
{
	t_char	*del;

	if (l_char != NULL)
	{
		del = l_char;
		while (l_char->befor != NULL)
			l_char = l_char->befor;
		if (del == l_char)
		{
			l_char = l_char->after;
			if (l_char != NULL)
				l_char->befor = NULL;
			free(del);
		}
		else
		{
			del->befor->b_prompt = 1;
			del->befor->after = del->after;
			if (del->after != NULL)
				del->after->befor = del->befor;
			free(del);
		}
	}
	return (l_char);
}

t_char	*ft_del_after(t_char *l_char)
{
	t_char	*del;

	if (l_char != NULL)
	{
		del = l_char;
		while (l_char->befor != NULL)
			l_char = l_char->befor;
		if (del == l_char)
		{
			l_char = l_char->after;
			if (l_char != NULL)
				l_char->befor = NULL;
			free(del);
		}
		else
		{
			del->befor->after = del->after;
			if (del->after != NULL)
				del->after->befor = del->befor;
			free(del);
		}
	}
	return (l_char);
}

t_char	*sup_one_char(int touch, char *read, t_char *l_char)
{
	t_char	*tmp;

	while (l_char->befor != NULL)
		l_char = l_char->befor;
	tmp = l_char;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	if (read[0] == 127 && read[1] == '\0' && tmp->b_prompt == 1)
		l_char = ft_del_befor(tmp);
	else if (touch == 7 && tmp->after != NULL)
	{
		if (tmp->b_prompt == 1)
			tmp = tmp->after;
		if (tmp->after != NULL)
			tmp->after->a_prompt = 1;
		l_char = ft_del_after(tmp);
	}
	return (l_char);
}

void	ft_home_and_end(int touch, t_char *l_char)
{
	t_char	*tmp;

	while (l_char->befor != NULL)
		l_char = l_char->befor;
	tmp = l_char;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	tmp->b_prompt = 0;
	tmp->a_prompt = 0;
	if (tmp->after != NULL)
		tmp->after->a_prompt = 0;
	if (touch == 5)
	{
		tmp = l_char;
		while (tmp->after != NULL)
			tmp = tmp->after;
		tmp->b_prompt = 1;
	}
	else if (touch == 6)
		l_char->a_prompt = 1;
}
