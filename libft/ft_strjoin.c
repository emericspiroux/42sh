/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:33:10 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/11 12:58:09 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strjoin(const char *s1, const char *s2)
{
	char		*str;
	size_t		i;

	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strlcat(str, s2, i + 1);
	return (str);
}
