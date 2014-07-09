/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:48:34 by rduclos           #+#    #+#             */
/*   Updated: 2014/02/12 20:05:18 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(s1);
	dup = (char*)malloc(sizeof(char) * len + 1);
	if (dup != NULL)
	{
		while (s1 && s1[index] != '\0')
		{
			dup[index] = s1[index];
			index++;
		}
		dup[index] = '\0';
	}
	return (dup);
}
