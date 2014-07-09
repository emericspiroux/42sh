/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:44:59 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/22 16:20:39 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_putnbr(int n)
{
	long	div;
	int		index;
	long	nb;

	nb = (long)n;
	index = 0;
	div = 1;
	if (nb < 0)
	{
		index = ft_putchar('-');
		nb = nb * - 1;
	}
	while ((nb / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((nb / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
