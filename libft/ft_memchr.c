/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:41:15 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/09 13:19:00 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*s1;
	unsigned int	index;

	index = 0;
	s1 = (char *)s;
	while (s1[index] != '\0' && index < n)
	{
		if (s1[index] == (char)c)
			return (s1 + index);
		index++;
	}
	return (NULL);
}
