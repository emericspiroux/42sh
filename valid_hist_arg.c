/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_hist_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:22:47 by espiroux          #+#    #+#             */
/*   Updated: 2014/03/21 15:04:03 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	valid_hist_arg(char **argv, int argc, int begin, t_cmds *first_cmds)
{
	char	hash[OPT_NUM + 1];

	ft_memset(hash, '0', 4);
	hash[OPT_NUM] = '\0';
	if ((find_opt(hash, argv, argc)) >= 0)
	{
		apply_opt(hash, begin , argv, first_cmds);
	}
}

int		find_opt(char *hash, char **argv, int argc)
{
	int		i;
	int		j;
	int		h;

	i = 1;
	h = 0;
	while (i < argc)
	{
		j = 1;
		if (ft_strncmp(argv[i], "-", 1) == 0)
		{
			while (argv[i][j] != '\0')
			{
				if ((hash[h] = opt_hist(argv[i][j])) != '0')
					h++;
				else
					return (display_bad(argv[i][j]));
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	print_bad_opt(char a)
{
	ft_putstr("42sh: bad option: ");
	ft_putchar('-');
	ft_putchar(a);
	ft_putchar('\n');
	return ;
}

void	apply_opt(char *hash, int begin, char **argv, t_cmds *first_cmds)
{
	int		h;
	int		bool_count;
	char	*name;

	h = 0;
	bool_count = TRUE;
	name = NULL;
	while (hash[h] != '\0')
	{
		if (hash[h] == 'p' || hash[h] == 'r')
		{
			reset_cmds(first_cmds);
			return ;
		}
		else if (hash[h] == 'a')
		{
			if ((begin = search_history(name, first_cmds, argv)) == -1)
				return ;
		}
		else if (hash[h] == 'n')
			bool_count = FALSE;
		h++;
	}
	make_simple_history(begin, bool_count, first_cmds);
}

char	opt_hist(char letter)
{
	if (letter == 'n')
		return (letter);
	else if (letter == 'p')
		return (letter);
	else if (letter == 'r')
		return (letter);
	else if (letter == 'a')
		return (letter);
	else
		return ('0');
}
