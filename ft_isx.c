/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftabarie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:13:45 by ftabarie          #+#    #+#             */
/*   Updated: 2014/03/11 19:50:07 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int					ft_isx(char *file2)
{
	struct stat		file;
	char			*per;
	char			d;

	stat(file2, &file);
	d = ft_lsistype(file.st_mode);
	if (d == 'd')
		return (2);
	per = ft_lspermi(file.st_mode);
	if (per[2] == 'x')
	{
		free(per);
		return (1);
	}
	free(per);
	return (0);
}

char				*ft_lspermi(int c)
{
	char			*str;
	char			*cm;

	cm = ft_dtob(ft_lsrmtype(c));
	str = (char *)malloc(sizeof(char) * 10);
	ft_memset(str, '-', 10);
	ft_bintoperm(str, cm);
	free(cm);
	return (str);
}

char				*ft_dtob(int c)
{
	char			*str;
	int				nb;
	int				i;

	nb = 256;
	i = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (i != 9)
	{
		if (c >= nb)
		{
			str[i] = '1';
			c = c - nb;
		}
		else
			str[i] = '0';
		i++;
		nb = nb / 2;
	}
	str[i] = '\0';
	return (str);
}

int					ft_lsrmtype(int c)
{
	int				nb;

	nb = c;
	if ((nb - 32768) >= 0)
		nb = nb - 32768;
	if ((nb - 16384) >= 0)
		nb = nb - 16384;
	if ((nb - 8192) >= 0)
		nb = nb - 8192;
	if ((nb - 4096) >= 0)
		nb = nb - 4096;
	if ((nb - 2048) >= 0)
		nb = nb - 2048;
	if ((nb - 1024) >= 0)
		nb = nb - 1024;
	if ((nb - 512) >= 0)
		nb = nb - 512;
	return (nb);
}

char				ft_lsistype(int c)
{
	if (S_ISDIR(c))
		return ('d');
	if (S_ISREG(c))
		return ('-');
	if (S_ISCHR(c))
		return ('c');
	if (S_ISBLK(c))
		return ('b');
	if (S_ISFIFO(c))
		return ('p');
	if (S_ISLNK(c))
		return ('l');
	if (S_ISSOCK(c))
		return ('s');
	else
		return ('E');
}
