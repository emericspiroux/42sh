/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_lc_char2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 20:14:17 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/09 20:34:53 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*first_of_lc(t_char *new)
{
	new->befor = NULL;
	new->after = NULL;
	return (new);
}

void	end_of_lc(t_char *tmp, t_char *new)
{
	tmp->b_prompt = 0;
	tmp->after = new;
	new->befor = tmp;
	new->after = NULL;
}

void	midle_of_lc(t_char *tmp, t_char *new)
{
	tmp->b_prompt = 0;
	tmp->after->befor = new;
	new->after = tmp->after;
	tmp->after = new;
	new->befor = tmp;
}

t_char	*start_of_lc(t_char *tmp, t_char *new)
{
	new->befor = NULL;
	tmp->befor = new;
	new->after = tmp;
	return (new);
}
