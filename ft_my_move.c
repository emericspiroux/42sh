/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 18:25:36 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/12 18:15:19 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	move_left_char(t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	ft_clear_liste_char(tmp);
	tmp->a_prompt = 1;
	if (tmp->befor != NULL)
		tmp->befor->b_prompt = 1;
}

void	move_right_char(t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	if (tmp->b_prompt == 1 && tmp->after != NULL)
	{
		ft_clear_liste_char(tmp);
		tmp->after->b_prompt = 1;
		if (tmp->after->after != NULL)
			tmp->after->after->a_prompt = 1;
	}
	else if (tmp->a_prompt == 1)
	{
		tmp->a_prompt = 0;
		tmp->b_prompt = 1;
		if (tmp->after != NULL)
			tmp->after->a_prompt = 1;
	}
}

void	move_on_char(int touch, t_char *l_char)
{
	t_char	*tmp;

	tmp = l_char;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	while (tmp->b_prompt != 1 && tmp->a_prompt != 1)
		tmp = tmp->after;
	if (touch == 1)
		move_left_char(tmp);
	else if (touch == 2)
		move_right_char(tmp);
}
