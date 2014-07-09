/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:07:59 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/17 20:20:02 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = NULL;
	if (s)
	{
		new = (char *)malloc(sizeof(char) * (len + 1));
		while (len != 0 && s[start] != '\0')
		{
			new[i] = s[start];
			start++;
			i++;
			len--;
		}
		new[i] = '\0';
	}
	return (new);
}
