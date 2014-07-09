/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:13:22 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 11:38:09 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_fd(const char *s, int fd);
char	*ft_itoa(int nb);

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}
