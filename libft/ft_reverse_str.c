/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:25:15 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/02 18:25:44 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);

char	*ft_reverse_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*reverse;

	i = 0;
	j = ft_strlen(str) - 1;
	reverse = (char *)malloc(sizeof(char) * j + 1);
	while (i < ft_strlen(str))
	{
		reverse[i] = str[j];
		i++;
		j--;
	}
	reverse[i] = '\0';
	str = ft_strcpy(str, reverse);
	free(reverse);
	return (str);
}
