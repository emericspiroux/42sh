/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_stars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:51:12 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/18 15:19:39 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_strsplit_stars(char *str, char cut)
{
	int		i;
	char	**tab;

	i = ft_count_malloc(str, cut);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab = ft_make_split(tab, str, cut);
	return (tab);
}
