/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:44:59 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/22 17:23:17 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_putlnbr(long n)
{
	long	div;
	int		index;

	index = 0;
	div = 1;
	if (n < 0)
	{
		index = ft_putchar('-');
		n = n * - 1;
	}
	while ((n / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((n / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
