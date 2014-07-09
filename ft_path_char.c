/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:56:53 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/22 15:16:40 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_char	*ft_path_char3(char *read, t_char *l_char, t_cmds *l_cmds)
{
	int		j;

	j = verify_dir_char(read);
	if (j == 1 ||j == 2)
	{
		if (l_char != NULL)
			move_on_char(j, l_char);
	}
	else if (j == 3 || j == 4)
	{
		if (l_cmds != NULL)
			l_char = ft_move_my_cmds(j, l_cmds, l_char);
	}
	return (l_char);
}

t_char	*ft_path_char2(char *read, t_char *l_char, t_cmds *l_cmds)
{
	int		i;

	i = verify_dir_char(read);
	if (read[0] == 127 || i == 7)
	{
		if (l_char != NULL)
			l_char = sup_one_char(i, read, l_char);
	}
	else if (i == 5 || i == 6)
	{
		if (l_char != NULL)
			ft_home_and_end(i, l_char);
	}
	else
		l_char = ft_path_char3(read, l_char, l_cmds);
	return (l_char);
}

t_char	*ft_path_char(char *read, t_char *l_char, t_cmds *l_cmds)
{
	if (read[0] < 127 && read[1] == '\0')
	{
		if (read[0] == 9)
			l_char = ft_make_my_tab(l_char, read);
		else
		{
			l_char = make_my_lc_char(read[0], l_char);
			ft_my_sig_cmp_file(-2);
		}
	}
	else
	{
		l_char = ft_path_char2(read, l_char, l_cmds);
		ft_my_sig_cmp_file(-2);
	}
	return (l_char);
}

t_char	*ft_make_my_tab(t_char *l_char, char *read)
{
	int	i;

	i = -1;
	if (l_char != NULL)
		i = verify_last_lc(l_char);
	else
	{
		l_char = make_my_lc_char(read[0], l_char);
		ft_my_sig_cmp_file(-2);
	}
	if (i == 0)
		l_char = ft_my_complite(l_char);
	else if (i == 1)
	{
		l_char = make_my_lc_char(read[0], l_char);
		ft_my_sig_cmp_file(-2);
	}
	return (l_char);
}
