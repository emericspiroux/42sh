/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:19:49 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 11:28:29 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

void	*ft_memalloc(size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * n);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, n);
	return (s);
}
