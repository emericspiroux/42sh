/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:00:30 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 14:00:58 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *s);

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	int				len;

	index = 0;
	len = ft_strlen(s1);
	while (index < n && s2[index] != '\0')
	{
		s1[len] = s2[index];
		len++;
		index++;
	}
	s1[len] = '\0';
	return (s1);
}
